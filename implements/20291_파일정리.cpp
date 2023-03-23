//
// Created by MZ01-GOJGHO on 2023/03/23.
//

#include <iostream>
#include <map>
using namespace std;
int n;
map<string, int> mp;

int main() {
    string str;
    cin >> n;


    while(n--) {
        cin >> str;

        str = str.substr(str.find(".") + 1, str.size());
        // cout << str << '\n';
        mp.insert({str, mp[str]++});
    }

    for(auto i : mp) {
        cout << i.first << " " << i.second << '\n';
    }

}