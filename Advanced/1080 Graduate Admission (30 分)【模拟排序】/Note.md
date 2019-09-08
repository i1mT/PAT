# 1080 Graduate Admission (30 分)

It is said that in 2011, there are about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.

Each applicant will have to provide two grades: the national entrance exam grade *G**E*, and the interview grade *G**I*. The final grade of an applicant is (*G**E*+*G**I*)/2. The admission rules are:

- The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.
- If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade *G**E*. If still tied, their ranks must be the same.
- Each applicant may have *K* choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.
- If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, **even if its quota will be exceeded**.

### Input Specification:

Each input file contains one test case.

Each case starts with a line containing three positive integers: *N* (≤40,000), the total number of applicants; *M* (≤100), the total number of graduate schools; and *K* (≤5), the number of choices an applicant may have.

In the next line, separated by a space, there are *M* positive integers. The *i*-th integer is the quota of the *i*-th graduate school respectively.

Then *N* lines follow, each contains 2+*K* integers separated by a space. The first 2 integers are the applicant's *G**E* and *G**I*, respectively. The next *K* integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to *M*−1, and the applicants are numbered from 0 to *N*−1.

### Output Specification:

For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.

### Sample Input:

```in
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
```

### Sample Output:

```out
0 10
3
5 6 7
2 8

1 4
```

### Analysis

##### 题目大意

有n个考生，m个学校，每个考生能有k个志愿。并给出每个考生的初试成绩ge与复试成绩gi以及k个志愿，求按照以下方式排名录取的录取结果。(学校编号从n-m，考生编号从0-n)

	1. 按照总分排名，总分计算方式为(ge+gi)/2。
 	2. 若总分相同，按照初试分数ge排名，若初始分数相同，名次应该相同。
 	3. 每个考生从排名第一开始一个一个录取。
 	4. 每个考生从前到后一个一个考虑其志愿决定录取与否。若某考生志愿学校招生人数未满，则录取；否则不予录取，考虑下一个志愿。
 	5. 若有考生在相同排名，并且**对应位置的志愿相同**，则学校无论是否超过招生人数，都应将相同排名的考生全部录取。

输出时第i行输出编号为i的学校的录取学生的编号，若某学校没有录取学生，应输出一个空行。

##### 解析

定义Stu结构体，保存ge，gi，sum总分，rank排名，prefer[]志愿。

之后根据sum与ge排序，然后更新每个学生的排名。

之后按照排名从前到后循环，当学校还有名额，或者学校最后一个招的人的排名与当前人的排名相同时，录取当前学生。之后先根据id排序，然后输出。



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


struct Stu {
	int id;
	int ge, gi, index;
	double sum;
	int rank;
	int prefer[6];
};

int n, m, k;
vector<vector<int>> res;
int quota[110];
vector<Stu> apps;

bool cmp (Stu a, Stu b) {
	if (a.sum != b.sum) return a.sum > b.sum;
	return a.ge > b.ge;
}
bool cmp1(int a, int b) {
	return apps[a].id < apps[b].id;
}


int main () {
	int tmp;

	scanf("%d%d%d", &n, &m, &k);

	res.resize(m);

	for(int i = 0; i < m; i++) {
		scanf("%d", &quota[i]);
	}

	Stu s;

	for(int i = 0; i < n; i++) {
		scanf("%d%d", &s.ge, &s.gi);
		s.sum = double((s.ge + s.gi) / 2);
		s.id = i;

		for(int j = 0; j < k; j++) {
			scanf("%d", &s.prefer[j]);
		}

		apps.push_back(s);
	}

	sort(apps.begin(), apps.end(), cmp);

	int cnt = 1;
	apps[0].rank = 1;
	for(int i = 1; i < apps.size(); i++) {

		if (apps[i].sum == apps[i-1].sum && apps[i].ge == apps[i-1].ge) apps[i].rank = apps[i-1].rank;
		else apps[i].rank = i+1;
	}
	int sc;
	for(int i = 0; i < apps.size(); i++) {
		for(int j = 0; j < k; j++) {
			sc = apps[i].prefer[j];

			if (quota[sc] != 0 || apps[ res[sc][ res[sc].size()-1 ] ].rank == apps[i].rank ) {
				res[sc].push_back(i);
				apps[i].index = j;
				if (quota[sc]!=0) quota[sc]--;

				break;
			}
		}
	}

	for(int i = 0; i < res.size(); i++) {
		sort(res[i].begin(), res[i].end(), cmp1);
		for(int j = 0; j < res[i].size(); j++) {
			if (j != 0) printf(" ");
			printf("%d", apps[res[i][j]].id);
		}

		printf("\n");
	}

	return 0;
}
```

