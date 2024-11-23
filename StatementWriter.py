import os
import sys
import time
import re

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.common.exceptions import NoSuchElementException, TimeoutException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.firefox.service import Service as FirefoxService


class StatementWriter:

    def __init__(self, browser, username, password):
        if browser == "F":
            options = webdriver.FirefoxOptions()
            options.add_argument("--headless")
            options.add_argument("--log-level=3")
            service = FirefoxService(log_output=os.path.devnull)
            self._driver = webdriver.Firefox(options=options,service=service)

        elif browser == "C":
            options = webdriver.ChromeOptions()
            options.add_experimental_option(
                'excludeSwitches', ['enable-logging'])
            options.add_argument("--log-level=3")
            self._driver = webdriver.Chrome(options=options)

        else:
            print("Invalid browser. Closing...")
            exit()

        self._login(username, password)
        time.sleep(5)
        if self._driver.current_url != "https://www.hackerrank.com/dashboard":
            print(
                "There was some error while logging in. Please, check your credentials.")
            exit()

    def _find_element_secure(self, by, selector, timeout=30):
        try:
            return WebDriverWait(self._driver, timeout).until(EC.presence_of_element_located((by, selector)))
        except TimeoutException:
            print("There was some error while finding the element.")
            print(sys.exc_info()[0])
            exit()

    def _login(self, email, password):
        try:
            self._driver.get("https://www.hackerrank.com/auth/login")
            
            # New login screen
            self._find_element_secure(By.CSS_SELECTOR,"input[name='username']").send_keys(email)
            self._find_element_secure(By.CSS_SELECTOR,"input[name='password']").send_keys(password)
            self._find_element_secure(By.CSS_SELECTOR,"button[type='submit']").click()
            
            # Old login screen
            #self._find_element_secure(By.LINK_TEXT, "Log in").click()
            #self._find_element_secure(By.ID, "input-1").send_keys(email)
            #self._find_element_secure(By.ID, "input-2").send_keys(password)
            #self._find_element_secure(
            #    By.CSS_SELECTOR, '#tab-1-content-1 > div.login-form.auth-form.theme-m > form > div.form-item.clearfix > button').click()
        
        except Exception:
            print("There was some error while logging in.")
            print(sys.exc_info()[0])
            exit()

    def _get_content(self, selector, strict=False):
        web_elements_list = self._driver.find_elements(
            By.CSS_SELECTOR, selector)
        result = ""
        for element in web_elements_list:
            raw_element = element.get_attribute('innerHTML')
            raw_element = re.sub(r'<pre.*?>', r'```\n', raw_element)

            if not strict:
                result += re.sub(r'<span.*?>.*?</span>',
                                 '$MISSING$', raw_element) + "\n"
                result = re.sub(r'\n', r'\n\n', result)
                continue

            clean_empty = re.sub(r'<span.*?></span>', '', raw_element)
            clean_span = re.sub(
                r'<span.*?>([a-zA-Z0-9 ]*?)</span>', r'\1', clean_empty)
            replaced_span = re.sub(r'<span.*?>.*?</span>',
                                   '$ MISSING $', clean_span)
            result += replaced_span + "\n"
            result = re.sub(r'<strong>(.*?)</strong>', r'\n#### \1', result)

        result = re.sub(r'<br>', r'\n', result)
        result = re.sub(r'<strong>(.*?)</strong>', r'**\1**', result)
        result = re.sub(r'<em>(.*?)</em>', r'*\1*', result)
        result = re.sub(r'<code>(.*?)</code>', r'```\1```', result)
        prev_repl = "#"
        while prev_repl != result:
            prev_repl = result
            result = re.sub(
                r'(#### Sample (Input|Output) [0-9]+)\n([a-zA-Z0-9 \n]*)(#### ((Sample (Input|Output) [0-9]+)|(Explanation [0-9]+)|$))', r'\1\n```\n\3\n```\n\4', result)
        result = re.sub(r'([\n]+)```', r'\n```', result)
        result = re.sub(r'(\n\n[\n]*)', r'\n\n', result)
        result = re.sub(r'```\n####', r'```\n\n####', result)
        result = re.sub(
            r'(#### Sample (Input|Output) [0-9]+)\n([a-zA-Z0-9 \n]*?)$', r'\1\n```\n\3```\n', result)

        return result

    def __del__(self):
        self._driver.quit()

    def create_task_folder(self, url, save_path):

        contest = url
        if re.match(r'^https?://(www\.)?hackerrank.com/contests/(.*?)/challenges/?$', url):
            contest = re.sub(r'https://(www\.)?hackerrank.com/contests/(.*?)/challenges.*',
                         r'https://www.hackerrank.com/\2', url)
            
        print("Opened contest!")
        self._driver.get(contest)

        time.sleep(1)
        # Sign up for the contest
        try:
            self._driver.find_element(
                By.XPATH, '//*[@id="contest_page"]/div[2]/div/div/button').click()
            print("Signed up for the contest!")
        except NoSuchElementException:
            print("You have already signed up for the contest.")

        time.sleep(5)

        challenges_raw = self._driver.find_elements(
            By.CSS_SELECTOR, '#contest-challenges-problem')

        challenges = []
        for challenge in challenges_raw:
            heading_raw = challenge.find_element(
                By.CSS_SELECTOR, '#contest-challenges-problem > div > header > div > h4 > a')
            heading = heading_raw.get_attribute('textContent')
            link = heading_raw.get_attribute('href')
            challenge_diff = challenge.find_element(
                By.CSS_SELECTOR, '#contest-challenges-problem > footer > div > span:nth-child(3)').get_attribute('textContent')
            challenges.append((heading, link, challenge_diff))

        with open(save_path, "w", encoding='utf-8') as f:
            print(f"# NNNNNNN - [Contest](<{url}>)\n", file=f)
            print(f"---\n", file=f)
            print(f"# Tasks\n", file=f)
            for i in range(0, len(challenges)):
                print(
                    f"## Task {i+1}. {challenges[i][0].strip()} ({challenges[i][2].strip()}) - [HackerRank](<{challenges[i][1].strip()}>)\n", file=f)

        if input("Continue with creating the folder structure with task statements? (y/n): ").strip().lower() != "y":
            print("Ok. Moving on with another task...")
            return

        print("Ok. Creating the folder structure...")
        for i in range(0, len(challenges)):
            task_path = os.path.join(os.path.dirname(
                save_path), f"Task {(i+1):02d}")
            if not os.path.exists(task_path):
                os.makedirs(task_path)
            self.get_task_statement(
                challenges[i][1], os.path.join(task_path, "README.md"))
            print(f"Done with task {i+1}.  ({challenges[i][0].strip()})")

    def get_task_statement(self, url, save_path):

        # Open Task
        self._driver.get(url)
        print("Opened task!")

        # Get task info
        heading = self._find_element_secure(
            By.CSS_SELECTOR, '#content > div > div > div > div:nth-child(1) > div > div > h2').get_attribute('textContent')
        difficulty = self._find_element_secure(
            By.CSS_SELECTOR, '#content > div > div > section > div > div.challenge-body-elements-problem.challenge-container-element > div.challenge-content > div > div > aside > div > div.sidebar_problem_difficulty > div:nth-child(4) > p.sidebar_att').get_attribute('textContent')

        task_statement = self._get_content(
            '#content > div > div > section > div > div.challenge-body-elements-problem.challenge-container-element > div.challenge-content > div > div > div > div > div.challenge_problem_statement > div > div > p')
        task_input = self._get_content(
            '#content > div > div > section > div > div.challenge-body-elements-problem.challenge-container-element > div.challenge-content > div > div > div > div > div.challenge_input_format > div.msB.challenge_input_format_body > div > p')
        task_output = self._get_content(
            '#content > div > div > section > div > div.challenge-body-elements-problem.challenge-container-element > div.challenge-content > div > div > div > div > div.challenge_output_format > div.msB.challenge_output_format_body > div > p')
        task_samples = self._get_content(
            '#content > div > div > section > div > div.challenge-body-elements-problem.challenge-container-element > div.challenge-content > div > div > div > div > div:nth-child(n+5) > div :is( div > p , div > div > pre)', True)

        task_constraints = self._get_content(
            '#content > div > div > section > div > div.challenge-body-elements-problem.challenge-container-element > div.challenge-content > div > div > div > div > div.challenge_constraints > div.msB.challenge_constraints_body > div > p', True)

        # Save to file
        with open(save_path, "w", encoding='utf-8') as f:
            print(
                f"# Task: {heading.strip()} ({difficulty.strip()}) - [HackerRank](<{url}>)\n\n", file=f)
            print(f"### Statement:\n\n{task_statement}", file=f)
            print(f"### Input format\n\n{task_input}", file=f)
            print(f"### Constraints\n\n{task_constraints}", file=f)
            print(f"### Output format\n\n{task_output}", file=f)

            if not task_samples.isspace() and not task_samples == "":
                print(f"### Samples\n\n{task_samples.rstrip()}", file=f)

    def _scan_tree(self, path):
        for entry in os.scandir(path):
            if entry.is_dir(follow_symlinks=False):
                yield from self._scan_tree(entry.path)
            else:
                yield entry

    def get_readme_list(self, root_dir):
        readmes = [f.path for f in self._scan_tree(root_dir) if f.is_file()
                   and f.name.strip().upper() == "README.MD"]
        result = []
        for readme in readmes:
            with open(readme, "r", encoding="utf-8") as f:
                content = f.read().strip()
                if re.match(r'^https?://(www\.)?hackerrank.com/contests/(.*?)/challenges/(\S)+$', content):
                    result.append(("task", readme, content.strip()))
                if (re.match(r'^https?://(www\.)?hackerrank.com/(\S)+$', content) and re.match(r'^https?://(www\.)?hackerrank.com/[^/]+/?$', content) ) or re.match(r'^https?://(www\.)?hackerrank.com/contests/(.*?)/challenges/?$', content):
                    result.append(("contest", readme, content.strip()))
        return result


