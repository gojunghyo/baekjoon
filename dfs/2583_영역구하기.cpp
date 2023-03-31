//
// Created by MZ01-GOJGHO on 2023/03/31.
//


#include <iostream>
#include <vector>
using namespace std;
int arr[104][104];
int vis[104][104];
vector<int> v;
int n,m,k;
int cnt,ret;
int dy[] = {1,0,-1,0};
int dx[] = {0,-1,0,1};
void Input(){
    cin >> n >> m >> k;
    int value = k;
    while(value--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for(int i=b; i<d; i++){
            for(int j=a; j<c; j++){
                arr[i][j] = 1;
            }
        }
    }
}
void dfs(int y , int x) {
    vis[y][x] = 1;
    arr[y][x] = 1;
    cnt++;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >=n || nx >= m) continue;
        if(!vis[ny][nx] && arr[ny][nx] == 0) {
            dfs(ny,nx);
        }
    }

}

void Sol(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0 && !vis[i][j]){
                cnt = 0;
                dfs(i,j);
                ret++;
                v.push_back(cnt);
            }
        }
    }

    cout << ret << '\n';
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
}

int main() {

    Input();
    Sol();
}