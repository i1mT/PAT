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

struct People {
	string id;
	int virtue;
	int talent;
	int cls;
	int total;
};

int n, h, l;
vector<People> list;

int cls (People p) {
	if (p.talent >= h && p.virtue >= h) {
		return 4;
	} else if (p.talent < h && p.virtue >= h) {
		return 3;
	} else if (p.talent <h && p.virtue < h && p.virtue >= p.talent) {
		return 2;
	} else {
		return 1;
	}
}

bool cmp (People p1, People p2) {
	if (p1.cls != p2.cls) {
		return p1.cls > p2.cls;
	} else {
		if (p1.total != p2.total) return p1.total > p2.total;
		else {
			if (p1.virtue != p2.virtue) return p1.virtue > p2.virtue;
			else {
				return p1.id < p2.id;
			}
		}
	}
}

int main () {
	

	scanf("%d%d%d", &n, &l, &h);

	People p;
	p.id.resize(8);

	for(int i = 0; i < n; i++) {
		scanf("%s%d%d", &p.id[0], &p.virtue, &p.talent);
		if (p.virtue >= l && p.talent >= l) {
			p.cls = cls(p);
			p.total = p.virtue + p.talent;
			list.push_back(p);
		}
	}

	sort(list.begin(), list.end(), cmp);

	printf("%d\n", list.size());
	for(int i = 0; i < list.size(); i++) {
		printf("%s %d %d\n", list[i].id.c_str(), list[i].virtue, list[i].talent);
	}
	
	return 0;
}
