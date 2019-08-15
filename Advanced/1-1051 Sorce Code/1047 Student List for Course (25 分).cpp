#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <cstdio>

using namespace std;


int n, k, c, tmp;
string s;
vector<vector<string>> table;

int main () {
	scanf("%d%d", &n, &k);
	table.resize(k+1);
	for(int i = 0; i < n; i++) {
		cin >> s;
		scanf("%d", &c);
		for(int j = 0; j < c; j++) {
			scanf("%d", &tmp);
			table[tmp].push_back(s);
		}
	}
	for(int i = 1; i <= k; i++) {
		printf("%d %d\n", i, table[i].size());
		sort(table[i].begin(), table[i].end());
		for(int j = 0; j < table[i].size(); j++)
			printf("%s\n", table[i][j].c_str());
	}

	return 0;
}
