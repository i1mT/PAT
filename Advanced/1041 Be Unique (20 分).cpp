#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

#define MAX 100001

struct Num {
	int num;
	int order;
};

map<int, Num> m;


int main () {

	int N, tmp, res = -1, resOrder = MAX + 1;

	Num ntmp;

	scanf("%d", &N);

	if (N == 0) return 0;

	for(int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		ntmp.num = 1;
		ntmp.order = i;
		if(m.find(tmp) == m.end()) {
			// new
			m[tmp] = ntmp;
		} else {
			m[tmp].num++;
		}
	}
	

	for(map<int, Num>::iterator it = m.begin(); it != m.end(); it++) {
		ntmp = it->second;
		if (it->second.num == 1 && it->second.order < resOrder) {
			res = it->first;
			resOrder = it->second.order;
		}
	}

	if (res < 0) printf("None");
	else printf("%d", res);


	return 0;
}
