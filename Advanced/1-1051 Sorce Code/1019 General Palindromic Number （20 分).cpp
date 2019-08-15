#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

int num, base;
vector<int> baseNum;

int main() {
	int temp, tmp;
	scanf("%d%d", &num, &base);
	temp = num;
	// ½øÖÆ×ª»»
	while (temp != 0) {
		tmp = temp % base;
		temp /= base;
		baseNum.push_back(tmp);
	}
	bool flag = true;
	for (int i = 0; i < baseNum.size() / 2; i++) {
		if (baseNum[i] != baseNum[baseNum.size() - 1 - i]) {
			flag = false;
			break;
		}
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
	for (int i = baseNum.size() - 1; i >= 0; i--) {
		if (i != baseNum.size() - 1) printf(" ");
		printf("%d", baseNum[i]);
	}
	return 0;
}

