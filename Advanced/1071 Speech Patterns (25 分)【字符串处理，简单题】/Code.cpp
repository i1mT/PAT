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
