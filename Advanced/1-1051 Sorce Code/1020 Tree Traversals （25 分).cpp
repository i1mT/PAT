#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm> 

using namespace std;

struct TreeNode {
	int data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
};


int N;
vector<int> postorder;
vector<int> inorder;
TreeNode *root = new TreeNode;


void getTree(vector<int> post, vector<int> in, TreeNode* node) {
	vector<int> inleft, inright;
	vector<int> postleft, postright;
	if (post.size() == 0) return;
	int rootNum = post[post.size() - 1];
	post.pop_back();
	node->data = rootNum;
	// 将中序遍历拆开
	bool flag = false;
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == rootNum) {
			flag = true;
			continue;
		}
		if (!flag)
			inleft.push_back(in[i]);
		else
			inright.push_back(in[i]);
	}
	// 将后序遍历拆开
	for (int i = 0; i < post.size(); i++) {
		if (i < inleft.size()) {
			postleft.push_back(post[i]);
		} else {
			postright.push_back(post[i]);
		}
	}

	if (inleft.size() > 0) {
		node->left = new TreeNode;
		getTree(postleft, inleft, node->left);
		
	}

	if (inright.size() > 0) {
		node->right = new TreeNode;
		getTree(postright, inright, node->right);
	}
}

void DFS() {
	queue<TreeNode*> ss, tmpss;
	ss.push(root);
	TreeNode* tmp;
	int cnt = 0;
	while (!ss.empty()) {
		tmp = ss.front();
		if (cnt == 0) cnt = 1;
		else printf(" ");
		printf("%d", tmp->data);
		ss.pop();

		if (tmp->left != NULL) ss.push(tmp->left);
		if (tmp->right != NULL) ss.push(tmp->right);
	}
}

int main() {
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		postorder.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		inorder.push_back(tmp);
	}

	getTree(postorder, inorder, root);

	DFS();
	return 0;
}
