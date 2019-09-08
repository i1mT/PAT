# 1061 Dating (20 分)

Sherlock Holmes received a note with some strange strings: `Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm`. It took him only a minute to figure out that those strange strings are actually referring to the coded time `Thursday 14:04` -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter `D`, representing the 4th day in a week; the second common character is the 5th capital letter `E`, representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from `A` to `N`, respectively); and the English letter shared by the last two strings is `s` at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

### Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

### Output Specification:

For each test case, print the decoded time in one line, in the format `DAY HH:MM`, where `DAY` is a 3-character abbreviation for the days in a week -- that is, `MON` for Monday, `TUE` for Tuesday, `WED` for Wednesday, `THU` for Thursday, `FRI` for Friday, `SAT` for Saturday, and `SUN`for Sunday. It is guaranteed that the result is unique for each case.

### Sample Input:

```in
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
```

### Sample Output:

```out
THU 14:04
```

### Analysis

##### 题目大意

day：前两个字符串的第一个相同大写字母是第四个字母D，代表星期4

hour：前两个字符串第二个相同的字符是E，代表14。一天0-23小时被0-9加A-N表示。

minute：后两个字符串相同英文字母出现在第四个位置s，代表第4分钟。

##### 解析

看代码即可

### Code

```
#include <iostream>
#include <strstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main () {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	int m, index;
	char day, h;
	int l = min(a.size(), b.size());
	for(int i = 0; i < l; i++) {
		if(a[i] == b [i] && (a[i] >= 'A' && a[i] <= 'G')) {
				day = a[i];
				index = i;
				break;
		}
	}

	for(int i = index + 1; i < l; i++) {
		if(a[i] == b [i]) {
			if((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i])) {
				h = a[i];
				break;
			}
		}
	}


	int len = min(d.size(), c.size());
	for (int i = 0; i < len; i++) {
		if (c[i] == d[i] && isalpha(c[i])) {
			m = i;
			break;
		}
	}

	int hh = isdigit(h) ? h-'0' : h-'A'+10;

	cout<< week[day-'A'];
	printf(" %02d:%02d", hh, m);



	return 0;
}
```

