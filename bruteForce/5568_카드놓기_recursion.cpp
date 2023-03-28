//
// Created by MZ01-GOJGHO on 2023/03/28.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n,k,ret;
bool visit[10004];
vector<int> v;
set<string> st;

void rec(string s, int cnt) {
    if(cnt == k){
        cout << s << '\n';
        st.insert(s);
        return;
    }

    for(int i=0; i<v.size(); i++){
        if(!visit[i]){ // 같은수를 또뽑는 경우를 배제하고자 visit 배열선언
            visit[i] = true;
            string str = s;
            rec(str += to_string(v[i]), cnt + 1);
            visit[i] = false;
        }
    }


}
void Input(){
    cin >> n >> k;

    for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(a);
    }
}
int main() {
    Input();
    rec("",0);

    cout << st.size();
}