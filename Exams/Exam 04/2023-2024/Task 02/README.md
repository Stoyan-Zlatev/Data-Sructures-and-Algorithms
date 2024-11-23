# Търчаща медиана (Medium) - [HackerRank](<https://www.hackerrank.com/contests/sda-20232024-test-4/challenges/challenge-4442>)


### Statement:

Дадени са ви N елемента, които се добавят последователно в масив. От вас се иска да принтирате медианата на масива след всяко добавяне. 

Медианата на един масив е:

* Средният по големина елемент, ако масивът съдържа нечетен брой елементи.

* Средното аритметично на двата средни по големина елементи, ако масивът съдържа четен брой елементи

Пример: 

Медианата на $[5,2,1,5]$ e $3.5$

Медианата на $[3,1,2]$ e $2$


### Input format

На първия ред се $N$. На следващите $N$ реда се въведжат числата от масива.     


### Constraints

$1 \le N \le 5*10^6$

Елементите на масива не надвишават $10^9$

### Output format

На $N$ реда са принтирани медианите след всяко добавяне в масива.


### Samples


#### Sample Input 0
```
10
1
2
3
4
5
6
7
8
9
10
```

#### Sample Output 0
```
1.0
1.5
2.0
2.5
3.0
3.5
4.0
4.5
5.0
5.5
```

#### Sample Input 1
```
4
3
11
4
2
```

#### Sample Output 1
```
3.0
7.0
4.0
3.5
```