# Task: Еконт (Medium) - [HackerRank](<https://www.hackerrank.com/contests/test6sda-renfuvidbviw/challenges/challenge-2326>)


### Statement:

Куриерска фирма Еконт иска да оптимизира доставките си от офис до офис. За целта и трябва да и се направи приложение, с което да може да изчислява от дадено офис какви са оптималните пътища до другите офиси.


### Input format

Първият ред на стандартния вход са дадени две цели числа - N, M , съответно броят на офисите и броят на пътищата между тях.

На следващите m реда са описани пътища с по три цели положителни числа:  u, v, w - описва автомобилен двупосочен път от офис u до офис v, което има разстояние w. (0 &lt;= u, v &lt; N)

На последния ред е дадено s - номерът на офиса от който търсим минималните пътища.


### Constraints

1 &lt;= N, M, &lt;= 2 * 10^5
тегла на ребрата до 10^5

### Output format

На единствения ред от стандартния изход отпечатайте N числа. i-тото число показва дължината на минималния път от s до връх i. След всяко число има интервал. 

Ако връх е недостижим изведете -1


### Samples


#### Sample Input 0
```
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1
```

#### Sample Output 0
```
24 3 15
```
