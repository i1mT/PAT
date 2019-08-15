/**
统计每个级叶子节点的个数
Sample Input
2 1   (共有2个节点，一个非叶子节点)
01 1 02  (非叶子节�?1，共�?个子节点，后面是所有子节点的编�?

Sample Output
0 1 (�?级，其中第一级有0个叶子节点，二级�?个叶子节�?
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#define MAX_LEN 101

using namespace std;

vector< vector<int> > tree(MAX_LEN);
vector<int> levels(MAX_LEN);
int MAX_LEVEL = 0;

int string2int(string s) {
  int res = 0, c = 1;
  
  for(int i = s.size() - 1; i >= 0; i--) {
    res += (s[i] - '0') * c;
    c   *= 10;
  }
  return res;
}

void dfs(int id, int l) {
  MAX_LEVEL = max(l, MAX_LEVEL);
  if(tree[id].empty()) {
    ++levels[l];
    return;
  }
  
  for(int i = 0; i < tree[id].size(); i++) {
    dfs(tree[id][i], l + 1);
  }
}

void solve() {
  //input
  int N, M, ID, K, childID;
  string temp = "";
  scanf("%d%d", &N, &M);
  //printf("N=%d, M=%d\n", N, M);
  for(int i = 0; i < M; i++) {
    cin >> temp >> K;
    ID = string2int(temp);
    //printf("ID=%d\n", ID);
    while(K--) {
      cin >> temp;
      childID = string2int(temp);
      //printf("childID=%d\n", childID);
      tree[ID].push_back(childID);
    }
  }
  //printf("dfs");
  //dfs
  fill(levels.begin(), levels.end(), 0);
  dfs(1, 0);
  
  //output
  for(int i = 0; i < MAX_LEVEL; i++) {
    printf("%d ", levels[i]);
  }
  printf("%d\n", levels[MAX_LEVEL]);
  return;
}

int main() {
    solve();
    return 0;
}
