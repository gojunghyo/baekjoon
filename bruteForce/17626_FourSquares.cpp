#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int n;
void Input() {
    cin >> n;
}

void Sol(){
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        int minValue = 1e9;

        for(int j=1; j<=sqrt(i); j++){
            int tmp = i - (j*j);
            minValue = min(minValue, dp[tmp]);
        }
        dp[i] = minValue + 1;
    }


    cout << dp[n] << '\n';
}
int main(){
    Input();
    Sol();
}