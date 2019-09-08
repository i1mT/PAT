#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <sstream>

using namespace std;

int n, minn, maxn;

struct Stu {
	string name, id;
	int grade;
};

vector<Stu> list;

bool cmp (Stu a, Stu b) {
	if (a.grade > maxn || a.grade < minn) {
		return false;
	}
	if (b.grade > maxn || b.grade < minn) {
		return true;
	}
	return a.grade > b.grade;
}

int main () {
	scanf("%d", &n);

	Stu stu;

	ios::sync_with_stdio(false);

	for(int i = 0; i < n; i++) {
		cin >> stu.name >> stu.id >> stu.grade;

		list.push_back(stu);
	}

	cin >> minn >> maxn;

	sort(list.begin(), list.end(), cmp);


	int cnt = 0;

	for(int i = 0; i < list.size(); i++) {
		if (list[i].grade > maxn || list[i].grade < minn) break;

		printf("%s %s\n", list[i].name.c_str(), list[i].id.c_str());
		cnt++;
	}

	if (!cnt) printf("NONE\n");

	return 0;
}
