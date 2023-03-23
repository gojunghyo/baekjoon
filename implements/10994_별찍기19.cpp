//
// Created by MZ01-GOJGHO on 2023/03/23.
//

#include <iostream>
using namespace std;
int n;
char arr[397][397];

void draw(int len, int row , int col){
    for(int i=0; i < len; i++){
        if(i == 0 || i == len -1) // 윗변 , 아랫변
            for(int j=0; j<len; j++) arr[row+i][col+j] = '*';
        else{
            arr[row + i][col] = '*';
            arr[row+i][col + len - 1]  = '*';
        }
    }
}

void square(int n, int row ,int col) {
    int len = 4 * n - 3;
    draw(len, row, col); // 재귀전 현재 지점 사각형 먼저 그리기

    if(n == 1) {
        return;
    }

    square(n-1, row +2, col +2);
}



int main() {
    cin >> n;

    //별찍기전에 미리 전체 배열에 공백 넣기

    for(int i=0; i<4*n-3;  i++){
        for(int j=0; j<4 * n -3; j++){
            arr[i][j] = ' ';
        }
    }

    square(n, 0, 0);  // 별찍기 가장큰 사각형부터 넘기기 사각형은 최상단

    //출력
    for(int i=0; i<4*n-3; i++){
        for(int j=0; j<4 * n -3; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }

}