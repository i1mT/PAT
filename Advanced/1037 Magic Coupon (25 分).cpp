#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>

using namespace std;

bool cmp1 (int a, int b) {
	return a > b;
}

bool cmp2 (int a, int b) {
	return a < b;
}

int main () {
	vector<int> couponP, couponN;
	vector<int> productP, productN;

	int N, M, sum = 0;

	scanf("%d", &N);
	int tmp, t, top = 0;
	P p;
	p.used = 0;
	for(int i = 0; i < N; i++) {
		scanf("%d", &tmp);

		if(tmp > 0)
			couponP.push_back(tmp);
		else
			couponN.push_back(tmp);
	}
	scanf("%d", &M);
	for(int i = 0; i < M; i++) {
		scanf("%d", &tmp);

		if(tmp > 0)
			productP.push_back(tmp);
		else
			productN.push_back(tmp);
	}
	sort(productP.begin(),productP.end(), cmp1);
	sort(couponP.begin(),couponP.end(), cmp1);

	sort(productN.begin(),productN.end(), cmp2);
	sort(couponN.begin(),couponN.end(), cmp2);
	
	int i;

	i = 0;
	while(i < couponP.size() && i < productP.size()) {
		sum += couponP[i] * productP[i];
		i++;
	}

	i = 0;
	while(i < couponN.size() && i < productN.size()) {
		sum += couponN[i] * productN[i];
		i++;
	}
	

	printf("%d\n", sum);

	return 0;
}
