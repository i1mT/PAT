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
	string name;
	int age;
	int asset;
};

int n, m, num, l, h;
vector<Node> list;

bool cmp (Node a, Node b) {
	if(a.asset != b.asset)
		return a.asset > b.asset;
	if(a.age != b.age)
		return a.age < b.age;
	return a.name < b.name;
}

void solve() {
	int cnt = 0;
	for(int i = 0; cnt < num && i < list.size(); i++) {
		if (list[i].age >= l && list[i].age <= h) {
			cnt++;
			printf("%s %d %d\n", list[i].name.c_str(), list[i].age, list[i].asset);
		}
	}
	if(cnt == 0) {
		printf("None\n");
	}
}

int main () {
	
	scanf("%d%d", &n, &m);
	Node nd;
	nd.name.resize(8);
	int max_page = 100;

	for(int i = 0; i < n; i++) {
		scanf("%s%d%d", &nd.name[0], &nd.age, &nd.asset);

		list.push_back(nd);
	}

	sort(list.begin(), list.end(), cmp);

	for(int i = 0; i < m; i++) {
		printf("Case #%d:\n", i+1);
		scanf("%d%d%d", &num, &l, &h);
		solve();
	}
	return 0;
}
