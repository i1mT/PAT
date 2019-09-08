# 1078 Hashing (25 分)

The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be *H*(*k**e**y*)=*k**e**y*%*T**S**i**z**e* where *T**S**i**z**e* is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

### Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers: *M**S**i**z**e* (≤104) and *N* (≤*M**S**i**z**e*) which are the user-defined table size and the number of input numbers, respectively. Then *N* distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

### Sample Input:

```in
4 4
10 6 4 15
```

### Sample Output:

```out
0 1 4 -
```

### Analysis

##### 题目大意

给你一个m长的哈希表，如果m不是素数，将m设为大于m最小的素数，解决冲突的方式采用正向平方探测。然后输入n个数，输出每个数对应的哈希值。如果无法插入哈希表，输出`-`。

##### 解析

先将素数表打出来，**注意这里要将1也当作素数(因为可能会有长度为1的表)**。之后平方探测即可。无法插入哈希表的判断方式为：

​	当数使用平方探测从0-m均无法找到位置，那么这个数无法插入。





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

#define maxn 15112

using namespace std;

int m, n;

int prime[maxn], table[maxn];


void getPrime () {
	fill(prime, prime+maxn, 1);
	prime[1] = 0; // 注意这里可能是只有一个元素的hash表 
	for(int i = 2; i <= maxn; i++) {
		if (prime[i]) {
			for(int j = i*i; j < maxn && i < sqrt(double(maxn)); j+=i) {
				prime[j] = 0;
			}
		}
	}
}

int h(int k) {
	int pos = k%m, p;
	int cnt = 1;
	p = pos;

	while(table[p] != 0 && cnt <= m) {
		p = (k + cnt*cnt) % m;
		cnt++;
	}

	if(table[p] == 0) {
		table[p] = k;
		return p;
	}

	return -1;
}

int main () {
	int tmp, res;

	getPrime();

	scanf("%d%d", &m, &n);

	// 找素数
	while(!prime[m]) m++;

	for(int i = 0; i < n; i++) {
 		scanf("%d", &tmp);
		res = h(tmp);

		if(i != 0) printf(" ");

		if (res < 0) printf("-");
		else printf("%d", res);
	}


	return 0;
}
```



