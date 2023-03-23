//
// Created by MZ01-GOJGHO on 2023/03/23.
//

#include <iostream>
#include <queue>
using namespace std;
string s;
string ret;
queue<char> q;
int main() {
    getline(cin,s);

    for(int i=0; i<s.size(); i++){
        q.push(s[i]);

    }

    string add;
    string str;
    bool flag = false;
    while(q.size()) {
//        cout  << q.front() << ' ';
        if(q.front() == '<'){
            if(str.size()){
                std::reverse(str.begin(), str.end());
                ret += str;
                str = "";
            }
            ret += '<';
            flag = true;
        }else if(q.front() == '>'){
            ret += add;
            ret += '>';
            add = "";

            flag = false;
        }else if(flag){
            add+=q.front();
            //cout << "add = " << add << "\n";
        }else if(q.front() == ' '){
            std::reverse(str.begin(), str.end());
            ret+=(str + q.front());
            str = "";
        }else{
            str+=q.front();
        }
        q.pop();
    }

   // std::reverse(ret.begin(), ret.end());
    if(str.size()) {
        std::reverse(str.begin(), str.end());
        ret += str;
    }
    cout << ret << '\n';

}