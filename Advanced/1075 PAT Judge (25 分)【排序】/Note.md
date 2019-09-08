# 1075 PAT Judge (25 分)

The ranklist of PAT is generated from the status list, which shows the scores of the submissions. This time you are supposed to generate the ranklist for PAT.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 3 positive integers, *N* (≤104), the total number of users, *K* (≤5), the total number of problems, and *M* (≤105), the total number of submissions. It is then assumed that the user id's are 5-digit numbers from 00001 to *N*, and the problem id's are from 1 to *K*. The next line contains *K*positive integers `p[i]` (`i`=1, ..., *K*), where `p[i]` corresponds to the full mark of the i-th problem. Then *M* lines follow, each gives the information of a submission in the following format:

```
user_id problem_id partial_score_obtained
```

where `partial_score_obtained` is either −1 if the submission cannot even pass the compiler, or is an integer in the range [0, `p[problem_id]`]. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, you are supposed to output the ranklist in the following format:

```
rank user_id total_score s[1] ... s[K]
```

where `rank` is calculated according to the `total_score`, and all the users with the same `total_score` obtain the same `rank`; and `s[i]` is the partial score obtained for the `i`-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

### Sample Input:

```in
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
```

### Sample Output:

```out
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
```

### Analysis

##### 题目大意

有n个用户，k道题目，m个提交记录。并给出每道题目的分值。要求你给他们排名：

	1. 按照总分排名，相同总分的排名相同。
 	2. 分数相同，按照完美通过数排名。
 	3. 完美通过数相同按照id排名。
 	4. 没提交过，或从未通过编译的不出现在排名列表上

##### 解析

定义结构体，要设置submit来存放提交书，perfect存放完美通过数(即获得满分)，通过编译数。之后sort，cmp函数根据上面4条写即可。

### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int n, k, m;
int score[6];

struct Node {
	int id;
	vector<int> scores;
	int perfect;
	int sum;
	int submit;
	int passed;
};

vector<Node> list;

bool cmp (Node a, Node b) {
	if (a.sum != b.sum) return a.sum > b.sum;
	if (a.perfect != b.perfect) return a.perfect > b.perfect;
	if (a.sum == 0)
		if (a.submit != b.submit) return a.passed > b.passed;
	return a.id < b.id;
}

int main () {
	int tmp;
	
	scanf("%d%d%d", &n, &k, &m);

	list.resize(n+1);

	for(int i = 1; i <= k; i++) {
		scanf("%d", &tmp);
		score[i] = tmp;
	}
	Node nd;
	nd.id = -1,nd.sum = 0, nd.perfect = 0, nd.submit = 0, nd.passed = 0;
	nd.scores.assign(6, -2);

	fill(list.begin(), list.end(), nd);

	int index, sc, id;


	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &id, &index, &sc);
		list[id].id = id;

		if (sc >= 0) {
			list[id].submit++;
			list[id].passed=1;
		}

		if (sc == score[index] && list[id].scores[index]!=score[index])
			list[id].perfect++;

		if (list[id].scores[index] < sc) { // 更新成绩与sum
			if (list[id].scores[index] > 0) // 若原成绩大于0
				list[id].sum -= list[id].scores[index];

			list[id].scores[index] = sc;

			if (sc > 0)
				list[id].sum += sc;
		}
	}

	sort(list.begin(), list.end(), cmp);

	int rank = 1;

	for(int i = 0; i < list.size(); i++) {
		if (list[i].id < 0) continue;
		if (list[i].submit == 0 || list[i].passed == 0) break;
		if (i > 0) {
			if (list[i].sum != list[i-1].sum)
				rank = i+1;
		}
		printf("%d %05d %d", rank, list[i].id, list[i].sum);

		for(int j = 1; j <= k; j++) {
			if (list[i].scores[j] < -1) printf(" -");
			else if (list[i].scores[j] == -1) printf(" 0");
			else printf(" %d", list[i].scores[j]);
		}
		printf("\n");
	}

	return 0;
}
```

