//
// Created by MZ01-GOJGHO on 2023/03/24.
//

#include <iostream>
using namespace std;

int a[1004][1004];
int n,m;
int cnt=1, num = 1;

void printA(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {

    cin >> n >> m;
    int dir = 0;
    int y = n/2;
    int x = n/2;
    a[y][x] = 1;
    //dir = 0 위 , dir = 1 앞  , dir = 2 , 아래 dir = 3 이면 뒤
    while(cnt < n * n) {
        if(dir == 0) {
            for(int i=0; i<num; i++){
                a[--y][x] = ++cnt;
                if(cnt == n*n) break;
            }
        }else if(dir == 1) {
            for(int i=0; i<num; i++){
                a[y][++x] = ++cnt;
            }
            num++;
        }else if(dir == 2) {
            for(int i=0; i<num; i++){
                a[++y][x] = ++cnt;
            }
        } else if(dir == 3){
            for(int i=0; i<num; i++){
                a[y][--x] = ++cnt;
            }
            num++;
        }

        dir = (dir + 1) % 4; // 0, 1, 2, 3,
    }

    printA();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == m) {
                cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }

}