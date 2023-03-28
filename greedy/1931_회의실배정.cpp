//
// Created by MZ01-GOJGHO on 2023/03/28.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ret;
struct Data{
    int start;
    int end;
};
vector<Data> v;

bool cmp(Data &a, Data &b) {
    if(a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}
void Input(){
    cin >> n;

    for(int i=0; i<n; i++){
        int start, end;
        cin >> start >> end;
        Data d;
        d.start = start;
        d.end = end;
        v.push_back(d);
    }
}

void Sol(){
    sort(v.begin(), v.end(), cmp);
    int start = v[0].end;
    ret = 1;
    for(int i=1; i<v.size(); i++){
//        cout << v[i].start << " : " << v[i].end << "\n";
        if(start <= v[i].start) {
            ret++;
            start = v[i].end;
        }
    }
    cout << ret;
}
int main() {

    Input();
    Sol();

}