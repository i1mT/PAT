#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <sstream>

// -123456789	Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
// 100800		yi Shi Wan ling ba Bai

using namespace std;

string snum[10] = {"", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string step[9] = {"" ,"Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};

int main () {
	string str;
	cin >> str;
	
	vector<string> res;

	for(int i = str.size()-1, k = 0; i >= 0; i--, k++) {
		if (str[i] == '0') {
			if (k == 4) {
				string s = str.substr(0, i-1);
				int n = abs(stoi(s));

				if(n%10000) {
					res.push_back("Wan");
				}
			}

			if (res.empty() || res[res.size()-1] == "ling" || res[res.size()-1] == "Wan") continue;

			res.push_back("ling");
			continue;
		}

		if (str[i] == '-') {
			res.push_back("Fu");
			break;
		}

		if (k)
			res.push_back(step[k]);

		res.push_back(snum[str[i] - '0']);
	}

	for(int i = res.size() - 1; i >=0; i--) {
		if (i != res.size() - 1) printf(" ");
		cout << res[i];
	}
	if (res.size() == 0) cout << "ling";
	cout << endl;

	return 0;
}
