## Task 01: Специфично принтиране - дърво (Medium) - [Hackerrank](<https://www.hackerrank.com/contests/sda-test3-2022-2023-rdsafgtvh/challenges/--149>)

## Statement:

Напишете програма, която да принтира всички възли в дърво, които имат точно два наследника. Подредбата за принтиране следва да е корен-ляво-дясно.

Пример:

```
          10
     5          12
  2    7     11     18
1  3              16   21
```

върхове отговарящи на условието: 10, 5, 2, 12, 18

**Input Format**

$Т$ - брой дървета които ще бъдат тествани следват $Т$ на брой последователности от $N$ и $X_1 \dots X_N$

$N$ - колко числа има в двоичното наредено дърво

$X_1 \dots  X_N$ - числа които се вкарват последователно в двоично наредено дърво.

**Constraints**

$1 < T < 10^3$

$3 < N < 10^5$

$0 < X_i < 10^6$

**Output Format**

Стойностите на възлите които имат по два наследника разделени със интервал. Ако няма такива възли принтирайте просто празен ред.

---

**Sample Input 0**

```
4
11
10 5 12 2 7 11 18 1 3 16 21
4
1 4 2 3
6
5 6 2 3 1 4
7
4 5 2 1 6 7 3

```

**Sample Output 0**

```
10 5 2 12 18 

5 2 
4 2 
```