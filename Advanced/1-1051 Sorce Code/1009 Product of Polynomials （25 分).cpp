#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

struct Poly {
	double exp; // 指数
	double coef; // 系数
};

vector <Poly> A, B, res;

bool cmp(Poly a, Poly b) {
	return a.exp > b.exp;
}

int main() {
	int N, M;
	Poly tmp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp.exp >> tmp.coef;
		A.push_back(tmp);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp.exp >> tmp.coef;
		B.push_back(tmp);
	}

	// mul
	int flag;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp.exp = A[i].exp + B[j].exp;
			tmp.coef = A[i].coef * B[j].coef;
			// 寻找同类项
			flag = 0;
			for (int k = 0; k < res.size(); k++) {
				if (res[k].exp == tmp.exp) {
					res[k].coef += tmp.coef;
					flag = 1;
					break;
				}
			}
			if (!flag) res.push_back(tmp);
		}
	}

	int count = 0;
	for (int i = 0; i < res.size(); i++) {
		if (res[i].coef != 0.0) count++;
	}
	sort(res.begin(), res.end(), cmp);
	cout << count;
	for (int i = 0; i < res.size(); i++) {
		if (res[i].coef == 0) continue;
		cout << " " << fixed << setprecision(0) << res[i].exp << " " << fixed << setprecision(1) << res[i].coef;
	}
	cout << endl;

	return 0;
}

