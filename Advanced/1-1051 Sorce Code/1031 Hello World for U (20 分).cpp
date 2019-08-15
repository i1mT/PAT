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

string s;
int N, n1 = -1, n2, tempn2;

int main() {
	cin >> s;
	N = s.size();
	for (int i = N; i >= 3; i--) {
		tempn2 = i;
		if ((N + 2 - tempn2) % 2 != 0) continue;
		if ((N + 2 - tempn2) / 2 > n1 && tempn2 >= (N + 2 - tempn2) / 2) {
			n1 = (N + 2 - tempn2) / 2;
			n2 = tempn2;
		}
 	}
	int cnt = 0;
	vector<string> ss;
	string tmps = "";
	for (int i = 0; i < n2; i++) tmps += " ";
	ss.assign(n1, tmps);

	for (int i = 0; i < n1; i++) {
		ss[i][0] = s[i];
		ss[i][n2 - 1] = s[N - i - 1];
	}
	for (int i = 1; i < n2 - 1; i++) {
		ss[n1 - 1][i] = s[n1 + i - 1];
	}
	for (int i = 0; i < ss.size(); i++) {
		cout << ss[i] << endl;
	}
	return 0;
}
