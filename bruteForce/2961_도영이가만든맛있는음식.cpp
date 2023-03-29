//
// Created by MZ01-GOJGHO on 2023/03/29.
//

#include <iostream>
#include <algorithm>
using namespace std;


pair<int,int> p1[10];
pair<int,int> p2[10];

int n,ret=1e9;
void Input(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        p1[i] = {a,b};
    }
}

void Combi(int idx, int cnt){
    if(cnt > 0) {
        int s = p2[0].first;
        int b = p2[0].second;

        for(int i=1; i<cnt; i++){
            s *= p2[i].first;
            b += p2[i].second;
        }
        cout << "s = " << s << " b = " << b << '\n';

        ret = min(ret, abs(s - b));
    }

    if(cnt == n) return;

    for(int i=idx; i<n; i++){
        p2[cnt] = {p1[i].first, p1[i].second};
        Combi(i + 1, cnt + 1);
    }
}

void Sol(){
    Combi(0,0);
    cout << ret << '\n';
}


int main() {
    Input();
    Sol();
}