#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

struct Score {
	string id;
	double score;
};

bool cmp(Score a, Score b) {
	return a.score > b.score;
}

vector<Score> A, C, M, E;
vector<string> list;

int main () {
	int N, m;
	Score tmp;
	double avg;
	cin >> N >> m;
	for (int i = 0; i < N; ++i) {
		cin >> tmp.id;
		
		cin >> tmp.score;
		avg += tmp.score;
		C.push_back(tmp);
		
		cin >> tmp.score;
		avg += tmp.score;
		M.push_back(tmp);
		
		cin >> tmp.score;
		avg += tmp.score;
		E.push_back(tmp);
		
		avg /= 3;
		tmp.score = avg;
		A.push_back(tmp);
	}
	
	// sort
	sort(A.begin(), A.end(), cmp);
	sort(C.begin(), C.end(), cmp);
	sort(M.begin(), M.end(), cmp);
	sort(E.begin(), E.end(), cmp);
	
	string ltmp;
	int best[4];
	string course = "ACME";
	bool flag_found;
	bool flag;
	int max_index;
	for (int j = 0; j < m; ++j) {
		best[0] = -1, best[1] = -1, best[2] = -1, best[3] = -1;
		cin >> ltmp;
		flag_found = false;
		for (int i = 0; i < N; i++) {
			if (A[i].id == ltmp) {
				flag_found = true;
				best[0] = i;
			}
			if (C[i].id == ltmp) {
				best[1] = i;
			}
			if (M[i].id == ltmp) {
				best[2] = i;
			}
			if (E[i].id == ltmp) {
				best[3] = i;
			}
			flag = true;
			for (int k = 0; k < 4; k++) {
				if (best[k] < 0) flag = false;
			}
			if (flag) break;
		}
		
		if (!flag_found) cout << "N/A" << endl;
		else {
			max_index = 0;
			for (int i = 1; i < 4; i++) {
				if (best[i] < best[max_index]) max_index = i;
			}
			
			cout << best[max_index] << " " << course[max_index] << endl;
		}
	}
	
	
	return 0;
}

