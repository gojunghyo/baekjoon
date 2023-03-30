//
// Created by MZ01-GOJGHO on 2023/03/30.
//

#include <queue>
#include <iostream>
using namespace std;
int n, k;
queue<int> q;
int main() {
    cin >> n >> k;

    for(int i=1; i<=n; i++) q.push(i);

    cout << "<";

    //solve
    while(q.size() > 1){
        for(int i=1; i<k; i++){
            int cq = q.front();
            q.pop();
            q.push(cq);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front();
    cout << ">";

}