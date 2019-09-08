#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

struct Node {
	int id;
	int data;
	int next;
};


Node list[100010];
vector<Node> llist;
int head, n, k;

int main () {
	scanf("%d%d%d", &head, &n, &k);

	Node nd;
	int tmp;

	if(n == 0) return 0;

	for(int j = 0; j < n; j++) {
		scanf("%d%d%d", &tmp, &nd.data, &nd.next);
		nd.id = tmp;
		list[tmp] = nd;
	}

	int p = head;

	while(p >= 0) {
		llist.push_back(list[p]);

		p = list[p].next;
	}

	int cnt = llist.size()/k;

	for(int i = 0; i < cnt; i++) {
		reverse(llist.begin() + i*k, llist.begin()+i*k+k );
	}

	for (int i = 0; i < llist.size(); i++) {
		if(i != 0)
			printf("%05d\n", llist[i].id);

		printf("%05d %d ", llist[i].id, llist[i].data);

		if(i == llist.size() - 1) printf("-1\n");
	}
	return 0;
}
