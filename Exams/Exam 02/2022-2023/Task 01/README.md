## Task 01: Заместване на елемент в списък (Medium) - [Hackerrank](<https://www.hackerrank.com/contests/sda-test-2022-2023-wdfgs/challenges/challenge-3729>)

## Statement:

Използвайте даденият клас SinglyLinkedList и реализирайте в него функцията void replace(int x) която замества стойността X в списъка със X на брой клетки съдържащи стойността 1. (Пример: при списък 4,5,3,8,5 и replace(3) получаваме списък 4,5,1,1,1,8,5) Ако X не се среща в списъка списъка остава непроменен.

Попълнете вашият код във темплейта по-долу където пише //TODO: write your code here!

**Input Format**

Входа на функцията е цялочислено число. Входа и изхода на програмата са за четене и тестване на по-сложни случаи и се очаква да не се променят.

**Constraints**

Функцията следва да е с линейна сложност.

**Output Format**

Функцията променя списъка и не връща резултат.

За цялата програма на стандартният изход се принтира списъка всеки път след като се промени от replace(ако няма промяна от изпълнението на функцията не се принтира)
---

**Sample Input 0**

```
4
2
add 6 0
replace 6
6
add 3 0
add 9 1
add 9 2
add 7 3
add 1 4
replace 3
4
add 5 0
add 3 1
add 2 2
replace 3
7
add 5 0
replace 10
add 6 1
replace 5
add 9 6
add 9 6
replace 1
```

**Sample Output 0**

```
1#1#1#1#1#1#
1#1#1#9#9#7#1#
5#1#1#1#2#
5#
1#1#1#1#1#6#
1#1#1#1#1#6#9#9#
```