#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <list>
#include <stack>
#include <vector>

using namespace std;

struct Record
{
	string plate;
	int time;
	int status;
};

vector<Record> record;
vector<Record> cars;
vector<string> llist;
vector<string> keys;
map<string, int> keep;

int string2seconds(string t)
{
	int seconds = 0;
	string hours = t.substr(0, 2);
	string minutes = t.substr(3, 2);
	string second = t.substr(6);
	int tmp, jin;
	tmp = 0;
	jin = 1;
	for (int i = 1; i >= 0; i--)
	{
		tmp += (hours[i] - '0') * jin;
		jin *= 10;
	}
	seconds += 3600 * tmp;
	tmp = 0;
	jin = 1;
	for (int i = 1; i >= 0; i--)
	{
		tmp += (minutes[i] - '0') * jin;
		jin *= 10;
	}
	seconds += 60 * tmp;
	tmp = 0;
	jin = 1;
	for (int i = 1; i >= 0; i--)
	{
		tmp += (second[i] - '0') * jin;
		jin *= 10;
	}
	seconds += tmp;
	return seconds;
}

string int2string(int a)
{
	string res = "00";
	res[1] = '0' + a % 10;
	res[0] = '0' + a / 10;

	return res;
}

string second2string(int seconds)
{
	int hours = 0, minutes = 0, second = 0;
	hours = seconds / 3600;
	seconds %= 3600;
	minutes = seconds / 60;
	seconds %= 60;
	second = seconds;

	return int2string(hours) + ":" + int2string(minutes) + ":" + int2string(second);
}

bool cmpTime(string t1, string t2)
{
	return string2seconds(t1) < string2seconds(t2);
}

bool cmpByPlate(Record r1, Record r2)
{
	if (r1.plate == r2.plate)
		return r1.time < r2.time;
	return r1.plate < r2.plate;
}

bool cmpByTime(Record r1, Record r2)
{
	return r1.time < r2.time;
}

void solve()
{
	int N, K;
	string tmps;
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		Record tmp;
		cin >> tmp.plate;
		cin >> tmps;
		tmp.time = string2seconds(tmps);
		cin >> tmps;
		tmp.status = tmps == "in" ? 1 : -1;
		record.push_back(tmp);
	}
	//sort by plate first, and if plate unique by time
	sort(record.begin(), record.end(), cmpByPlate);
	//filter right record
	vector<Record>::iterator it = record.begin();
	Record temp, temp1;
	int longerst = -1;
	while (it < record.end() - 1) // N
	{
		temp = *it;
		temp1 = *(it + 1);
		if(temp.plate == temp1.plate && temp.status == 1 && temp1.status == -1) {
      //paired!
      cars.push_back(temp);
      cars.push_back(temp1);
			keep[temp.plate] += temp1.time - temp.time;
			if(longerst < keep[temp.plate]) longerst = keep[temp.plate];
      it++;
    }
		it++;
	}
	//sort by time ASC
	sort(cars.begin(), cars.end(), cmpByTime);
	vector<int> kRes(N);
	//mock parking
	for (int i = 0; i < cars.size(); i++)
	{
		if(i == 0) {
			kRes[i] = cars[i].status;
		} else {
			kRes[i] = kRes[i - 1] + cars[i].status;
		}
	}
	//input points and compute sync
	int index = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> tmps;
		int j;
		for (j = index; j < cars.size(); j++) {
			if(cars[j].time > string2seconds(tmps)) {
				cout << kRes[j - 1] << endl;
				break;
			} else if(j + 1 == cars.size()) {
				cout << kRes[j] << endl;
			}
		}
		index = j;
	}
	//find and output keep
	pair<string, int> tempp;
	map<string, int>::iterator hashit = keep.begin();
	while (hashit != keep.end())
	{
		tempp = *hashit;
		if (tempp.second == longerst)
			cout << tempp.first << " ";
		hashit++;
	}
	//output longerst
	cout << second2string(longerst) << endl;
}

int main()
{
	solve();
	return 0;
}
