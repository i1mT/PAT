#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <sstream>


using namespace std;

int n, nume = 0, deno = 0, intiger = 0, t1, t2;

int gcd(int a, int b) {
	if (b == 0) return a;

	return gcd(b, a%b);
}

int minMul (int a, int b) {
	return a/gcd(a, b)*b;
}

void reduct (int &num, int &den) {
	int maxn = gcd(num, den);

	num /= maxn, den /= maxn;
}

void add (int &a1, int &b1, int &a2, int &b2) {

	if(b1 == 0) {
		nume = a2, deno = b2;
		return;
	}

	reduct(a1, b1);
	reduct(a2, b2);

	int mul = minMul(b1, b2);
	int c1 = mul/b1, c2 = mul/b2;

	a1 *= c1, a2 *= c2;

	b1 = mul, b2 = mul;

	a1 += a2;

	reduct(a1, b1);
}


int main () {
	
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d/%d", &t1, &t2);

		add(nume, deno, t1, t2);
	}

	intiger = nume/deno;
	if (intiger) {
		printf("%d", intiger);
		nume -= deno*intiger;
	}

	reduct(nume, deno);

	if (intiger && nume != 0)
		printf(" ");

	if (nume != 0)
		printf("%d/%d", nume, deno);

	if (intiger == 0 && nume == 0) {
		printf("0");
	}

	return 0;
}
