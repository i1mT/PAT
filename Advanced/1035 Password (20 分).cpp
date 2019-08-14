#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

using namespace std;

struct User {
	string name;
	string pwd;
	int mdf;
};

int modify (string &s) {
	string st = s;
	for(int i = 0; i < s.size(); i++) {
		if (s[i] == '1') s[i] = '@';
		if (s[i] == '0') s[i] = '%';
		if (s[i] == 'l') s[i] = 'L';
		if (s[i] == 'O') s[i] = 'o';
	}

	if(st != s) return 1;
	return 0;
}

int main () {
	
	int N, sum = 0;
	User u;
	vector<User> users;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> u.name >> u.pwd;
		u.mdf = modify(u.pwd);
		if (u.mdf == 1) sum++;
		users.push_back(u);
	}

	if (sum == 0) {
		if (N == 1) {
			printf("There is 1 account and no account is modified\n");

			return 0;
		} else {
			printf("There are %d accounts and no account is modified\n", N);
			
			return 0;
		}
	} else {
		printf("%d\n", sum);
		for(int i = 0; i < users.size(); i++) {
			if (users[i].mdf == 1) {
				cout << users[i].name << " " << users[i].pwd << endl;
			}
		}
	}

	return 0;
}
