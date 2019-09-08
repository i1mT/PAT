# 1071 Speech Patterns (25 分)

People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

### Input Specification:

Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return `\n`. The input contains at least one alphanumerical character, i.e., one character from the set [`0-9 A-Z a-z`].

### Output Specification:

For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.

Note that words are case **insensitive**.

### Sample Input:

```in
Can1: "Can a can can a can?  It can!"
```

### Sample Output:

```out
can 5
```

### Analysis

##### 题目大意

输入一行，找出出现最多的单词。单词定义：连续的字母数字混合的字符，由非字母数字字符或开头结尾隔开。

##### 解析

用map存储，for一遍，将所有单词都存进去，找出现次数最多的。

### Code

```
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

map<string, int> mp;

void insert (string s) {
	if(mp.find(s) != mp.end()) {
		mp[s]++;
	} else {
		mp[s] = 1;
	}
}

int main () {
	string s, tmp = "";

	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i]) || isalpha(s[i])) {
			if (s[i]<= 'Z' && !isdigit(s[i])) {
				s[i] = char('a' + int(s[i] - 'A'));
			}
			tmp += s[i];
		} else if (tmp != "") {
			insert(tmp);
			tmp = "";
		}

		if (i == s.size()-1 && tmp != "") {
			insert(tmp);
		}
	}
	
	int times = -1;

	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second > times) {
			tmp = it->first;
			times = it->second;
		}
	}

	printf("%s %d", tmp.c_str(), times);

	return 0;
}
```

