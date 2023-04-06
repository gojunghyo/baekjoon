//
// Created by MZ01-GOJGHO on 2023/04/06.
//

#include <iostream>
#include <algorithm>

using namespace std;
int n,m, ret=1e9;
char arr[54][54];
char white_arr[8][8] = {
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W'
};

char black_arr[8][8] = {
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B'
};

int white_cnt (int y, int x) {
    int result = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[y+i][x+j] != white_arr[i][j]) result++;
        }
    }

    return result;
}

int black_cnt (int y, int x) {
    int result = 0;

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[y+i][x+j] != black_arr[i][j]) result++;
        }
    }
    return result;
}


int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int ret_white, ret_black;
    int mx = 1e9;
    for(int i=0; i<=n - 8; i++){
        for(int j=0; j<=m - 8; j++){
            ret_white = white_cnt(i,j);
            ret_black = black_cnt(i,j);
            mx = min(ret_white, ret_black);
            ret = min(ret, mx);
        }
    }

    cout << ret;



}