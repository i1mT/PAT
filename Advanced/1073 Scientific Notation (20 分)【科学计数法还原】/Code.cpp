#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

// +1.23400E-03

int str2int (string s) {
	int res = 0, duct = 1;

	for(int i = s.size()-1; i >= 0; i--) {
		res += duct*(s[i]-'0');
		duct*=10;
	}
	return res;
}

void solve(string s) {
	string res = "";
	string idx;
	// 确定符号
	string sign = s.substr(0, 1);
	if(sign == "-")
		cout << sign;
	
	s = s.substr(1);

	// 确定e前数字

	s.erase(1, 1);

	int eidx = s.find('E');

	res = s.substr(0, eidx);

	// 确定e的位置
	int negidx = s.find('-');
	if(negidx != -1) {
		// 指数为负
		int times = str2int(s.substr(negidx+1)) - 1;
		printf("0.");
		while(times > 0) {
			printf("0");
			times--;
		}
		cout << res;
	} else {
		// 指数为正
		int times = str2int(s.substr(eidx+2));
		if (times < res.size() - 1) {
			int cnt = 0;
			for(int i = 0; i < res.size(); i++) {
				printf("%c", res[i]);
				if(i==times) printf(".");
			}
		} else {
			times -= res.size()-1;
			cout << res;
			while(times > 0) {
				printf("0");
				times--;
			}
		}
	}
}

int main () {
	string s;

	cin >> s;

	solve(s);
	

	return 0;
}
