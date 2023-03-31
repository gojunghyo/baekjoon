//
// Created by MZ01-GOJGHO on 2023/03/31.
//


#include <iostream>

using namespace std;

int a,b,c,n;

int arr[3];
int vis[3];
bool flag = false;

void Input(){
    cin >> a >> b >> c >> n;

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

}

void Sol(int hap, int cnt){
   if(cnt > 3 || hap > n) return;
    if(hap == n) {
        flag = true;
        return;
    }
    for(int i=0; i<=n; i++){
      int add = arr[cnt] * i;
      Sol(add + hap, cnt + 1);
    }

}

int main() {
    Input();
    Sol(0,0);

    if(flag) cout << 1 << '\n';
    else cout << 0 << '\n';
}