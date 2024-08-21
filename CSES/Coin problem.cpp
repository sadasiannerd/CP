#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){


}

int main(){

 int n, m;
 cin >> n >> m;
 int c[n];
 int first[m];
 for(int i = 0; i < n; i ++)
    cin >> c[i];
 int dp[m + 1];
 dp[0] = 0;
 for(int i = 1; i <= m; i ++){
    dp[i] = INT_MAX;
    for(auto &v: c){
        if(i - v >= 0 && 1 + dp[i - v] < dp[i]){
            dp[i] = dp[i - v] + 1;
            first[i] = v;
        }
    }
 }

 cout << dp[m] << endl;
 int cur = m;
 for(int i = 0; i < dp[m]; i ++)
 {
    cout << first[cur] << spc;
    cur -= first[cur];
 }
 cout << endl;



}
