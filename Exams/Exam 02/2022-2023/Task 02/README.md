## Task 02: Заместване на елемент в списък - вариант 2 (Medium) - [Hackerrank](<https://www.hackerrank.com/contests/sda-test-2022-2023-wdfgs/challenges/challenge-3730>)

## Statement:

Използвайте даденият клас SinglyLinkedList и реализирайте в него функцията void replace(int x) която прави следното:

Намира стойността Y която е на позиция X в списъка
Обикаляйки последователно по списъка замества всяка стойност Y със стойността на следващият елемент в списъка.
Пример: при списък 4,5,3,8,3,5 и replace(2) получаваме списък 4,5,8,8,5,5 понеже в оригиналният списък на позиция 2 имаме числото 3 (позициите ги броим започвайки от 0). След това обикаляйки последователно по списъка заместваме първото срещане на 3 със следващият елемент(8), а второто срещане на 3 със следващият елемент(5).

Ако X e извън списъка - не се прави нищо. Ако числото което трябва да заместим със следваща стойност е последното в списъка не правим нищо.

Попълнете вашият код във темплейта по-долу където пише //TODO: write your code here!

**Input Format**

Входа на функцията е цялочислено число. Входа и изхода на програмата са за четене и тестване на по-сложни случаи и се очаква да не се променят.

**Constraints**

Функцията следва да е с линейна сложност.

**Output Format**

Функцията променя списъка и не връща резултат.

---

**Sample Input 0**

```
4
3
add 6 0
add 10 1
replace 0
7
add 3 0
add 1 1
add 9 2
add 7 3
add 9 4
add 6 5
replace 2
4
add 4 0
add 3 1
replace 0
add 4 2
3
add 5 1
add 9 3
replace 1
```

**Sample Output 0**

```
10#10#
3#1#7#7#6#6#
3#3#
5#9#
```