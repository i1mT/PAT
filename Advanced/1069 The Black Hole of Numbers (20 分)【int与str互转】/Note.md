# 1069 The Black Hole of Numbers (20 分)

For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number `6174` -- the **black hole** of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from `6767`, we'll get:

```
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
```

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

### Input Specification:

Each input file contains one test case which gives a positive integer *N* in the range (0,104).

### Output Specification:

If all the 4 digits of *N* are the same, print in one line the equation `N - N = 0000`. Else print each step of calculation in a line until `6174` comes out as the difference. All the numbers must be printed as 4-digit numbers.

### Sample Input 1:

```in
6767
```

### Sample Output 1:

```out
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
```

### Sample Input 2:

```in
2222
```

### Sample Output 2:

```out
2222 - 2222 = 0000
```

### Analysis

##### 题目大意

给你一个不超过10000的数字，它各位降序排列的数字与升序排列的数字相减，得到的结果再进行同样操作，最后数字会固定在6174。让你模拟这个过程。

##### 解析

写两个函数str2int与int2str就好了。

注意处理输入位数小于4的情况。



### Code

```
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
```

