//
// Created by MZ01-GOJGHO on 2023/03/27.
//

#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int can_value[1000];
int ret;
struct Game{
    int Number;
    int Strike;
    int Ball;
};
vector<Game> v;

int n;
void InitValue(){
    memset(can_value, true, sizeof can_value);
    for(int i=123; i<=999; i++){
        string tmp = to_string(i);
        if(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) can_value[i] = false;
        if(tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) can_value[i] = false;
    }
}

void Input(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Game G;
        G.Number = a;
        G.Strike = b;
        G.Ball = c;
        v.push_back(G);
    }
}

void Solution(){
    for(int i=0; i<v.size(); i++){
        int Num = v[i].Number;
        int Strike = v[i].Strike;
        int Ball = v[i].Ball;
        string Origin = to_string(Num);

        for(int j=123; j<=999; j++){
            int Tmp_Strike = 0;
            int Tmp_Ball = 0;
            if(can_value[j]){
                string Tmp = to_string(j);
                for(int a=0; a<3; a++){
                    for(int b=0; b<3; b++){
                        if(a == b && Origin[a] == Tmp[b]) Tmp_Strike++;
                        if(a != b && Origin[a] == Tmp[b]) Tmp_Ball++;
                    }
                }
                if(Strike != Tmp_Strike || Ball != Tmp_Ball) {
                    can_value[j] = false;
                }
            }
        }
    }

    for(int i=123; i<=999; i++){
        if(can_value[i]) ret++;
    }
    cout << ret <<'\n';
}

void solve(){
    InitValue();
    Input();
    Solution();
}

int main() {

    solve();
}