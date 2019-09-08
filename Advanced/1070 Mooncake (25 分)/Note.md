# 1070 Mooncake (25 分)

Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.

Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers *N* (≤1000), the number of different kinds of mooncakes, and *D* (≤500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of *N*kinds of mooncakes. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

### Sample Input:

```in
3 200
180 150 100
7.5 7.2 4.5
```

### Sample Output:

```out
9.45
```

### Analysis

##### 题目大意

给你n个仓库的储藏信息，要你求满足需求量为d的最大收入。

每个仓库信息包含：总库存量与总价格。

##### 解析

计算量单价，按单价排序价高的先卖。

注意：用double，float精度不够

注意：有所有仓库加起来的库存都满足不了需求的可能。

### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

struct Good {
	double stock;
	double price;
	double rate;
};

vector<Good> list;

bool cmp (Good a, Good b) {
	return a.rate > b.rate;
}

int main () {

	int n;
	double d;
	scanf("%d%lf", &n, &d);

	list.resize(n);

	for(int i = 0; i < n; i++) {
		scanf("%lf", &list[i].stock);
	}
	for(int i = 0; i < n; i++) {
		scanf("%lf", &list[i].price);
		list[i].rate = list[i].price / list[i].stock;
	}

	sort(list.begin(), list.end(), cmp);

	double res = 0;
	int lidx = 0;

	while(d > 0 && lidx < n) {
		if (list[lidx].stock >= d) {
			res += d * list[lidx].rate;
			d -= list[lidx].stock;
		} else {
			res += list[lidx].price;
			d -= list[lidx].stock;

			lidx++;
		}
	}

	printf("%.2f", res);
	
	return 0;
}
```

