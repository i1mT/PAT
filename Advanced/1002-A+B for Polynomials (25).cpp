#include <iostream>
#include <string>
#include<iomanip> //accurate decimal

using namespace std;

/**
输入两行
每行第一个 有几项 后面 指数 系数对应为一项
思路



*/

int getlength(double A[][2]) {
    return (sizeof(A) / sizeof(A[0]));
}

string doubleToString(double num) {
    char str[16]; //16 is double length
    sprintf(str, "%lf", num);
    string result = str;
    return result;
}

string getAccurateNum(double num, int accurate) {
    string res = doubleToString(num);
    int i;
    for(i = 0; i < res.size(); i++){  
        if(res[i] == '.')
            return res.substr(0, i + 1 + accurate);
    }
}

int main(){
    double A[10][2], B[10][2], RES[20][2];
    int N_A, N_B, i, j;
    //init RES
    for(i = 0; i < 20; i++){
        RES[i][0] = 0;
        RES[i][1] = 0;
    }

    cin >> N_A;
    for(i = 0; i < N_A; i++){
       cin >> A[i][0] >> A[i][1]; 
    }
    cin >> N_B;
    for(i = 0; i < N_B; i++){
       cin >> B[i][0] >> B[i][1]; 
    }
    int A_step = 0, B_step = 0, RES_step = 0;
    double polynomial[2];
    for(i = 0; i < N_A + N_B; i++){
        if(A_step >= N_A) {
            polynomial[0] = B[B_step][0];
            polynomial[1] = B[B_step++][1];
        } else if (B_step >= N_B){
            polynomial[0] = A[A_step][0];
            polynomial[1] = A[A_step++][1];
        } else if(A[A_step][0] < B[B_step][0]) {
            polynomial[0] = B[B_step][0];
            polynomial[1] = B[B_step++][1];
        } else {
            polynomial[0] = A[A_step][0];
            polynomial[1] = A[A_step++][1];
        }

        //cout << "poly: " << polynomial[0] << "--" << polynomial[1] << endl;

        //循环查找RES 在RES中添加
        for(j = 0; j < 20 ; j++) {
            if(RES[j][0] == polynomial[0])
                break;
        }
        if(j < 20){
            //found!
            RES[j][1] += polynomial[1];
        } else {
            //new polynomial
            RES[RES_step][0] = polynomial[0];
            RES[RES_step][1] = polynomial[1];
            RES_step++;
        }
    }

    //count
    int cnt = 0;
    int empty_item = 0;
    for(i = 0; i < 20; i++){
        
        if(RES[i][0] == 0 && RES[i][1] == 0)
            break;
        if(RES[i][1] == 0.0)
            empty_item++;
        cnt++;
    }
    //output
    cout << cnt - empty_item;
    double dou_n, dou_k;
    int n, k;
    for(i = 0; i < cnt; i++) {
        if(RES[i][1] == 0.0)
            continue;
        
        cout << " " << int(RES[i][0]) << " " << setiosflags(ios::fixed) << setprecision(1) << RES[i][1] << setiosflags(ios::fixed);
    }
    cout << endl;
    return 0;
}
