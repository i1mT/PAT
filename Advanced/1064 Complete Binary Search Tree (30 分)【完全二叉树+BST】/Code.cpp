#include <iostream>
#include <strstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>

#define maxn 1010

using namespace std;

int n, idx = 0;
int cbt[maxn], num[maxn];


void inorder(int root) {
	if(root > n) return;

	inorder(root*2);
	cbt[root] = num[idx++];
	inorder(root*2+1);
}

int main () {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num+n);
	inorder(1);

	for(int i = 1; i <= n; i++) {
		if(i!=1) printf(" ");
		printf("%d", cbt[i]);
	}

	return 0;
}
