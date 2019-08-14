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

struct Stu{
	int id;
	string name;
	int grade;
};

bool cmp1(Stu a, Stu b) {
	return a.id < b.id;
}

bool cmp2(Stu a, Stu b) {
	if (a.name != b.name) return a.name < b.name;
	return a.id < b.id;
}

bool cmp3(Stu a, Stu b) {
	if (a.grade != b.grade) return a.grade < b.grade;
	return a.id < b.id;
}

int main() {
	int N, C;
	vector<Stu> list;
	Stu tmp;
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++) {
		cin >> tmp.id >> tmp.name >> tmp.grade;
		list.push_back(tmp);
	}
	switch (C) {
		case 1: 
			sort(list.begin(), list.end(), cmp1);
			break;
		case 2:
			sort(list.begin(), list.end(), cmp2);
			break;
		case 3:
			sort(list.begin(), list.end(), cmp3);
			break;
	}
	for (int i = 0; i < list.size(); i++) {
		printf("%06d ", list[i].id);
		cout << list[i].name;
		printf(" %d\n", list[i].grade);
	}
	return 0;
}
