# Task: Специфично обхождане - дърво (Medium) - [HackerRank](<https://www.hackerrank.com/contests/sda-2020-2021-test6-dbr8t-r/challenges/traversal-level-order/problem>)


### Statement:

По дадено двоично наредено дърво, имплементирайте обхождане по нива, което обаче променя посоката на обхождане на всеки ред. 

На ниво 0 (корена), елементите се обхождат отляво надясно. На ниво 1 - отдясно наляво. На ниво 2 - отляво надясно и тн.

Методът insert() е реализиран. 

Реализирайте метода printSFB();


### Input format

На първият ред на стандартния вход се въвежда число N

На вторният ред на стадартния вход се въвеждат N цели числа - елементите от дървото.


### Constraints

$2 \le n \le 10^6 $
$0 \le a_i \le 10^8$

### Output format

На единствения ред на стандартния изход отпечатайте елементите на масива в указания ред.


### Samples


#### Sample Input 0
```
10
4 2 7 1 3 9 0 6 10 8
```

#### Sample Output 0
```
4 7 2 1 3 6 9 10 8 0
```

#### Explanation 0
Дървото изглежда така: 
```
        4
       / \
      2   7
     / \ / \
    1  3 6  9
   /       / \
  0       8   10
```
