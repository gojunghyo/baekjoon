//
// Created by MZ01-GOJGHO on 2023/04/06.
//

#include <iostream>

using namespace std;
int n,ret,cnt;

int main() {

   cin >> n;
    ret = 0;
    cnt = 0;

    while(cnt != n){
        ret++;
        int tmp = ret;

        while(tmp != 0){
            if(tmp % 1000 == 666){
                cnt++;
                break;
            }else tmp/=10;
        }
    }
    cout << ret;

}