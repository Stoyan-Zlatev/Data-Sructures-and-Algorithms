# Task: Test3_zad1 (Medium) - [HackerRank](<https://www.hackerrank.com/contests/sdatest3/challenges/test3-zad1/problem>)


### Statement:

Реализирайте едносвързан списък, който има следните операции:


### Input format

всеки тест започва с число N показващо броя на тестващите редици с операции. След това ще се подадат К на брой операции, като първо се подава числото К и след това всяка една операция. Всяка операция е на нов ред, като първо е името на операцията, а след това ако операцията има параметри те се подават с разделител интервал


### Constraints

ще бъдат подадени максимум 1 милион операции.

### Output format

Изхода е спрямо указанията по-горе, като изхода от всяка тестова редица от операции се извежда на нов ред. При изкарването на резултатите не принтирайте никакви символи(интервали,табулации или нещо друго), които на са в указанието.

Тестовете покриват всяка една функция и може да си тествате функционалността по време на писане като ги стартирате.


### Samples


#### Sample Input 0
```
4
4
add 1 0
add 2 1
add 3 2
print
4
add 1 0
add 2 0
add 3 0
print
4
add 1 0
add 2 1
add 3 1
print
4
add 1 2
add 2 2
add 3 2
print
```

#### Sample Output 0
$ MISSING $
$ MISSING $
$ MISSING $
$ MISSING $

#### Sample Input 1
```
6
5
add 1 0
add 2 1
add 3 2
remove 0
print
5
add 1 0
add 2 0
add 3 0
remove 1
print
5
add 1 0
add 2 1
add 3 1
remove 2
print
5
add 1 2
add 2 2
add 3 2
remove 3
print
8
add 1 2
add 2 2
remove 1
add 3 2
remove 1
add 5 2
remove 0
print
9
add 1 2
add 2 2
remove 1
remove 0
add 3 2
remove 1
add 5 2
remove 0
print
```

#### Sample Output 1
$ MISSING $
$ MISSING $
$ MISSING $
$ MISSING $
$ MISSING $
$ MISSING $

#### Sample Input 2
```
4
5
add 1 0
add 2 1
add 3 2
reverse
print
5
add 1 0
add 2 0
add 3 0
reverse
print
7
add 1 0
add 2 1
add 3 1
reverse
print
reverse
print
6
add 1 2
add 2 2
add 3 2
reverse
reverse
print
```

#### Sample Output 2
$ MISSING $
$ MISSING $
$ MISSING $
$ MISSING $

#### Sample Input 3
4
4
add 1 0
add 2 0
add 3 0
$ MISSING $
4
add 1 0
add 1 0
add 1 0
$ MISSING $
4
add 1 0
add 2 0
add 1 0
$ MISSING $
6
add 1 0
add 2 0
add 3 0
add 2 0
add 1 0
$ MISSING $

#### Sample Output 3
```
false
true
true
true
```

#### Sample Input 4
```
4
4
add 1 0
add 2 0
add 3 0
count 2
4
add 1 0
add 1 1
add 1 1
count 1
4
add 1 2
add 2 2
add 2 2
count 2
9
add 1 0
add 2 1
add 3 2
add 2 1
add 2 4
count 2
count 1
count 3
count 2
```

#### Sample Output 4
1
3
$ MISSING $
3113

#### Sample Input 5
4
5
add 1 0
add 2 0
add 3 0
$ MISSING $
print
5
add 1 0
add 1 1
add 1 1
$ MISSING $
print
5
add 1 2
add 2 2
add 2 2
$ MISSING $
print
7
add 1 0
add 2 1
add 3 2
add 2 1
add 2 4
$ MISSING $
print

#### Sample Output 5
$ MISSING $

$ MISSING $
$ MISSING $

#### Sample Input 6
```
4
5
add 1 0
add 2 0
add 3 0
group 0 0
print
5
add 1 0
add 2 0
add 3 0
group 0 1
print
5
add 1 0
add 2 0
add 3 0
group 0 2
print
5
add 1 0
add 2 0
add 3 0
group 0 3
print
```

#### Sample Output 6
$ MISSING $
$ MISSING $
$ MISSING $
$ MISSING $
