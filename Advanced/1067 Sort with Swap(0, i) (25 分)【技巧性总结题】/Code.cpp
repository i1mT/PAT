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
����:
	1. ʹ��nums[t]=i��ʾ����tռ��i��λ��
	2. ʹi��1��ʼѭ�������nums[i]!=i���ͽ���nums[0]��nums[nums[0]]��ֱ��nums[0]=0
	3. ���nums[i]��Ȼû�й�λ����0���λ�õ����ֻ���������ѭ��
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
