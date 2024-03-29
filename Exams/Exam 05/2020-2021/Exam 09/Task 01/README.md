# Task: Съществува ли конкретен път в граф? (Medium) - [HackerRank](<https://www.hackerrank.com/contests/sda-2020-2021-test9-wefnkcsdw/challenges/challenge-2763/problem>)


### Statement:

Напишете програма, която да проверява дали съществува конкретен път по зададен граф. Пътя се подава като множество от последователни върхове за обхождане в графа.


### Input format

М - брой върхове в графа(градовете са номерирани последователно от 0 до М-1)

Следват М реда по-един за всеки град на които първо се подава Ni - брой върхове свързани с М, а след това Ni на брой числа показващи градовете свързани с конкретният град. Ако град не е свързан с никой друг град то Ni ще е равно на 0 и след това няма да има други числа. (Графа е ненасочен, за това ако е указано че има път от един x до град y, то има път и от y до x)

Q - число показващо колко пътя ще бъдат обработени

Следват Q на брой реда като първо се подава дължината на пътя Lj, а след това има Lj на брой числа които показват градове през които минава пътя


### Constraints

1 &lt;= M  &lt;= 1000
0 &lt;= Ni &lt;= M-1
1 &lt;= Q  &lt;= 10000
1 &lt;= Lj &lt;= M

### Output format

поредица от Q нули и единици, като изведете 1 ако има път и 0 ако няма за всяка една от Q-те заявки


### Samples


#### Sample Input 0
```
5
3 0 3 4 
5 4 0 3 1 2 
5 4 3 1 0 2 
4 4 2 1 3 
4 4 0 2 3 
3
5 3 1 2 4 0 
3 3 1 4 
4 3 4 1 2 
```

#### Sample Output 0
```
1 1 1 
```
