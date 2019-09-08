# 1059 Prime Factors (25 分)

Given any positive integer *N*, you are supposed to find all of its prime factors, and write them in the format *N* = *p*1*k*1×*p*2*k*2×⋯×*p**m**k**m*.

### Input Specification:

Each input file contains one test case which gives a positive integer *N* in the range of **long int**.

### Output Specification:

Factor *N* in the format *N* `=` *p*1`^`*k*1`*`*p*2`^`*k*2`*`…`*`*p**m*`^`*k**m*, where *p**i*'s are prime factors of *N* in increasing order, and the exponent *k**i* is the number of *p**i* -- hence when there is only one *p**i*, *k**i* is 1 and must **NOT** be printed out.

### Sample Input:

```in
97532468
```

### Sample Output:

```out
97532468=2^2*11*17*101*1291
```

### Analysis

##### 题目大意

给你一个long int 的数，求这个数的质因数。相同的质因数乘积用指数表示。如果一个质数的指数为1，则省略。



##### 解法

> 学习了 [柳婼](https://www.liuchuo.net/) 的解法: [1059. Prime Factors (25)-PAT甲级真题（素数表的建立）](<https://www.liuchuo.net/archives/2289>)
>
> 
>
> 这里用到了一种简单易记的素数表的求法，先写下来：
>
> ```
> // 求10000以内的素数
> vector<int> prime(10000, 1);
> for (int i = 2; i*i < 10000; i++)
> 	for (int j = 2; j*i < 10000; j++)
> 		prime[i*j] = 0;
> ```
>
> 

边计算边输出，看代码即可理解。



### Code

```
#include <iostream>
#include <strstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAX 500000

vector<int> prime(MAX, 1);

int main () {
	long int a;

	// 求素数表
	for(int i = 2; i * i < MAX; i++) {
		for(int j = 2; i * j < MAX; j++)
			prime[i*j] = 0;
	}

	scanf("%ld", &a);
	printf("%ld=", a);
	if(a == 1) printf("1");
	int cnt, flag, state = 0;
	for (int i = 2; a >= 2; i++) {
		cnt = 0;
		flag = 0;
		while(prime[i] == 1 && a%i == 0) {
			// a is prime facter
			cnt++;
			a = a/i;
			flag = 1;
		}

		if (flag == 1) {
			if (state) printf("*");
			printf("%d", i);
			state = 1;
		}
		if(cnt >= 2) {
			printf("^%d", cnt);
		}
	}
	
	return 0;
}
```

