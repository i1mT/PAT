#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <sstream>

using namespace std;

struct Node {
	int index;
	char c;
};

map<char, int> tmp;
vector<Node> res;

void toUpperCase(char &c) {
	if (!isalpha(c) || c <= 'Z') return;

	c = char('A' + (c - 'a'));
}

bool cmp(Node a, Node b) {
	return a.index < b.index;
}

int main () {
	string origin, str;

	ios::sync_with_stdio(false);

	cin >> origin >> str;

	int i = 0, j = 0;

	Node nd;

	while(i < origin.size() && j < str.size()) {
		if (origin[i] != str[j]) {
			nd.index = i;
			nd.c = origin[i];
			toUpperCase(nd.c);
			if (tmp.find(nd.c) == tmp.end())
				tmp[nd.c] = nd.index;
			i++;
		} else {
			i++;
			j++;
		}
	}

	if (i < origin.size()) {
		for(;i < origin.size(); i++) {
			nd.index = i;
			nd.c = origin[i];
			toUpperCase(nd.c);
			if (tmp.find(nd.c) == tmp.end())
				tmp[nd.c] = nd.index;
		}
	}


	for(map<char, int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		nd.index = it->second;
		nd.c = it->first;

		res.push_back(nd);
	}

	sort(res.begin(), res.end(), cmp);

	for(int i = 0; i < res.size(); i++) {
		printf("%c", res[i].c);
	}

	return 0;
}
