#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<algorithm> 

using namespace std;

struct Node {
	string id;
	int score, location, frank, lrank;
};

vector<Node> res;
vector< vector<Node> > src;
int N, K;

bool cmp(Node a, Node b) {
	if (a.score != b.score) return a.score > b.score;
	else if (a.id != b.id) return a.id < b.id;
}

void rankChildList(vector<Node> &list) {
	int index = 1, rank = 1, scoreMax;
	if (list.size() < 1) return;
	list[0].lrank = rank;
	scoreMax = list[0].score;
	for (; index < list.size(); index++) {
		if (list[index].score < scoreMax) {
			scoreMax = list[index].score;
			rank = index + 1;
			list[index].lrank = rank;
		}
		else if (list[index].score == scoreMax) {
			list[index].lrank = rank;
		}
	}
}

void merge() {
	sort(res.begin(), res.end(), cmp);
	int index = 1, rank = 1, scoreMax;
	if (res.size() < 1) return;
	res[0].frank = rank;
	scoreMax = res[0].score;
	for (; index < res.size(); index++) {
		if (res[index].score < scoreMax) {
			scoreMax = res[index].score;
			rank = index + 1;
			res[index].frank = rank;
		}
		else if (res[index].score == scoreMax) {
			res[index].frank = rank;
		}
	}
}

int main() {
	scanf("%d", &N);
	vector<Node> tmp;
	int itmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &itmp);
		tmp.clear();
		for (int j = 0; j < itmp; j++) {
			Node ntmp;
			cin >> ntmp.id >> ntmp.score;
			ntmp.location = i + 1;
			tmp.push_back(ntmp);
		}
		sort(tmp.begin(), tmp.end(), cmp);
		rankChildList(tmp);
		for (int j = 0; j < tmp.size(); j++) {
			res.push_back(tmp[j]);
		}
	}
	merge();

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].id << " " << res[i].frank << " " << res[i].location << " " << res[i].lrank << endl;
	}
	return 0;
}

