# 1062 Talent and Virtue (25 分)

About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage（圣人）"; being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）"; being good in neither is a "fool man（愚人）"; yet a fool man is better than a "small man（小人）" who prefers talent than virtue.

Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.

### Input Specification:

Each input file contains one test case. Each case first gives 3 positive integers in a line: *N* (≤105), the total number of people to be ranked; *L* (≥60), the lower bound of the qualified grades -- that is, only the ones whose grades of talent and virtue are both not below this line will be ranked; and *H* (<100), the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades. Those with talent grades below *H* but virtue grades not are cosidered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". Those with both grades below *H*, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the *L* line are ranked after the "fool men".

Then *N* lines follow, each gives the information of a person in the format:

```
ID_Number Virtue_Grade Talent_Grade
```

where `ID_Number` is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.

### Output Specification:

The first line of output must give *M* (≤*N*), the total number of people that are actually ranked. Then *M* lines follow, each gives the information of a person in the same format as the input, according to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.

### Sample Input:

```in
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
```

### Sample Output:

```out
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
```

### Analysis

##### 题目大意

司马光将人根据talent与virtue分为4等，简写为t与v。现有一系列人的属性，排序。给定阈值L，H，若t与v都不小于L的才计入排序。排序规则如下：

	1. 若t，v均不小于L，则为圣人。
 	2. 若t小于H，而v不是，则为君子。
 	3. 若t与v均小于h，但v不小于t，则为愚人。
 	4. 剩下的都是小人。
 	5. 圣人>君子>愚人>小人
 	6. 相同等级之间，按照v与t之和降序排列。
 	7. 若v与t之和也相同，按v降序排列。
 	8. 若v也相同，按照ID递增排列。

##### 解析

按照上述排序方式写cmp函数即可。这里最好在输入每个人之后先将他们的等级算好。

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

using namespace std;

struct People {
	string id;
	int virtue;
	int talent;
	int cls;
	int total;
};

int n, h, l;
vector<People> list;

int cls (People p) {
	if (p.talent >= h && p.virtue >= h) {
		return 4;
	} else if (p.talent < h && p.virtue >= h) {
		return 3;
	} else if (p.talent <h && p.virtue < h && p.virtue >= p.talent) {
		return 2;
	} else {
		return 1;
	}
}

bool cmp (People p1, People p2) {
	if (p1.cls != p2.cls) {
		return p1.cls > p2.cls;
	} else {
		if (p1.total != p2.total) return p1.total > p2.total;
		else {
			if (p1.virtue != p2.virtue) return p1.virtue > p2.virtue;
			else {
				return p1.id < p2.id;
			}
		}
	}
}

int main () {
	

	scanf("%d%d%d", &n, &l, &h);

	People p;
	p.id.resize(8);

	for(int i = 0; i < n; i++) {
		scanf("%s%d%d", &p.id[0], &p.virtue, &p.talent);
		if (p.virtue >= l && p.talent >= l) {
			p.cls = cls(p);
			p.total = p.virtue + p.talent;
			list.push_back(p);
		}
	}

	sort(list.begin(), list.end(), cmp);

	printf("%d\n", list.size());
	for(int i = 0; i < list.size(); i++) {
		printf("%s %d %d\n", list[i].id.c_str(), list[i].virtue, list[i].talent);
	}
	
	return 0;
}
```

