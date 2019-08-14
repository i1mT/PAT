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


stack<int> ss;


int m, n, k;

bool check (vector<int> seq) {
	while(!ss.empty()) ss.pop();

	int i = 1, index = 0;
	//printf("->");
	while(ss.size() < m && index < seq.size()) {
		ss.push(i++);
		while(!ss.empty() && seq[index] == ss.top()) {
			index++;
			//printf("%d ", ss.top());
			ss.pop();
		}
	}
	//printf("\n");

	if (index != seq.size() || !ss.empty()) return false;

	return true;
}


int main () {
	scanf("%d%d%d", &m, &n, &k);
	int tmp;
	for(int i = 0; i < k; i++) {
		vector<int> seq;
		for(int j = 0; j < n; j++) {
			scanf("%d", &tmp);

			seq.push_back(tmp);
		}

		if (check(seq)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
