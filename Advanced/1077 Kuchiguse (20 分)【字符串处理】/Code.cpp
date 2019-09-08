#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>

using namespace std;

int n;
vector<string> data;


int main () {
	scanf("%d", &n);
	data.resize(n+1);
	ios::sync_with_stdio(false);

	string res = "", tmp;

	int flag, minlen = 9999;
	getline(cin, tmp);
	for(int i = 0; i < n; i++) {
		getline(cin, data[i]);

		if(data[i].size() < minlen) minlen = data[i].size();
	}

	char c;
	int cnt = 0;
	for(int i = 0; i < minlen; i++) {
		c = data[0][data[0].size() - i - 1];
		flag = 1;
		for(int j = 1; j < n; j++) {
			if (c != data[j][data[j].size() - i - 1]) {
				flag = 0;
				break;
			}
		}

		if(!flag) break;
		else res = c + res;
	}

	if (res == "") {
		printf("nai");
	} else {
		printf("%s", res.c_str());
	}

	return 0;
}
