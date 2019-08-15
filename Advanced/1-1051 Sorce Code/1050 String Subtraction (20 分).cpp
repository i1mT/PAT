#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;


int asc[99999];


int main () {
	string s1, s2;

	getline(cin, s2);
	getline(cin, s1);
	

	// s2 - s1

	for(int i = 0; i < s1.size(); i++) {
		asc[int(s1[i])] = 1;
	}

	for(int i = 0; i < s2.size(); i++) {
		if (asc[int(s2[i])] == 0) {
			printf("%c", s2[i]);
		}
	}
	printf("\n");

	return 0;
}
