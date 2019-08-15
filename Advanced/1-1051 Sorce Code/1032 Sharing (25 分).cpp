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

struct Node {
	int next;
	int c;
};

int head1, head2, N;
Node list[100000];
string s1, s2;

void getString() {
	s1 = "";
	s2 = "";
	int p = head1;
	Node n;
	while (p != -1) {
		n = list[p];
		s1 += n.c;
		p = n.next;
	}

	p = head2;
	while (p != -1) {
		n = list[p];
		s2 += n.c;
		p = n.next;
	}

}

int main() {
	scanf("%d%d%d", &head1, &head2, &N);
	Node n;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &tmp, &n.c, &n.next);

		list[tmp] = n;
	}
	getString();
	return 0;
}

