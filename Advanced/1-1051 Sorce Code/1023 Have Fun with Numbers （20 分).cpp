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

string number = "0123456789";
const int MAXSIZE = 100;

string add(string a, string b) {
	string ans;
	int na[MAXSIZE] = { 0 }, nb[MAXSIZE] = { 0 };
	int la = a.size(), lb = b.size();

	for (int i = 0; i < la; i++) na[la - i - 1] = a[i] - '0';
	for (int i = 0; i < lb; i++) nb[lb - i - 1] = b[i] - '0';

	int lmax = la > lb ? la : lb;

	for (int i = 0; i < lmax; i++) {
		na[i] += nb[i];
		na[i + 1] += na[i] / 10;
		na[i] %= 10;
	}

	if (na[lmax]) lmax++;

	for (int i = lmax - 1; i >= 0; i--) ans += na[i] + '0';

	return ans;
}

int main() {
	string s, res;
	vector<int> counts, countres;
	counts.assign(22, 0);
	countres.assign(22, 0);

	cin >> s;
	res = add(s, s);

	for (int i = 0; i < s.size(); i++) {
		counts[s[i] - '0']++;
		countres[res[i] - '0']++;
	}
	int flag = 1;
	for (int i = 0; i < 10; i++) {
		if (counts[i] != countres[i]) {
			flag = 0;
			break;
		}
	}
	if (flag == 0)printf("No\n");
	else printf("Yes\n");
	cout << res << endl;
	return 0;
}

