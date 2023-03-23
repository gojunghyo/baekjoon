//
// Created by MZ01-GOJGHO on 2023/03/23.
//
#include <algorithm>
#include <vector>
#include <iostream>
#define YEAR 365
using namespace std;
int yearCnt[YEAR+1], n , height, width, ret;
vector<pair<int,int>> v;

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        int start , end;
        cin >> start >> end;
        v.push_back({start,end});
    }

    sort(v.begin(), v.end());

    for(auto i : v) {
        for(int j=i.first; j<=i.second; j++){
            yearCnt[j]++;
        }
    }

    for(int i =1; i<=YEAR; i++){
        if(yearCnt[i]){
            height = max(height,yearCnt[i]);
            width++;
        }
        if(!yearCnt[i] || i == YEAR) {
            ret += height * width;
            height = 0;
            width = 0;
            cout << " ret =  " << ret << '\n';
        }
    }
    cout << ret;
}