# Task 3. CEO на стартъп (Hard) - [HackerRank](<https://www.hackerrank.com/contests/sda-hw-3-2022/challenges/challenge-3670>)

## Statement:

Годината е 2032. Стартъпът, за който си мечтаете, е вече реалност. Той надминава и най-смелите ви очаквания. Поради експоненциалния растеж на компанията вече имате твърде много девелъпъри и разпределението по екипи е лошо. Вие имате специални умения и знаете всеки един от вашите девелъпъри какви умения има и може да ги оцените с едно цяло число $s_i$. Вашата цел е да постигнете баланс в компанията, като за целта искате да разделите девелъпърите на $T$ на брой екипа и максималният сбор на уменията на членовете на всеки екип да бъде минимизиран. Понеже обаче сте твърде заети, нямате време да пробвате всички комбинации, затова нареждате девелъпърите в една редица и всеки един екип трябва да бъде част от редицата без да има прекъсване между членовете на екипа.

При дадена редица от девелъпъри и $T$ - брой на екипите, на които ще ги разделяте, минимизирайте максималния сбор на уменията във всеки екип.


**Input Format**

От първия ред се въвеждат $N$ и $T$ - броя девелъпъри и броя екипи, на които да ги разделите.

От следващия ред се въвеждат $N$ числа $s_i$ - уменията на девелъпърите.

**Constraints**

$1 \le N \le 10^5$

$1 \le s_i \le 10^5$

$1 \le T \le \min(\dfrac{N}{2},100)$

**Output Format**

Изведете 1 число, най-малката възможна стойност за най-голямата стойност на сбора на уменията на девелъпърите във всеки екип.

---

**Sample Input 0**

```
3 1
1 2 3
```

**Sample Output 0**

```
6
```

**Explanation 0**

Имаме 3 девелъпъри, които трябва да разделим в 1 екип, тоест имаме само една възможност, която е $[1,2,3]$ със сбор $6$.

---

**Sample Input 1**

```
4 2
1 2 3 7
```

**Sample Output 1**

```
7
```

**Explanation 1**

Тъй като имаме 7-ца най-доброто разпределение ще бъде $[1,2,3]$ и $[7]$ $\Rightarrow$ отговорът ще бъде $7$