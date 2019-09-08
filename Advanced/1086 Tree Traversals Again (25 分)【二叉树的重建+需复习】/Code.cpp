#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <sstream>

using namespace std;

struct Node {
	int data;
	Node *lchild, *rchild;

	Node () {
		lchild = NULL;
		rchild = NULL;
	}
};

int n, cnt = 0, cur = 0;
vector<int> pre, mid;
stack<int> stk;

Node *root = new Node;

int findRootIndex(int num) {
	for(int i = 0; i < n; i++) {
		if (mid[i] == num) return i;
	}

	return -1;
}

// 使用先序序列与中序序列重建二叉树到根root上
Node* createTree(int left, int right) {
	if (left > right) return NULL;

	int rt = pre[cur];
	cur++;

	int rtIndex = findRootIndex(rt);

	Node *t = new Node;
	t->data = rt;

	if(left != right) {
		t->lchild = createTree(left, rtIndex - 1);
		t->rchild = createTree(rtIndex+1, right);
	}

	return t;
}

void postPrint(Node *r) {
	if (r == NULL) return;

	postPrint(r->lchild);

	postPrint(r->rchild);

	if (cnt != 0) printf(" ");
	if (cnt == 0) cnt = 1;

	printf("%d", r->data);
}

int main () {
	scanf("%d", &n);

	string s;
	int tmp;
	ios::sync_with_stdio(false);

	for(int i = 0; i < n*2; i++) {
		cin >> s;
		if (s[1] == 'u') {
			cin >> tmp;
			// push
			stk.push(tmp);
			pre.push_back(tmp);
		} else {
			// pop
			mid.push_back(stk.top());
			stk.pop();
		}
	}

	root = createTree(0, n-1);
	postPrint(root);
	return 0;
}
