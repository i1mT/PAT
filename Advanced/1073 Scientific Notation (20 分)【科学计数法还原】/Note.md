# 1073 Scientific Notation (20 分)

Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]`.`[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number *A* in scientific notation, you are supposed to print *A* in the conventional notation while keeping all the significant figures.

### Input Specification:

Each input contains one test case. For each case, there is one line containing the real number *A* in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

### Output Specification:

For each test case, print in one line the input number *A* in the conventional notation, with all the significant figures kept, including trailing zeros.

### Sample Input 1:

```in
+1.23400E-03
```

### Sample Output 1:

```out
0.00123400
```

### Sample Input 2:

```in
-1.2E+10
```

### Sample Output 2:

```out
-12000000000
```

### Analysis

##### 题目大意

给你一个科学技术法表示的数，将其转为常规数字。

##### 解析

细心就好。

### Code

```
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
```

