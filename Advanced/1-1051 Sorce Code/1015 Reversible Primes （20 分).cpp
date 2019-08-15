#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/*
埃式筛法，区间筛法

a<b≤10^12, b-a≤10^6
*/

vector<bool> isPrime;

void getPrime(int n) {
	isPrime.assign(n + 1, true);
	isPrime[0] = false, isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n && i <= sqrt(n); j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int getDec(string num, int radix) {
	int sum = 0;
	int r = 1;
	for (int i = num.size() - 1; i >= 0; i--) {
		sum += r * int(num[i] - '0');
		r *= radix;
	}
	// cout << num << " " << radix << "->" << sum << endl;
	return sum;
}

string getNumRevString(int num, int radix) {
	string res = "";
	int tmp;
	while (num) {
		tmp = num % radix;
		num /= radix;

		res.push_back('0' + tmp);
	}

	return res;
}




int main() {
	int max = 100000;
	getPrime(max);
	int radix, num, revNum;
	string revSnum;
	while (1) {
		scanf("%d", &num);
		if (num < 0) break;
		scanf("%d", &radix);

		revSnum = getNumRevString(num, radix);
		revNum = getDec(revSnum, radix);


		if (isPrime[num] && isPrime[revNum]) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}
