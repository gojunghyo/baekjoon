//
// Created by MZ01-GOJGHO on 2023/03/22.
//

#include <iostream>

using namespace std;
int a[6][6];
int bingo = 0;

bool check(int num){
    int ret = 0;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            if(a[i][j] == num) {
                a[i][j] = 0;
            }
        }
    }


    int crossCnt1 = 0;
    int crossCnt2 = 0;
    int downNum = 5;

    for(int i=1; i<=5; i++){
        //J 는 행 체크
        int rowCnt = 0;
        int colCnt = 0;
        for(int j=1; j<=5; j++){
            if(a[i][j] == 0) rowCnt++;
            if(a[j][i] == 0) colCnt++;
        }

        if(a[i][i] == 0) crossCnt1++;
        if(a[i][downNum--] == 0) crossCnt2++;
        if(rowCnt == 5) ret++;
        if(colCnt == 5) ret++;
        if(crossCnt1 == 5) ret++;
        if(crossCnt2 == 5) ret++;

        if(ret >= 3) return true;
    }

    return false;
}

int main() {

    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            cin >> a[i][j];
        }
    }

    int cnt = 25;

    while(cnt--){
        int value;
        cin >> value;
        bingo++;
        bool ch = check(value);
        if(ch) break;
    }

    cout << bingo << '\n';

}