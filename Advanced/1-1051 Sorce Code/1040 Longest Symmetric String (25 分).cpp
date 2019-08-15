#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

string longestPalindrome1(string s)
{
    if(s.empty()) return "";
    if(s.size() == 1) return s;
    int start = 0, maxlength = 1;//记录最大回文子串的起始位置以及长度
	for(int i=0; i<s.size(); i++) {
		for(int j=i+1; j<s.size(); j++)//从当前位置的下一个开始算
		{
			int temp1, temp2;
			for(temp1 = i,temp2 = j; temp1 < temp2; temp1++,temp2--)
			{
				if(s[temp1] != s[temp2])
					break;
			}
			if(temp1 >= temp2 && j-i+1 > maxlength)//这里要注意条件为temp1>=temp2，因为如果是偶数个字符，相邻的两个经上一步会出现大于的情况
			{
				maxlength = j-i+1;
				start = i;
			}
		}
	}

    return s.substr(start, maxlength);//利用string中的substr函数来返回相应的子串,第一个参数是起始位置，第二个参数是字符个数
}

/*
 * DP 解法
 * 状态转移方程：
 * 若str[i] == str[j]，若dp[i+1][j-1] == 1，则str[i...j]是回文串
 * 若str[i] != str[j]，dp[i][j] = 1
 */
string longestPalindromeDP(string s) {
	if (s == "") return s;
	int len = s.size();
	if (len == 1) return s;
	
	int longest = 1; // 最长的长度
	int start = 0; // 最长回文串的起点
	vector< vector<int> > dp(len, vector<int>(len));

	// 初始化dp数组，dp[i][i] = 1，若s[i] == s[i+1](连续两字符相同)，则dp[i]dp[i+i] = 1
	for(int i = 0; i < len; i++) {
		dp[i][i] = 1;

		if (i < len - 1) {
			if (s[i] == s[i+1]) {
				dp[i][i+1] = 1;
				start = i;
				longest = 2;
			}
		}
	}

	// 开始解决字串
	for (int i = 3; i <= len; i++) { // 字串长度
		for (int t = 0; i + t - 1 < len; t++) { // 字串起点
			int e = i + t - 1; // 终点

			if (s[t] == s[e] && dp[t+1][e-1] == 1) {
				dp[t][e] = 1;
				start = t;
				longest = i;
			}
		}
	}

	return s.substr(start, longest);
}

int main () {
	string s, res;
	
	getline(cin, s);
	
	res = longestPalindromeDP(s);

	printf("%d\n", res.size());

	return 0;
}
