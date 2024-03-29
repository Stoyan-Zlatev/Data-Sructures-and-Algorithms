# Task: Exam (Medium) - [HackerRank](<https://www.hackerrank.com/contests/sda-hw-13-2022-1/challenges/exam-7>)


### Statement:

Мими е четвърти курс и за пореден път ще се явява на изпит по ДИС, но изобщо не иска да учи. Незнайно как обаче е успяла да се сдобие със решенията на задачите които ще бъдат дадени. Тя има право на позволен пищов, но не може да рискува да напише направо решенията, тъй като може някой да забележи и да си създаде проблеми. За това Мими измисли алгоритъм за кодиране и декодиране на тази безценна инфомация. За нейна изненада се оказа че декодирането е по-сложно от колкото си мислеше.

При кодирането тя е преобразувала решенията в последователност от малки латински букви. За да възстанови първоначалния им вид, тя трябва да раздели тази последователност на части по такъв начин, че във всяка част всяка латинска буква или да се среща нечетен брой пъти, или изобщо да не се среща. Всъщност Мими се интересува от минималния брой части, на които трябва да се раздели кодираното решение. Ако и предоставите тази информация всичко останало за нея е тривиално. Вие решавате да и помогнете за да може най-накрая да си вземе предмета (а и за да изкарате някоя точка на контролното по СДА практикум).


### Input format

От единствения ред на стандартния вход се въвежда низ $S$, съставен от малки латински букви – кодираните решения. 


### Constraints

В низа $S$ има най-много 3000 символа, всички от които са малки латински букви.

### Output format

Минималния брой части, на които трябва да се раздели кодираната информация, така чевъв всяка част всяка латинска буква или да се среща нечетен брой пъти, или да не се среща изобщо.

Важно: решение винаги има, тъй като кодът може да се раздели на толкова части, колкото букви има в него и така във всяка част всяка буква ще се среща само веднъж, т.е нечетен брой пъти. 


### Samples


#### Sample Input 0
```
zxcvbnzxxccvvbbnn
```

#### Sample Output 0
```
2
```

#### Sample Input 1
```
asssffgfhfdgdgsshfghgffjfff
```

#### Sample Output 1
```
5
```
