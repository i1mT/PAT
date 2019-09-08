# 1067 Sort with Swap(0, i) (25 分)

Given any permutation of the numbers {0, 1, 2,..., *N*−1}, it is easy to sort them in increasing order. But what if `Swap(0, *)` is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

```
Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
```

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first *N* nonnegative integers.

### Input Specification:

Each input file contains one test case, which gives a positive *N* (≤105) followed by a permutation sequence of {0, 1, ..., *N*−1}. All the numbers in a line are separated by a space.

### Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

### Sample Input:

```in
10
3 5 7 2 6 4 9 0 8 1
```

### Sample Output:

```out
9
```

### Analysis

##### 题目大意

给你一个排列，使用swap(0, *)将排列有序。问最少需要执行多少次swap？

##### 解析

一个能想到的办法就是，对于一个位置i，其上数字为u，i!=u说明u没有归位，那么先用0所在位置与位置u上的数字交换，然后再用0所在位置的数与i交换，u归位。如图所示：

![正常归位](http://upy.iimt.me/微信截图_20190822212526.png)



但是这样会多一步先用0占领要归位数字的位置，如果0所在位置正好与该位置上应有数字所在的位置互换，即可一步就将数字归位。例如：`a[5] = 0` ，该位置本应为5，而`a[7]=5` ,那么`swap(a[5], a[7])` 即可将5归位。之后再继续归位7即可，这样可以一直持续到0也归位。

自己列一个表格，然后来按照如上策略交换，会发现，是一个0开头0结尾的闭环。如图：

![闭环示意图](http://upy.iimt.me/2019/08/21/微信截图_20190822213804.png)

写出这个闭环：`0-1-3-4-0` (注意这里将0当作同一个节点)。这样的策略有个问题就是，当a[5]=0时，需要查询5所在位置(当然可以做一个指示位置的数组，也可以在O(1)内查到)。不过还有更好的办法。

它不是闭环么，那我们从任何节点出发都可以，那现在我们可以倒着来，从上方的0出发：

![](http://upy.iimt.me/2019/08/21/微信截图_20190822214304.png)

发现和刚刚是相同的，所以我们可以一直从下标0出发，走完闭环。（与从0所在位置出发走完闭环所需要的交换数是相等的）

所以最终策略是：

	1. 从位置i=1开始，如果位置i没有归位。那么就看看0有没有归位，若没有归位，一直swap(a[0], a[a[0]])，直到a[0]=0
 	2. 如果i依然没有归位，说明i没有在这个闭环中，那么我们swap(a[0], a[i])，这样就将0添加到闭环中了。然后继续第一步即可。

> 代码有参考柳神。

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
#include <list>
#include <cmath>
#include <cstring>

using namespace std;

vector<int> nums;

/*
解析:
	1. 使用nums[t]=i表示数字t占着i的位置
	2. 使i从1开始循环，如果nums[i]!=i，就交换nums[0]与nums[nums[0]]，直到nums[0]=0
	3. 如果nums[i]依然没有归位，将0与该位置的数字互换，继续循环
*/

int main () {
	int n, tmp, ans = 0;
	cin >> n;
	nums.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		nums[tmp] = i;
	}

	for(int i = 0; i < n; i++) {
		if(nums[i]!=i) {
			while(nums[0]!=0) {
				swap(nums[0], nums[nums[0]]);
				ans++;
			}

			if(nums[i]!=i) {
				swap(nums[0], nums[i]);
				ans++;
			}
		}
	}

	printf("%d", ans);

	return 0;
}
```

