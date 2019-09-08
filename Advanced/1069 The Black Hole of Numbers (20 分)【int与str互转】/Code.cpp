#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string num;

int str2int (string s) {
	int res = 0;
	int duct = 1;

	

	for(int i = s.size()-1; i >= 0; i--) {
		res += (s[i]-'0') * duct;
		duct *= 10;
	}
	
	return res;
}

string int2str (int n) {
	string res = "";
	string stmp;
	int duct = 1, tmp;

	while(n > 0) {
		tmp = n%10;
		res = char(tmp + '0') + res;
		n /= 10;
	}
	
	int a = 4 - res.size();
	while(a>0) {
		res = "0" + res;
		a--;
	}

	return res;
}

string sub(string s) {

	string s1 = s;
	sort(s.begin(), s.end(), greater<char>());
	sort(s1.begin(), s1.end());

	int res = str2int(s) - str2int(s1);
	string sres = int2str(res);
	
	printf("%s - %s = %s\n", s.c_str(), s1.c_str(), sres.c_str());

	return sres;
}

int main () {


	cin >> num;

	int a = 4-num.size();
	while(a>0) {
		num = "0" + num;
		a--;
	}

	num = sub(num);

	while(num != "6174" && num != "0000") {
		num = sub(num);
	}

	return 0;
}
