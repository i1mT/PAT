#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
思路



*/
string int2string(int num);

int main(){
    int A,B;

    cin >> A >> B;

    int result = A+B;
    string res = int2string(result);
    string negative = "";
    if(res[0] == '-') {
        negative = "-";
        res = res.substr(1);
    }

    if(abs(result) < 1000) {
        res = negative + res;
        cout << res << endl;
        return 0;
    }
    int cnt = 0;
    int time = 0;
    for(int i = res.size() - 1; i >= 0; i--) {
        if(cnt %3 == 0 && cnt != 0) {
            string pre = res.substr(0, res.size() - (cnt + time));
            string sub = res.substr(res.size() - (cnt + time));

            if(pre.size() > 0)
                sub = "," + sub;
            res = pre + sub;
            time++;
        }
        cnt++;
    }
    res = negative + res;
    cout << res << endl;
    return 0;
}

string int2string(int num) {
    if(num == 0) return "0";

    int backup = num;
    string s = "";
    int temp;
    num = abs(num);

    while(num) {
        temp = num%10;
        num /= 10;
        s = "0" + s;
        s[0] = '0' + temp;
    }

    if(backup < 0)
        s = "-" + s;
    return s;
}