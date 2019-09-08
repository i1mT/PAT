# 1077 Kuchiguse (20 分)

The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

- Itai nyan~ (It hurts, nyan~)
- Ninjin wa iyada nyan~ (I hate carrots, nyan~)

Now given a few lines spoken by the same character, can you find her Kuchiguse?

### Input Specification:

Each input file contains one test case. For each case, the first line is an integer *N* (2≤*N*≤100). Following are *N* file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

### Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all *N* lines. If there is no such suffix, write `nai`.

### Sample Input 1:

```in
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
```

### Sample Output 1:

```out
nyan~
```

### Sample Input 2:

```in
3
Itai!
Ninjinnwaiyada T_T
T_T
```

### Sample Output 2:

```out
nai
```

### Analysis

##### 题目大意

给你n个字符串，找出相同的结尾。如果没有相同的结尾，输出nai

##### 解析

从后遍历相同的加到res上，遇到不同的break，res为空串输出nai。

### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>

using namespace std;

int n;
vector<string> data;


int main () {
	scanf("%d", &n);
	data.resize(n+1);
	ios::sync_with_stdio(false);

	string res = "", tmp;

	int flag, minlen = 9999;
	getline(cin, tmp);
	for(int i = 0; i < n; i++) {
		getline(cin, data[i]);

		if(data[i].size() < minlen) minlen = data[i].size();
	}

	char c;
	int cnt = 0;
	for(int i = 0; i < minlen; i++) {
		c = data[0][data[0].size() - i - 1];
		flag = 1;
		for(int j = 1; j < n; j++) {
			if (c != data[j][data[j].size() - i - 1]) {
				flag = 0;
				break;
			}
		}

		if(!flag) break;
		else res = c + res;
	}

	if (res == "") {
		printf("nai");
	} else {
		printf("%s", res.c_str());
	}

	return 0;
}
```

