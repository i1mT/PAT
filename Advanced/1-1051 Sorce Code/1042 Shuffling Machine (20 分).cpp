#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

string d = "SHCDJ";

int deck[55];

int shf[55];

void shuffing () {
	int tmp[55];

	for(int i = 1; i <= 54; i++) {
		tmp[shf[i]] = deck[i];
	}

	for(int i = 1; i <= 54; i++) {
		deck[i] = tmp[i];
	}
}

int main () {

	int T, tmp;

	scanf("%d", &T);

	for(int i = 1; i <= 54; i++) {
		scanf("%d", &tmp);
		deck[i] = i;
		shf[i] = tmp;
	}

	for(int i = 0; i < T; i++) {
		shuffing();
	}

	for(int i = 1; i <= 54; i++) {
		if(i != 1) printf(" ");
		deck[i]--;
		printf("%c%d", d[deck[i]/13], deck[i] % 13 + 1);
	}

	return 0;
}
