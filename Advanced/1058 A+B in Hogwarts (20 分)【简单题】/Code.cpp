#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>

using namespace std;



int main () {
	
	int g, s, k;
	int g1, g2, s1, s2, k1, k2;

	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);

	k = k1 + k2;
	s = s1 + s2 + k/29;
	g = g1 + g2 + s/17;
	k %= 29;
	s %= 17;
	
	printf("%d.%d.%d", g, s, k);

	return 0;
}
