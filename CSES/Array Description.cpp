#include <bits/stdc++.h>
#define ll long long
#define isValid(a) (a <= n)&&(a >= 1)
using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

int main() {
  
  int n,m; cin >> n >> m;
  int x[n];
  for(int i = 0; i < n; i++) cin >> x[i];
  
  ll dp[n][m + 1];
  for(int i = 0; i < n; i ++)
    for(int j = 0; j <= m; j ++) dp[i][j] = 0;
  
  if(x[0] == 0)
    for(int i = 1; i <= m; i ++) dp[0][i] = 1;
  else
    dp[0][x[0]] = 1;
  
  
  for(int i = 1; i < n; i ++)
  {
    if(x[i] != 0){
      dp[i][x[i]] = (dp[i - 1][x[i] - 1] + dp[i - 1][x[i]])%mod;
      if(x[i] < m) dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + 1])%mod;
      continue; 
    }
    for(int j = 1; j <= m; j ++){
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%mod; 
      if(j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1])%mod;
      
    } 
  }
  
  
  ll ans = 0;
  for(int i = 1; i <= m; i ++){
    ans = (ans + dp[n - 1][i])%mod;
  }
  
  cout << ans << endl;
  
  
}
  
