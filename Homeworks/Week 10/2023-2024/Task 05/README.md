# Бонус: Лего от Али експрес (Medium) - [HackerRank](<https://www.hackerrank.com/contests/sda-hw-10-2023/challenges/lego-from-ali-express>)


### Statement:

По време присъствието ви на кариерния форум на ФМИ печелите томбула, в която наградата е Лего комплект. Разбира се обаче, тъй като това е ФМИ, комплектът е купен от Али експрес, струва 50 стотинки и ще пристигне по Коледа. 

Вие все пак сте много развълнувани за този пъзел и решавате да си купите друг такъв от кварталната бакалия и да си го наредите, понеже не ви се чака. 

Пъзелът се състои от градове и пътища, но тъй като е от Али експрес, имате пътища само с дължина 1 или 2. Вие го нареждате, но сега се чудите как можете най-бързо да стигнете от един град до друг. 

Сега задачата ви е да решите този проблем и да напишете програма, която намира най-краткия път между два дадени града в нареденото Лего.


### Input format

На първия ред се въвеждат $N$ и $M$

На следващите $M$ реда се дават по три числа - първите две са номерата на градовете, между които има път, a трето е дължината на пътя (1 или 2).

На последния ред се въвеждат 2 числа $startIndex$ и $endIndex$.


### Constraints

$1 \le N,M \le 10^6$

Номерата на върховете са между $0 \; и \; N-1$

$0 \le startIndex,endIndex \le 10^6$

### Output format

На един ред се извежда търсеният отговор - дължината на най-краткия път между двата $startIndex$ и $endIndex$.


### Samples


#### Sample Input 0
```
8 7
1 2 2
1 3 1
2 4 2 
3 4 1 
4 5 1 
5 6 2 
6 7 1 
1 7
```

#### Sample Output 0
```
6
```
