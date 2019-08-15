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
    int start = 0, maxlength = 1;//��¼�������Ӵ�����ʼλ���Լ�����
	for(int i=0; i<s.size(); i++) {
		for(int j=i+1; j<s.size(); j++)//�ӵ�ǰλ�õ���һ����ʼ��
		{
			int temp1, temp2;
			for(temp1 = i,temp2 = j; temp1 < temp2; temp1++,temp2--)
			{
				if(s[temp1] != s[temp2])
					break;
			}
			if(temp1 >= temp2 && j-i+1 > maxlength)//����Ҫע������Ϊtemp1>=temp2����Ϊ�����ż�����ַ������ڵ���������һ������ִ��ڵ����
			{
				maxlength = j-i+1;
				start = i;
			}
		}
	}

    return s.substr(start, maxlength);//����string�е�substr������������Ӧ���Ӵ�,��һ����������ʼλ�ã��ڶ����������ַ�����
}

/*
 * DP �ⷨ
 * ״̬ת�Ʒ��̣�
 * ��str[i] == str[j]����dp[i+1][j-1] == 1����str[i...j]�ǻ��Ĵ�
 * ��str[i] != str[j]��dp[i][j] = 1
 */
string longestPalindromeDP(string s) {
	if (s == "") return s;
	int len = s.size();
	if (len == 1) return s;
	
	int longest = 1; // ��ĳ���
	int start = 0; // ����Ĵ������
	vector< vector<int> > dp(len, vector<int>(len));

	// ��ʼ��dp���飬dp[i][i] = 1����s[i] == s[i+1](�������ַ���ͬ)����dp[i]dp[i+i] = 1
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

	// ��ʼ����ִ�
	for (int i = 3; i <= len; i++) { // �ִ�����
		for (int t = 0; i + t - 1 < len; t++) { // �ִ����
			int e = i + t - 1; // �յ�

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
