#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<algorithm> 

using namespace std;

string S = "0123456789ABC";

string solve(int num, int radix) {
	string res = "";
	int tmp;
	while (num != 0) {
		tmp = num / radix;
		res = S[num % radix] + res;
		num = tmp;
	}
	if (res.size() == 1) return "0" + res;
	if (res.size() == 0) return "00";
	return res;
}

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#" << solve(r, 13) << solve(g, 13) << solve(b, 13) << endl;
	return 0;
}

