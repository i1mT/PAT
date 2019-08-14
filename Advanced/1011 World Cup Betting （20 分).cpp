#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

double Scale_4(double argu, double accu) {
	double size = pow(10, accu);
    return floor(argu*size + 0.5) / size;
}

int main () {
	double A[3][3];
	for (int i = 0; i < 3; ++i) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	}
	int res[3];
	int temp;
	double sum = 1;
	for (int i = 0; i < 3; ++i) {
		temp = 0;
		
		for (int j = 1; j < 3; j++) {
			if (A[i][j] > A[i][temp]) {
				temp = j;
			}
		}
		res[i] = temp;
		sum *= A[i][temp];
	}
	sum *= 0.65;
	sum = (sum - 1) * 2;
	for (int i = 0; i < 3; ++i) {
		if (i != 0) cout << " ";
		
		if (res[i] == 0) cout << "W";
		if (res[i] == 1) cout << "T";
		if (res[i] == 2) cout << "L";
	}
	cout << " " << fixed << setprecision(2) << Scale_4(sum, 2);
	return 0;
}

