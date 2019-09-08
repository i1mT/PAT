#include<iostream>
#include<stack> 
#include<vector> 
using namespace std;

// 判断入栈序列为a[]的情况下，出栈序列b[]是否合法
bool check(vector<int> a, vector<int> b) {
	int index = 0;// 记录出栈
	stack<int> s;
	
	for(int i = 0; i < a.size(); i++) {
		s.push(a[i]);
		
		while(!s.empty() && s.top() == b[index]) {
			index++;
			s.pop();
		}
	}
	
	return s.size() == 0 ? true:false;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        vector<int> in, out;
        cin >> n;
        in.resize(n), out.resize(n);

        for(int i = 0; i < n; i++) {
            cin >> in[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> out[i];
        }
        bool flag = check(in, out);
        if (flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }


    return 0;
}
