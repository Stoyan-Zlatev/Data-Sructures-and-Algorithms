# Task: Обръщане на списък (Hard) - [HackerRank](<https://www.hackerrank.com/contests/exam-2020-02-06-sda/challenges/challenge-2853>)


### Statement:

Напишете функция reverse(n,m) за свързан списък, която обръща в списъка последователността от n-тото до m-тото число на списъка. Например за списък с числа 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; 6 -&gt; 7, когато се извика reverse(2,5) получаваме 1 -&gt; 5 -&gt; 4 -&gt; 3 -&gt; 2 -&gt; 6 -&gt; 7, ако n e по-голямо от размера на списъка, не се обръща нищо, ако m  е по-голямо от дължината на списъка, то се обръща списъка от n до края. 


### Input format

Форматът на входа можете да видите в примерния вход. Не е нужно да реализирате нищо, свързано с него, тъй като за това е предоставен шаблон. От вас се иска да реализирате методът reverse(int n, int m) на структурата List


### Constraints

0 &lt; n &lt; m &lt; 100000

### Output format

Самата функция не връща резултат, но списъка следва да е правилно променен, така че да минават тестовете на задачата.


### Samples


#### Sample Input 0
```
15
add 1
add 2
add 3
add 4
add 5
add 6
add 7
add 8
add 9
reverse 3 5
print
add 10
add 11
reverse 8 11
print
```

#### Sample Output 0
```
1 2 5 4 3 6 7 8 9
1 2 5 4 3 6 7 11 10 9 8
```
