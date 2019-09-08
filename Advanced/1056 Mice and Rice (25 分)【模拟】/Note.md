# 1056 Mice and Rice (25 分)

**Mice and Rice** is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.

First the playing order is randomly decided for *N**P* programmers. Then every *N**G*programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every *N**G* winners are then grouped in the next match until a final winner is determined.

For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.

### Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: *N**P* and *N**G* (≤1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than *N**G* mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains *N**P* distinct non-negative numbers *W**i* (*i*=0,⋯,*N**P*−1) where each *W**i* is the weight of the *i*-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,⋯,*N**P*−1 (assume that the programmers are numbered from 0 to *N**P*−1). All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print the final ranks in a line. The *i*-th number is the rank of the *i*-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.

### Sample Input:

```in
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
```

### Sample Output:

```out
5 5 5 2 5 5 5 3 1 3 5
```



### ### Analysis

##### 题目大意

给定np为游戏玩家数，ng为每个组的容量，每个玩家的重量W[i]，玩家游戏先后序列。模拟游戏，输出最终排名。游戏玩法为：

	1. 从游戏先后序列分组，每个组人数不能超过np。
 	2. 每个组中选出重量最大的，进入下一轮游戏。
 	3. 继续1，直到进入下一轮游戏的人数为1。
 	4. 之后排序，注意排序是并列排序。

##### 解析

游戏序列保存于队列中，设置q为游戏队列，qg为进入下一轮游戏的序列。每次先按照ng个一组分组，将每个组最重的放入ng。q空之后将ng全部复制入q中，再进行游戏。直到ng的长度为1停止循环。

【注意】：为了能够记录排名，设置rk向量，每当有序号为K的玩家进入下一局，就rk[K]++。之后排序按照并列排序输出即可。



### Code

```c++
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


struct Node {
	int id;
	int num;
};

int np, ng, max_rk = -1;
vector<int> w;
queue<int> q;
vector<int> rk;
vector< Node > res;

bool cmp(Node a, Node b) {
	return a.num > b.num;
}

void solve () {
	int tmp, mmax = -1, maxI, level = 0;
	int cnt;
	queue<int> qg;
	while(1) {
		while(!qg.empty()) {
			q.push(qg.front());
			qg.pop();
		}
		mmax = -1;
		cnt = 0;
		while(!q.empty()) {
			tmp = q.front();
			q.pop();
			
			cnt++;
			if (w[tmp] > mmax) {
				mmax = w[tmp];
				maxI = tmp;
			}
			if(cnt%ng == 0 || q.empty()) {
				if (mmax != -1) {
					qg.push(maxI);
					rk[maxI] += 1;
					max_rk = max(max_rk, rk[maxI]);
					mmax = -1;
				}
			}
		}
		if(cnt == 1) {
			break;
		}
	}

	Node p;
	for(int i = 0; i < rk.size(); i++) {
		p.id = i;
		p.num = rk[i];
		res.push_back(p);
	}
	sort(res.begin(), res.end(), cmp);

	int order = 0, num;
	for(int i = 0; i < res.size(); i++) {
		if(i == 0) {
			num = res[i].num;
			order++;
			rk[res[i].id] = order;
		}
		if(num > res[i].num) {
			num = res[i].num;
			order = i + 1;
			rk[res[i].id] = order;
		} else {
			rk[res[i].id] = order;
		}
	}

	for(int i = 0; i < rk.size(); i++) {
		if(i != 0) printf(" ");
		printf("%d", rk[i]);
	}
}

int main () {
	
	int tmp;

	scanf("%d%d", &np, &ng);
	rk.assign(np, -1);

	for (int i = 0; i < np; i++) {
		scanf("%d", &tmp);
		w.push_back(tmp);
	}

	for(int i = 0; i < np; i++) {
		scanf("%d", &tmp);
		q.push(tmp);
	}

	solve();
	
	return 0;
}
```

