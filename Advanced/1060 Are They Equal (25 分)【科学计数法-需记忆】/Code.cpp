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

using namespace std;

int main () {
	int n;
	char a[10000], b[10000], A[10000], B[10000];

	scanf("%d%s%s", &n, a, b);
	
	int cnta = strlen(a), cntb = strlen(b);

	for(int i = 0; i < strlen(a); i++) {
		if(a[i] == '.') {
			cnta = i;
			break;
		}
	}

	for(int i = 0; i < strlen(b); i++) {
		if(b[i] == '.') {
			cntb = i;
			break;
		}
	}

	int indexa = 0, indexb = 0, p = 0, q = 0;
	while(a[p] == '0' || a[p] == '.') p++;
	while(b[q] == '0' || b[q] == '.') q++;

	if (cnta >= p)
		cnta = cnta - p;
	else
		cnta = cnta - p + 1;
	if(cntb >= q)
		cntb = cntb - q;
	else
		cntb = cntb - q + 1;

	if(p == strlen(a))
		cnta = 0;
	if(q == strlen(b))
		cntb = 0;

	while(indexa < n) {
		if(a[p] != '.' && p < strlen(a)) {
			A[indexa++] = a[p];
		} else if (p >= strlen(a)) {
			A[indexa++] = '0';
		}
		p++;
	}
	A[indexa] = '\0';

	while(indexb < n) {
		if(b[q] != '.' && q < strlen(b)) {
			B[indexb++] = b[q];
		} else if (q >= strlen(b)) {
			B[indexb++] = '0';
		}
		q++;
	}
	B
	[indexb] = '\0';

	if(strcmp(A, B) == 0 && cnta == cntb) {
		printf("YES 0.%s*10^%d", A, cnta);
	} else {
		printf("NO 0.%s*10^%d 0.%s*10^%d", A, cnta, B, cntb);
	}
	
	

	return 0;
}
