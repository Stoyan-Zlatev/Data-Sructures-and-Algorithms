# Task: Цикличен граф (Medium) - [HackerRank](<https://www.hackerrank.com/contests/sda-exam-27-01-19-/challenges/-1-12>)


### Statement:

Даден е насочен граф с тегла по ребрата. Да се напише функция, която проверява дали има цикъл в графа.


### Input format

N - брой тестове

следват N на брой тестове всеки от които включва:

V E - брой върхове и брой ребра

xi yi wi - ребро между връх xi и връх yi с тегло wi


### Constraints

1 &lt; N &lt; 20
1&lt; V &lt; 1000

### Output format

за всеки граф ако има цикъл се принтира true иначе falsе, резултатите се разделят с интервал.


### Samples


#### Sample Input 0
```
2
3 5
3 1 4
2 3 4
3 2 2
1 3 2
2 1 1
3 5
1 3 1
1 2 4
2 3 3
3 1 3
3 2 4
```

#### Sample Output 0
```
true true 
```
