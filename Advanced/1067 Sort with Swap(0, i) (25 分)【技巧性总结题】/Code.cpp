#include <iostream>
#include <strstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <cstring>

using namespace std;

vector<int> nums;

/*
解析:
	1. 使用nums[t]=i表示数字t占着i的位置
	2. 使i从1开始循环，如果nums[i]!=i，就交换nums[0]与nums[nums[0]]，直到nums[0]=0
	3. 如果nums[i]依然没有归位，将0与该位置的数字互换，继续循环
*/

int main () {
	int n, tmp, ans = 0;
	cin >> n;
	nums.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		nums[tmp] = i;
	}

	for(int i = 0; i < n; i++) {
		if(nums[i]!=i) {
			while(nums[0]!=0) {
				swap(nums[0], nums[nums[0]]);
				ans++;
			}

			if(nums[i]!=i) {
				swap(nums[0], nums[i]);
				ans++;
			}
		}
	}

	printf("%d", ans);

	return 0;
}
