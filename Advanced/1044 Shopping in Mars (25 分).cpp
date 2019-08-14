#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

struct Item {
	int i;
	int j;
	int sum;
};

vector<int> chain;
vector<Item> slsPool;

int cmp (Item a, Item b) {
	return a.i < b.i;
}

int main () {

	int N, M, tmp;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);

		chain.push_back(tmp);
	}

	int head = 0, tmpTail = -1, sum = 0, mini = -1;
	Item item;

	while (1) {
		tmpTail++;
		sum += chain[tmpTail];
		if (sum >= M) {
			if (mini == -1) mini = sum;

			if (sum <= mini) {
				item.i = head + 1;
				item.j = tmpTail + 1;
				item.sum = sum;

				slsPool.push_back(item);

				mini = sum;
			}
			head++;
			tmpTail = head - 1;
			sum = 0;
		}

		if (tmpTail == chain.size() - 1) break;
	}

	vector<Item> sls;
	for(int i = 0; i < slsPool.size(); i++) {
		if (slsPool[i].sum == mini) {
			sls.push_back(slsPool[i]);
		}
	}

	sort(sls.begin(), sls.end(), cmp);

	for(int i = 0; i < sls.size(); i++) {
		printf("%d-%d\n", sls[i].i, sls[i].j);
	}

	return 0;
}
