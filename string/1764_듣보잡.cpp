//
// Created by MZ01-GOJGHO on 2023/03/30.
//

#include <iostream>
#include <map>
using namespace std;

map<string,int> mp;
int n, m;
int main() {
    cin >> n >> m;
    int cnt = 0;

    for(int i=0; i<n+m; i++){
        string s;
        cin >> s;
        mp.insert({s, mp[s]++});
        if(mp[s] > 1) cnt++;
    }

    cout << cnt << '\n';
    for(auto i : mp) {
        if(i.second > 1) {
            cout << i.first << '\n';
        }
    }



}