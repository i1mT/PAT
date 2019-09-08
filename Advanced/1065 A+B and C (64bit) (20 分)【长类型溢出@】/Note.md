# 1065 A+B and C (64bit) (20 分)

Given three integers *A*, *B* and *C* in [−263,263], you are supposed to tell whether *A*+*B*>*C*.

### Input Specification:

The first line of the input gives the positive number of test cases, *T* (≤10). Then *T* test cases follow, each consists of a single line containing three integers *A*, *B* and *C*, separated by single spaces.

### Output Specification:

For each test case, output in one line `Case #X: true` if *A*+*B*>*C*, or `Case #X: false`otherwise, where *X* is the case number (starting from 1).

### Sample Input:

```in
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
```

### Sample Output:

```out
Case #1: false
Case #2: true
Case #3: false
```

### Analysis

##### 题目大意

给你三个范围在[-2^63, 2^63]的整数a、b、c，判断a+b>c是否成立。

##### 解析

已知`long long`类型可以表示64位整数，但两数相加会溢出。需要对溢出判断一下。

	1. 一正一负一定不会溢出，所以直接判断a+b>c即可
 	2. a为正，b为正，若溢出，则a+b<0，则a+b一定大于c。因为a与b的和早已大于c的取值范围。
 	3. a为负，b为负，若溢出则a+b>=0，同理a+b一定小于c。

详见代码。

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
#include <cstring>

int main () {
	long long a, b, c, res;
	int n, flag;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		res = a+b;
		if(a>0 && b>0 && res<0) flag = 1;
		else if (a < 0 && b < 0 && res >= 0) flag = -1;
		else if (res > c) flag = 1;
		else flag = -1;
		printf("Case #%d: ", i+1);

		if(flag == 1) printf("true\n");
		else printf("false\n");
	}

	return 0;
}
```

