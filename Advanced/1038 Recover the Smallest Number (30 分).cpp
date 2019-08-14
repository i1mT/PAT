#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stack>

using namespace std;

vector<string> numbers;
int N;

bool cmp(string a, string b) {
	int index = 0;
	while (index < a.size() && index < b.size()) {
		if (a[index] < b[index]) return true;
		else if (a[index] > b[index]) return false;

		index++;
	}

	// ������ͬ
	if (a.size() == b.size()) return false;

	if (index == a.size()) {
		// a�Ƚ϶̣����b����һ�����ֱȵ�ǰ��С��ѡb
		if (b[index] <= a[0]) {
			return false;
		} else return true;

	} else {
		// b�Ƚ϶̣����a����һ�����ֱȵ�ǰ��С��ѡa
		if (a[index] <= b[0]) {
			return true;
		} else return false;
	}

}

int main () {

	string s, res = "";
	scanf("%d", &N);

	for(int i= 0; i < N; i++) {
		cin >> s;

		numbers.push_back(s);
	}

	sort(numbers.begin(), numbers.end(), cmp);


	for(int i = 0; i < numbers.size(); i++) {
		res = res + numbers[i];
	}
	int i = 0;
	while(res[0] == '0') {
		if (res == "0") {
			res = "0";
			break;
		}
		res = res.substr(1);
	}
	cout << res << endl;

	return 0;
}
