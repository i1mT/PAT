# 1081 Rational Sum (20 分)

Given *N* rational numbers in the form `numerator/denominator`, you are supposed to calculate their sum.

### Input Specification:

Each input file contains one test case. Each case starts with a positive integer *N* (≤100), followed in the next line *N* rational numbers `a1/b1 a2/b2 ...` where all the numerators and denominators are in the range of **long int**. If there is a negative number, then the sign must appear in front of the numerator.

### Output Specification:

For each test case, output the sum in the simplest form `integer numerator/denominator` where `integer` is the integer part of the sum, `numerator` < `denominator`, and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

### Sample Input 1:

```in
5
2/5 4/15 1/30 -2/60 8/3
```

### Sample Output 1:

```out
3 1/3
```

### Sample Input 2:

```in
2
4/3 2/3
```

### Sample Output 2:

```out
2
```

### Sample Input 3:

```in
3
1/3 -1/6 1/8
```

### Sample Output 3:

```out
7/24
```

### Analysis

##### 题目大意

给你n个分数，求这些分数之和，分子与分母在`long int`范围内。若分子比分母大，要输出带分数，否则输出真分数。若分数值为整数，要只输出整数。

##### 解析

首先分数相加需要求最小公倍数，分数约分要求最大公因数。所以先写一个gcd函数，然后写一个add分数加法。之后就与A+B相同了。在最后输出的时候分情况讨论下，不要忘记分数之和正好为0的情况。



### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <sstream>


using namespace std;

int n, nume = 0, deno = 0, intiger = 0, t1, t2;

int gcd(int a, int b) {
	if (b == 0) return a;

	return gcd(b, a%b);
}

int minMul (int a, int b) {
	return a/gcd(a, b)*b;
}

void reduct (int &num, int &den) {
	int maxn = gcd(num, den);

	num /= maxn, den /= maxn;
}

void add (int &a1, int &b1, int &a2, int &b2) {

	if(b1 == 0) {
		nume = a2, deno = b2;
		return;
	}

	reduct(a1, b1);
	reduct(a2, b2);

	int mul = minMul(b1, b2);
	int c1 = mul/b1, c2 = mul/b2;

	a1 *= c1, a2 *= c2;

	b1 = mul, b2 = mul;

	a1 += a2;

	reduct(a1, b1);
}


int main () {
	
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d/%d", &t1, &t2);

		add(nume, deno, t1, t2);
	}

	intiger = nume/deno;
	if (intiger) {
		printf("%d", intiger);
		nume -= deno*intiger;
	}

	reduct(nume, deno);

	if (intiger && nume != 0)
		printf(" ");

	if (nume != 0)
		printf("%d/%d", nume, deno);

	if (intiger == 0 && nume == 0) {
		printf("0");
	}

	return 0;
}
```

