//
// Created by MZ01-GOJGHO on 2023/03/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
string target = "quack";
int ret;

bool getCount(){
    vector<int> duck_v;
    int start, end, idx =0;
    while(idx < str.size()) {
        start = find(target.begin(), target.end(), str[idx]) - target.begin();
        end = s;
        while(idx < str.size() && end < target.size() && str[idx] == target[end]){
            idx++;
            end++;
        }
        if(s==0){
            duck_v.push_back(end);
            ret = max(ret, (int) duck_v.size());
            if(e - s == target.size()) duck_v.pop_back();
            continue;
        }
    }
}


int main() {
    cin >> str;
    if(getCount()){
        cout << ret << '\n';
    }else{
        cout << -1 << '\n';
    }
}