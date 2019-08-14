#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

int main() {
	int N;
	cin >> N;
	int temp = 0;
	int left = 0;
	int templeft, right, tmp;
	int sum = -1; // 防止最大和是0的情况
	vector <int> A;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		A.push_back(tmp);
		temp += tmp;

		if (temp < 0) {
			temp = 0;
			templeft = i + 1;
		} else if (temp > sum) {
			sum = temp;
			right = i;
			left = templeft;
		}
	}

	if (sum < 0) {
		cout << 0 << " " << A[0] << " " << A[N - 1] << endl;
	} else {
		cout << sum << " " << A[left] << " " << A[right] << endl;
	}

	return 0;
}