### MAIN ###

browser = ""
while browser not in ["C", "F"]:
    browser = input("Please choose a browser to use for the script:\n F: Firefox (recommended)\n C: Chrome (not recommended due to hackerranks's specifics and lack of headless mode)\nPlease choose (F/C):").strip().upper()


print("\n\nPlease, enter your hackerrank credentials:")
writer = StatementWriter(browser, input("Email/Username: "), input("Password: "))

readme_list = writer.get_readme_list(os.getcwd())

print("\n")

if len(readme_list) == 0:
    print("No readme files found. Closing...")
    del writer
    exit()

for readme in readme_list:
    if readme[0] == "contest":
        print(f" Contest link found @ {readme[1]} -> {readme[2]}\n")
        if input("Approve contest statement extraction? (y/n): ").strip().lower() != "y":
            print("Ok. Moving on with another task...\n\n")
            continue
        writer.create_task_folder(readme[2], readme[1])
        print("Done! Going on...\n\n")
        continue

    elif readme[0] == "task":
        print(f" Task link found @ {readme[1]} -> {readme[2]}\n")
        if input("Approve task statement extraction? (y/n): ").strip().lower() != "y":
            print("Ok. Moving on with another task...\n\n")
            continue
        writer.get_task_statement(readme[2], readme[1])
        print("Done! Going on...\n\n")
        continue

print("I'm done. Closing...\n\n")
del writer