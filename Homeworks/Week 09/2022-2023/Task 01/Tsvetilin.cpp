#include <iostream>
#include <unordered_map>
#include <set>

int main()
{
    size_t n;
    std::cin >> n;
    std::string current = "/";

    std::unordered_map<std::string, std::pair<std::string, std::set<std::string>>> directories;

    directories.insert({current, {"", {}}});

    for (size_t i = 0; i < n; i++)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "mkdir")
        {
            std::cin >> cmd;
            if (directories[current].second.count(cmd) > 0)
            {
                std::cout << "Directory already exists\n";
                continue;
            }

            directories.insert({current + cmd + "/", {current, {}}});
            directories[current].second.insert(cmd);
        }
        else if (cmd == "cd")
        {
            std::cin >> cmd;
            if (cmd == ".." && current != "/")
                current = directories[current].first;
            else if (directories[current].second.count(cmd) > 0)
                current += cmd + "/";
            else
                std::cout << "No such directory\n";
        }
        else if (cmd == "ls")
        {
            for (auto &dir : directories[current].second)
            {
                std::cout << dir << " ";
            }

            std::cout << "\n";
        }
        else if (cmd == "pwd")
        {
            std::cout << current << "\n";
        }
    }

    return 0;
}