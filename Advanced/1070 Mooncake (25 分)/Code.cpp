#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

struct Good {
	double stock;
	double price;
	double rate;
};

vector<Good> list;

bool cmp (Good a, Good b) {
	return a.rate > b.rate;
}

int main () {

	int n;
	double d;
	scanf("%d%lf", &n, &d);

	list.resize(n);

	for(int i = 0; i < n; i++) {
		scanf("%lf", &list[i].stock);
	}
	for(int i = 0; i < n; i++) {
		scanf("%lf", &list[i].price);
		list[i].rate = list[i].price / list[i].stock;
	}

	sort(list.begin(), list.end(), cmp);

	double res = 0;
	int lidx = 0;

	while(d > 0 && lidx < n) {
		if (list[lidx].stock >= d) {
			res += d * list[lidx].rate;
			d -= list[lidx].stock;
		} else {
			res += list[lidx].price;
			d -= list[lidx].stock;

			lidx++;
		}
	}

	printf("%.2f", res);
	
	return 0;
}
