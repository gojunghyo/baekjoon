//
// Created by MZ01-GOJGHO on 2023/03/28.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,k,ret;
vector<int> v;
set<string> st;
void Input(){
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

void Sol(){
    sort(v.begin(), v.end());
    do{
        string s;
        for(int i=0; i<k; i++){
            s+=to_string(v[i]);
        }
        cout << s << '\n';
        st.insert(s);
    } while (next_permutation(v.begin(), v.end()));

cout << st.size() << '\n';
}

int main() {
    Input();
    Sol();

}