//
// Created by MZ01-GOJGHO on 2023/03/23.
//

#include <iostream>
#include <map>
using namespace std;

map<int,int> mp;

int n,m;

int main() {

    while(true){
        cin >> n >> m;

        if(n == 0 && m == 0) break;
        int fiMax = -1e9;
        int seMax = -1e9;
        mp.clear();

        for(int i=0; i<n * m; i++){
                int value;
                cin >> value;
                mp.insert({value, mp[value]++});
                if(fiMax < mp[value]) {
                    fiMax = mp[value];
                }
        }

        for(auto i : mp){
            if(i.second == fiMax){
                mp[i.first] = 0;
            }
        }

        for(auto i : mp) {
           if(seMax < i.second){
               seMax = i.second;
           }
        }

        for(auto i : mp){
            if(i.second == seMax){
                cout << i.first << ' ';
            }
        }


        cout << '\n';

    }


}