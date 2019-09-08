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
