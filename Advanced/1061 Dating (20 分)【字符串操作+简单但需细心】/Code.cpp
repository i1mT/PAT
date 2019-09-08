#include <iostream>
#include <strstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main () {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	int m, index;
	char day, h;
	int l = min(a.size(), b.size());
	for(int i = 0; i < l; i++) {
		if(a[i] == b [i] && (a[i] >= 'A' && a[i] <= 'G')) {
				day = a[i];
				index = i;
				break;
		}
	}

	for(int i = index + 1; i < l; i++) {
		if(a[i] == b [i]) {
			if((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i])) {
				h = a[i];
				break;
			}
		}
	}


	int len = min(d.size(), c.size());
	for (int i = 0; i < len; i++) {
		if (c[i] == d[i] && isalpha(c[i])) {
			m = i;
			break;
		}
	}

	int hh = isdigit(h) ? h-'0' : h-'A'+10;

	cout<< week[day-'A'];
	printf(" %02d:%02d", hh, m);



	return 0;
}
