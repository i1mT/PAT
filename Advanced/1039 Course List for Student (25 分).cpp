#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

map< string, set<int> > data;

int N, K;

void queryOutput(string name) {
	set<int> s = data[name];
	cout << name;
	printf(" %d", s.size());

	for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
		printf(" %d", *it);
	}
	printf("\n");
}

int main () {
	string s;
	int tmp, cid, num;
	s.resize(4);
	scanf("%d%d", &N, &K);


	for(int i = 0; i < K; i++) {
		scanf("%d%d", &cid, &num);

		for(int j = 0; j < num; j++) {
			scanf("%s", &s[0]);
			if (data.count(s) != 1) {
				// ц╩сп
				set<int> sset;
				sset.insert(cid);

				data[s] = sset;
			} else {
				data[s].insert(cid);
			}
		}
	}

	for(int i = 0; i < N; i++) {
		scanf("%s", &s[0]);
		queryOutput(s);
	}

	return 0;
}
