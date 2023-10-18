# Task: BST Insert & Inorder traversal (Medium) - [HackerRank](<https://www.hackerrank.com/contests/algorithms-implementation-test-environment/challenges/bst-insert/problem>)


### Statement:

Реализирайте двоично дърво за търсене и обхождане в дълбочина. Необходимо е да реализирате само методите за добавяне на елемент и inorder обхождане.


### Input format

$n$ - Брой на инструкциите

След това на $n$ нови реда ще получите $n$ инструкции. Инструкциите биват 2 вида:

```add X``` - добавяне на числото X към двоичното дърво. Ако X вече съществува в дървото, не правим нищо.
```inorder``` - обхождане на дървото inorder и извеждане на елементите с " " (пауза) между тях

### Constraints

$0 \le n \le 500,000$, но дървото е рандомизирано.

$-10^9 \le X \le 10^9$

### Output format

При инструкция ```add X``` не се извежда нищо.

При инструкция ```inorder``` се извеждат стойностите на елементите на дървото в нарастващ ред, разделени с " " (пауза). Накрая се извежда нов ред ```\n```.


### Samples


#### Sample Input 0
```
5
add 1
add 2
add 5
add 0
inorder
```

#### Sample Output 0
```
0 1 2 5 
```

#### Explanation 0
При обхождане на елементите от най-малък към най-голям получаваме ```0 1 2 5 \n```.
<img src="https://s3.amazonaws.com/hr-assets/0/1596749482-2373c76c7d-Screenshot_20200807_003104.png" alt="image" title="">

#### Sample Input 1
```
5
add 1
inorder
add 3
add 3
inorder
```

#### Sample Output 1
```
1 
1 3 
```

#### Explanation 1
След първото обхождане получаваме ```1 \n```. След второто обхождане получаваме ```1 3 \n```.
<img src="https://s3.amazonaws.com/hr-assets/0/1596749378-92ce2c69e5-Screenshot_20200807_002909.png" alt="image" title="">
