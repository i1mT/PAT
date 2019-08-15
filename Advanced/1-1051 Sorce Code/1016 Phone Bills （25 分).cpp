#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

struct Record {
	string id;
	int month, day, hour, minute;
	string type;
	bool visited;

	void show();
};

struct RTime {
	int smonth, sday, shour, sminute;
	int emonth, eday, ehour, eminute;
	int spend;
	int charge;
};

struct Bill {
	string id;
	int month;
	vector<RTime> timelist;
	int totalTime;
	double charge;

	void calCharge();
	void show();
};

vector<int> toll;
int N;
vector<Record> oriList;
vector<Bill> BList;


void Bill::calCharge() {
	int totalTS, totalTE, totalS, totalE;
	int t24 = 0;
	for (int i = 0; i < 24; i++) {
		t24 += toll[i] * 60;
	}
	for (int i = 0; i < timelist.size(); i++) {

		totalS = t24 * timelist[i].sday;
		totalTS = 24 * 60 * timelist[i].sday;

		totalE = t24 * timelist[i].eday;
		totalTE = 24 * 60 * timelist[i].eday;

		for (int j = 0; j < timelist[i].shour; j++) {
			totalS += toll[j] * 60;
			totalTS += 60;
		}
		totalS += toll[timelist[i].shour] * timelist[i].sminute;
		totalTS += timelist[i].sminute;

		for (int j = 0; j < timelist[i].ehour; j++) {
			totalE += toll[j] * 60;
			totalTE += 60;
		}
		totalE += toll[timelist[i].ehour] * timelist[i].eminute;
		totalTE += timelist[i].eminute;


		timelist[i].charge = totalE - totalS;
		timelist[i].spend = totalTE - totalTS;
		totalTime += totalTE - totalTS;
		charge += totalE - totalS;
	}
}


void Bill::show() {
	cout << id << " ";
	if (month < 10) cout << "0";
	cout << month << endl;
	for (int i = 0; i < timelist.size(); i++) {
		if (timelist[i].sday < 10) cout << "0";
		cout << timelist[i].sday << ":";

		if (timelist[i].shour < 10) cout << "0";
		cout << timelist[i].shour << ":";

		if (timelist[i].sminute < 10) cout << "0";
		cout<< timelist[i].sminute;

		cout << " ";

		if (timelist[i].eday < 10) cout << "0";
		cout << timelist[i].eday << ":";
		
		if (timelist[i].ehour < 10) cout << "0";
		cout << timelist[i].ehour << ":";
		
		if (timelist[i].eminute < 10) cout << "0";
		cout << timelist[i].eminute << " ";

		cout << timelist[i].spend << " $" << fixed << setprecision(2) << timelist[i].charge/100.0 << endl;
	}

	cout << "Total amount: $" << fixed << setprecision(2) << charge/100.0 << endl;
}

void Record::show() {
	cout << id << " " << month << ":" << day << ":" << hour << ":" << minute << " " << type << endl;
}

bool cmp(Record a, Record b) {
	if (a.month != b.month) return a.month < b.month;
	if (a.day != b.day) return a.day < b.day;
	if (a.hour != b.hour) return a.hour < b.hour;
	if (a.minute != b.minute) return a.minute < b.minute;
	return true;
}

bool cmpBill(Bill a, Bill b) {
	if (a.id != b.id) return a.id < b.id;
	return a.month < b.month;

}

void input() {
	toll.assign(24, 0);
	for (int i = 0; i < toll.size(); i++) {
		cin >> toll[i];
	}
	cin >> N;
	Record tmp;
	tmp.visited = false;
	for (int i = 0; i < N; i++) {
		cin >> tmp.id;
		scanf("%d:%d:%d:%d", &tmp.month, &tmp.day, &tmp.hour, &tmp.minute);
		cin >> tmp.type;

		oriList.push_back(tmp);
	}
	sort(oriList.begin(), oriList.end(), cmp);

	/*for (int i = 0; i < N; i++) {
		oriList[i].show();
	}*/
}

void joinBList(Record on, Record off) {
	Bill btmp;
	RTime tmp;
	for (int i = 0; i < BList.size(); i++) {
		if (BList[i].id == on.id && BList[i].month == on.month) {
			tmp.smonth = on.month;
			tmp.sday = on.day;
			tmp.shour = on.hour;
			tmp.sminute = on.minute;

			tmp.emonth = off.month;
			tmp.eday = off.day;
			tmp.ehour = off.hour;
			tmp.eminute = off.minute;

			BList[i].timelist.push_back(tmp);

			return;
		}
	}
	// 没有匹配，新建Bill
	// init Bill
	btmp.id = on.id;
	btmp.totalTime = 0;
	btmp.charge = 0.0;
	btmp.month = on.month;

	tmp.smonth = on.month;
	tmp.sday = on.day;
	tmp.shour = on.hour;
	tmp.sminute = on.minute;

	tmp.emonth = off.month;
	tmp.eday = off.day;
	tmp.ehour = off.hour;
	tmp.eminute = off.minute;

	btmp.timelist.push_back(tmp);
	BList.push_back(btmp);
}


void getBList () {
	Record tmp;
	
	int index;
	while (1) {
		tmp.month = -1;

		// 寻找一个没有被visited过的记录
		for (int i = 0; i < N; i++) {
			// 不找被visited的，和off的
			if (!oriList[i].visited && oriList[i].type == "on-line") {
				tmp = oriList[i];
				oriList[i].visited = true;
				index = i;
				break;
			}
		}

		// 均访问过
		if (tmp.month < 0) break;

		// 寻找一个匹配tmp的
		for (int i = index + 1; i < N; i++) {
			// 没访问过，且是off
			if (!oriList[i].visited && oriList[i].type == "off-line") {
				if (oriList[i].id == tmp.id) {
					// paired!
					oriList[i].visited = true;
					joinBList(tmp, oriList[i]);
					break;
				}
			}
			else if (!oriList[i].visited && oriList[i].id == tmp.id && oriList[i].type == "on-line") {
				break;
			}
		}
	}


}

int main() {
	input();
	getBList();

	for (int i = 0; i < BList.size(); i++) {
		BList[i].calCharge();
	}

	sort(BList.begin(), BList.end(), cmpBill);
	for (int i = 0; i < BList.size(); i++) {
		BList[i].show();
	}
	return 0;
}

