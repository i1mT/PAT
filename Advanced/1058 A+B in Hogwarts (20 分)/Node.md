# 1058 A+B in Hogwarts (20 分)

If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute *A*+*B*where *A* and *B* are given in the standard form of `Galleon.Sickle.Knut` (`Galleon` is an integer in [0,107], `Sickle` is an integer in [0, 17), and `Knut` is an integer in [0, 29)).

### Input Specification:

Each input file contains one test case which occupies a line with *A* and *B* in the standard form, separated by one space.

### Output Specification:

For each test case you should output the sum of *A* and *B* in one line, with the same format as the input.

### Sample Input:

```in
3.2.1 10.16.27
```

### Sample Output:

```out
14.1.28
```

### Analysis

##### 题目大意

17个Sickles算一个Galleon，29个Knuts算一个Sickle。

给出格式为Galleon.Sickle.Knut的A与B，计算A+B。

##### 解法

对应相加，商加到上一级，取余。

### Code

```
#include <iostream>
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



int main () {
	
	int g, s, k;
	int g1, g2, s1, s2, k1, k2;

	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);

	k = k1 + k2;
	s = s1 + s2 + k/29;
	g = g1 + g2 + s/17;
	k %= 29;
	s %= 17;
	
	printf("%d.%d.%d", g, s, k);

	return 0;
}
```



