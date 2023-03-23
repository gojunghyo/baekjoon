//
// Created by MZ01-GOJGHO on 2023/03/23.
//
#include <map>
#include <iostream>
using namespace std;

map<char , pair<int,int>> mp;

bool check(char s) {
    //자음이면 true
    if(s == 'q' || s == 'w' || s == 'e' || s == 'r' || s == 't' ||
    s == 'a' || s == 's' || s == 'd' || s == 'f' || s == 'g' || s == 'z' || s == 'x' ||
    s == 'c' || s == 'v') return true;
    return false;
}

int main() {
    mp['q'] = {1,1}, mp['w'] = {1,2}, mp['e'] = {1,3}, mp['r'] = {1,4}, mp['t'] = {1,5},
            mp['y'] = {1,6}, mp['u'] = {1,7}, mp['i'] = {1,8}, mp['o'] = {1,9},mp['p'] = {1,10};

    mp['a'] = {2,1},mp['s'] = {2,2},mp['d'] = {2,3},mp['f'] = {2,4},mp['g'] = {2,5},mp['h'] = {2,6},mp['j'] = {2,7}
    ,mp['k'] = {2,8},mp['l'] = {2,9},

    mp['z'] = {3,1},mp['x'] = {3,2},mp['c'] = {3,3},mp['v'] = {3,4},mp['b'] = {3,5},mp['n'] = {3,6},mp['m'] = {3,7};


    int ret = 0;
    char lt, rt;
    string s;
    cin >> lt >> rt;
    cin >> s;

    for(int i=0; i<s.size(); i++){
        if(s[i] == lt || s[i] == rt) {
            ret += 1;
        }else{
           if(check(s[i])){
               //자음이면 왼손으로만 터치
               int lt_min = (abs(mp[lt].first - mp[s[i]].first) + abs(mp[lt].second - mp[s[i]].second));
               lt = s[i];
               ret += lt_min + 1;
           }else{
               //모음이면 오른손으로만 터치
               int rt_min = (abs(mp[rt].first - mp[s[i]].first) + abs(mp[rt].second - mp[s[i]].second));
               rt = s[i];
               ret += rt_min + 1;
           }

        }
    }

    cout << ret << '\n';
}