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
	string in;
	string out;
};

int M;
vector <Record> rec_in, rec_out;

bool cmp_in(Record a, Record b) {
	return a.in < b.in;
}

bool cmp_out(Record a, Record b) {
	return a.out > b.out;
}

void solve() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		Record tmp;
		cin >> tmp.id >> tmp.in >> tmp.out;
		rec_in.push_back(tmp);
		rec_out.push_back(tmp);
	}

	sort(rec_in.begin(), rec_in.end(), cmp_in);
	sort(rec_out.begin(), rec_out.end(), cmp_out);

	cout << rec_in[0].id << " " << rec_out[0].id << endl;
}

int main() {
	solve();
	return 0;
}

