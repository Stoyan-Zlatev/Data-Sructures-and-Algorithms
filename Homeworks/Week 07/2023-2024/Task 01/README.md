# Медианчо (Medium) - [HackerRank](<https://www.hackerrank.com/contests/sda-hw-7-2023/challenges/challenge-4335>)


### Statement:

Имало едно време човек на име Медианчо и целият му професионален живот се състоял в едно: Да определя едно конкретно число **B** в колко нечетни по дължина подмасиви на конкретен масив се явява медиана$^1$. Медианчо обаче е бил тясно специализиран, той можел да отговаря на предния въпрос само при дадени условия:

Ако масивът му е с дължина **N**, то елементите на масива са между 1 и **N** включително и се срещат само по веднъж (Медианчо би могъл да отговори за масив [1,2,3], но не и на [1,2,2] при N = 3).

Дава ви се масив от числа, изпълняващ гореописаните условия, и Вие трябва да определите числото **B** в колко нечетни по дължина подмасиви се явява медиана$^1$.

$^1$: В задачата под "медиана" разбираме числото, което би застанало "по средата" на масив, след като го сортираме. Примерно за [1,5,3] като медиана би се явила тройката.


### Input format

Получавате две числа като вход: **N** и **B**, където **N** е големината на масива.

Следват **N** на брой реда, които представляват съдържанието му.


### Constraints

$1 \le N \le 10^5 $

$1 \le B \le N$

$1 \le arr[i] \le N$

$arr[i] = arr[j] => i=j$

### Output format

Изведете едно число, броят на нечетните по дължина подмасиви, в които **B** се явява медиана$^1$.


### Samples


#### Sample Input 0
```
5 4
1 2 3 4 5
```

#### Sample Output 0
```
2
```

#### Explanation 0
2-та подмасива с нечетна дължина, за които 4 е медиана са:
[4]
[3, 4, 5]

#### Sample Input 1
```
7 4
5 7 2 4 3 1 6
```

#### Sample Output 1
```
4
```

#### Explanation 1
4-те подмасива с нечетна дължина, за които 4 е медиана са:
[4]
[7, 2, 4]
[5, 7, 2, 4, 3]
[5, 7, 2, 4, 3, 1, 6]
