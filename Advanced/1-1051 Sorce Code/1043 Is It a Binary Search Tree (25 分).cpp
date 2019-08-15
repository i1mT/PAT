#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

vector<int> seq;
vector<int> preSeq;
vector<int> mPreSeq;
int cnt = 0;

struct Node {
	int data;
	Node* lchild;
	Node* rchild;
};

Node* getNewNode() {
	Node *n = new Node;
	n->rchild = NULL;
	n->lchild = NULL;

	return n;
}


void cmp (int a, int b) {

}

void preOrder(Node *r, vector<int> &s) {
	if (r == NULL) return;

	s.push_back(r->data);

	preOrder(r->lchild, s);
	preOrder(r->rchild, s);
}

void postOrder(Node *r) {
	if (r == NULL) return;

	postOrder(r->lchild);
	postOrder(r->rchild);

	if (cnt == 0) {
		cnt++;
	} else {
		printf(" ");
	}
	printf("%d", r->data);
}

int main () {

	int N,tmp, first, type = 1; // type: 1 BST, 2 mBST, -1 None
	Node *root, *tmpNode, *p;
	Node *mirrorRoot, *mp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
		if (i == 0) {
			root = getNewNode();
			mirrorRoot = getNewNode();
			root->data = tmp;
			mirrorRoot->data = tmp;
			continue;
		}

		tmpNode = getNewNode();
		tmpNode->data = tmp;
		
		// build BST
		p = root;
		while (1) {
			if (tmp >= p->data) {
				if (p->rchild == NULL) {
					Node *_tmpNode = getNewNode();
					_tmpNode->data = tmpNode->data;
					p->rchild = _tmpNode;
					break;
				}
				p = p->rchild;
				
			} else {
				if (p->lchild == NULL) {
					Node *_tmpNode = getNewNode();
					_tmpNode->data = tmpNode->data;
					p->lchild = _tmpNode;
					break;
				}
				p = p->lchild;
			}
		}

		// build mirror BST
		mp = mirrorRoot;
		while (1) {
			if (tmp < mp->data) {
				if (mp->rchild == NULL) {
					Node *_tmpNode = getNewNode();
					_tmpNode->data = tmpNode->data;
					mp->rchild = _tmpNode;
					break;
				}
				mp = mp->rchild;
				
			} else {
				if (mp->lchild == NULL) {
					Node *_tmpNode = getNewNode();
					_tmpNode->data = tmpNode->data;
					mp->lchild = _tmpNode;
					break;
				}
				mp = mp->lchild;
			}
		}
	}

	preOrder(root, preSeq);
	preOrder(mirrorRoot, mPreSeq);

	for (int i = 0; i < N; i++) {
		if (seq[i] != preSeq[i]) {
			type = -1;
			break;
		}
	}

	if (type == 1) {
		// BST
		printf("YES\n");
		postOrder(root);

		return 0;
	}

	type = 2;
	for (int i = 0; i < N; i++) {
		if (seq[i] != mPreSeq[i]) {
			type = -1;
			break;
		}
	}

	if (type == 2) {
		// mBST
		printf("YES\n");
		postOrder(mirrorRoot);
	} else {
		// None
		printf("NO");
	}

	return 0;
}
