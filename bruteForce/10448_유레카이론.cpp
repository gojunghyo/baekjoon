//
// Created by MZ01-GOJGHO on 2023/03/29.
//

#include <iostream>

using namespace std;
int n;
int dp[1004];
bool ch = false;
void Sol(int num, int hap, int cnt){
    if(hap > num) return;
    if(cnt == 3) {
        if(num == hap) ch = true;
//        cout << hap << '\n';
        return;
    }

    for(int i=1; i<50; i++){
        int add = hap;
        Sol(num, add + dp[i], cnt + 1);
    }
}
int main() {

    for(int i=1; i<=1000; i++){
        dp[i] = i*(i+1)/2;
//        cout << dp[i] << ' ';
    }

    cin >> n;

    while(n--){
        int a;
        cin >> a;
        ch = false;
        Sol(a,0, 0);
        if(ch) {
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }
}