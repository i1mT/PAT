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

struct Stu {
	string id;
	string name;
	int grade;
};

int N;
vector<Stu> maleList;
vector<Stu> famelList;

bool cmp1(Stu a, Stu b) {
	return a.grade > b.grade;
}

bool cmp2(Stu a, Stu b) {
	return a.grade < b.grade;
}

int main() {
	cin >> N;
	string gender;
	Stu u;
	for (int i = 0; i < N; i++) {
		cin >> u.name >> gender >> u.id >> u.grade;

		if (gender == "F") {
			famelList.push_back(u);
		}
		else {
			maleList.push_back(u);
		}
	}

	sort(famelList.begin(), famelList.end(), cmp1);
	sort(maleList.begin(), maleList.end(), cmp2);

	if (famelList.size() == 0) printf("Absent\n");
	else {
		cout << famelList[0].name << " " << famelList[0].id << endl;
	}
	if (maleList.size() == 0) printf("Absent\n");
	else {
		cout << maleList[0].name << " " << maleList[0].id << endl;
	}
	if (maleList.size() == 0 || famelList.size() == 0) printf("NA");
	else
		printf("%d", abs(maleList[0].grade - famelList[0].grade));
	return 0;
}
