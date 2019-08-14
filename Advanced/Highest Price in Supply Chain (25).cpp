#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip> 
#include <map>
#include <list>
#include <stack>
#include <vector>

#define MAX_LEN 100000

using namespace std;

double calc(double root, double rate, int times) {
  return root * pow(rate, times);
}

void solve() {
  int N, tmp;
  double P, r;
  vector<int> map;
  cin >> N >> P >> r;
  
  for(int i = 0; i < N; i++) {
    cin >> tmp;
    map.push_back(tmp);
  }

  //DFS
  vector<int> length;
  int longest = -1;
  vector<int>::iterator it = map.begin();
  int mark = 0;
  while(it != map.end()) {
    int cnt = 0;
    int parIndex = *it;
    if(parIndex == -1) {
      it++;
      mark++;
      continue;
    }
    //cout << mark;
    //cout << "->" << parIndex;
    while(parIndex != -1) {
      cnt++;
      parIndex = map[parIndex];
      //cout << "-> " << parIndex;
    }
    //cout << " => length: " << cnt << endl;
    length.push_back(cnt);
    if(longest < cnt) longest = cnt;
    it++;
    mark++;
  }
  //cout << "longest: " << longest << endl;
  //get longest and count num
  int times = 0;
  it = length.begin();
  while(it != length.end()) {
    if(*it == longest) times++;
    it++;
  }

  //cout << "times: " << times << endl;
  double rate = 1.00 + r/100;
  double result = calc(P, rate, longest);

  cout << setiosflags(ios::fixed) << setprecision(2) << result << " " << times << endl;
}

int main() {
  solve();
  return 0;
}