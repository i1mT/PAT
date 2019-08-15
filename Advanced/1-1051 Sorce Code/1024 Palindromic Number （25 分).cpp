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

const int MAXSIZE = 100;
string num, revnum;
int N;

string add (string a, string b) {
	string ans;
	int na[MAXSIZE] = {0}, nb[MAXSIZE] = {0};
	int la = a.size(), lb = b.size();
	
	for (int i = 0; i < la; i++) na[la - i - 1] = a[i] - '0';
	for (int i = 0; i < lb; i++) nb[lb - i - 1] = b[i] - '0';
	
	int lmax = la > lb ? la : lb;
	
	for (int i = 0; i < lmax; i++) {
		na[i] += nb[i];
		na[i+1] += na[i] / 10;
		na[i] %= 10;
	}
	
	if(na[lmax]) lmax++;
	
	for (int i = lmax - 1; i >= 0; i--) ans += na[i] + '0';
	
	return ans;
}

string rev (string a) {
	string res="";
	for (int i = a.size() - 1; i >= 0; i--) {
		res = res + a[i];
	}
	return res;
}

bool isPal(string a) {
	for (int i = 0; i < a.size()/2; i++) {
		if (a[i] != a[a.size() - 1 - i]) return false;
	}
	return true;
}

void solve() {
	int index = 0;
	
	while(1) {
		if (isPal(num)) {
			cout << num << endl << index << endl;
			return;
		} else if (index == N) {
			cout << num << endl << index << endl;
			return;
		}
		revnum = rev(num);
		num = add(num, revnum);
		index++;
	}
	
}

int main () {
	cin >> num >> N;
	solve();
	return 0;
}

