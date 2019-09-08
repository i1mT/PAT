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

vector<int> list1;
int N, M;

int main() {
	int tmp;
	int mid, count = 0, pos1 = 0, pos2 = 0;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		list1.push_back(tmp);
	}
	list1.push_back(0x7fffffff);
	scanf("%d", &M);
	mid = (M + N + 1) / 2;
	
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		
		while (tmp > list1[pos1]) {
			count++;
			if (count == mid) printf("%d", list1[pos1]);
			pos1++;
		}

		count++;
		if (count == mid) printf("%d", tmp);
	}

	while (count < mid) {
		count++;
		if (count == mid) printf("%d", list1[pos1]);
		pos1++;
	}
	
	return 0;
}

