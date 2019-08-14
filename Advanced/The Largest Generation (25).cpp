#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <list>

#define MAX_LEN 100

using namespace std;

int tree[100][100];

int input(string num) {
  int res = 0, i = 1;
  for(int j = num.size() - 1; j >= 0; j--) {
    res += (num[j] - '0') * i;
    i *= 10;
  }
  return res;
}

void solve() {
  int N, M, par, childNum;
  string tmp;
  cin >> N >> M;
  //input
  for(int i = 0; i < M; i++) {
    cin >> par >> childNum;
    for(int j = 0; j < childNum; j++) {
      cin >> tmp;
      tree[par][j] = input(tmp);
    }
  }
  //calc
  int level, max = 0, tmpCnt,curPopulation, curMember, curLevel = 1;
  queue<int> q, tmpq;
  tmpCnt = 0;
  q.push(1);
  while(q.size()) {
    curPopulation = q.size();
    //cout << "level: " << curPopulation << endl;
    if(max < curPopulation) {
      level = curLevel;
      max   = curPopulation;
    }
    for(int i = 0; i < curPopulation; i++) {
      curMember = q.front();
      //cout << curMember << " ";
      q.pop();
      for(int j = 0; j < MAX_LEN; j++) { //push the child to another queue
        if(tree[curMember][j] != 0) {
          tmpq.push(tree[curMember][j]);
        }
      }
    }
    //cout << endl;
    while(tmpq.size()) { //let q is the next generation queue
      curMember = tmpq.front();
      q.push(curMember);
      tmpq.pop();
    }
    curLevel++;
  }

  cout << max << " " << level << endl;
}

int main() {
  solve();
  return 0;
}