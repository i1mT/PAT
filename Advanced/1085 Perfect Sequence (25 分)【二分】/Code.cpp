#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <sstream>

using namespace std;

int n, p, tmp, res = 0;
vector<long long> list;

int main () {
	scanf("%d%d", &n, &p);

	for(int i = 0; i < n; i++) {
		scanf("%lld", &tmp);

		list.push_back(tmp);
	}

	sort(list.begin(), list.end());

	for(int i = 0; i < n; i++) {
		int temp = upper_bound(list.begin(), list.end(), list[i]*p) - list.begin() - i;

		res = max(res, temp);
	}

	printf("%d", res);

	return 0;
}
