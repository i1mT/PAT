#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

#define MAX 100002

int c[MAX], dis[MAX];
int n, m, f, t, sum = 0;


int dist(int f, int t) {
	int len = len = dis[t-1] - dis[f-1];
	return min(len, sum - len);
}

int main () {

	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		sum += c[i];
		dis[i] = sum;
	}

	scanf("%d", &m);

	for(int i = 0; i < m; i++) {
		scanf("%d%d", &f, &t);
		if(f > t) swap(f, t);
		printf("%d\n", dist(f, t));
	}

	return 0;
}
