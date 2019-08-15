#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

int main () {
	int N, sum = 0, from = 0, to;
	cin >> N;
	while (N--) {
		cin >> to;
		if (from > to) {
			sum += 4 * (from - to);
		} else {
			sum += 6 * (to - from);
		}
		sum += 5;
		from = to;
	}
	cout << sum << endl;
	return 0;
}

