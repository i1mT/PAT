#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;

struct Node {
	int add;
	int key;
	int next;
	bool flag;
};

vector<int> ll;
vector<Node> list;
vector<Node> docker(100000);

bool cmp(Node a, Node b) {
	return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}

bool cmp1(int a, int b) {
	return docker[a].key < docker[b].key;
}


int main () {
	int n, head, cnt = 0;
	Node nd;

	scanf("%d%d", &n, &head);

	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &nd.add, &nd.key, &nd.next);
		nd.flag = false;
		docker[nd.add] = nd;
	}

	// ¼ÇÂ¼±í
	for(int i = head; i != -1; i = docker[i].next) {
		docker[i].flag = true;
		cnt++;
	}

	if(cnt == 0) {
		printf("0 -1");
		return 0;
	}

	sort(docker.begin(), docker.end(), cmp);

	printf("%d", cnt);
	for(int i = 0; i < cnt; i++) {
		printf(" %05d\n%05d %d", docker[i].add, docker[i].add, docker[i].key);

		if(i == cnt-1) {
			printf(" -1");
		}
	}

	return 0;
}
