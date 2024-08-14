#include <bits/stdc++.h>
#define ll long long
#define isValid(a) (a <= n)&&(a >= 1)
using namespace std;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

ll dp[MAXN][2];

int main() {
  
  int t;
  dp[1][0] = 1;
  dp[1][1] = 1;
  for(int i = 2; i < MAXN; i ++){
    dp[i][0] = (dp[i - 1][0]*2%mod + dp[i - 1][1])%mod;
    dp[i][1] = (dp[i - 1][1]*4%mod + dp[i - 1][0])%mod;
  }
  cin >> t;
  while(t--){
    int v; cin >> v;
    cout << (dp[v][0] + dp[v][1])%mod << endl;
  }
  
}
  
