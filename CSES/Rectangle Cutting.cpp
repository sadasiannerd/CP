#include <bits/stdc++.h>
#define ll long long
#define isValid(a) (a <= n)&&(a >= 1)
using namespace std;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

int main() {
  int a, b;
  cin >> a >> b;
  vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
  for(int i = 0; i <= a; i ++)
    for(int j = 0; j <= b; j ++){
      if(i == j){
        dp[i][j] = 0;
        continue;
      }
      
      for(int k = 1; k < j; k ++)
        dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
        
      for(int k = 1; k < i; k ++)
        dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
      
    }
    
    
  cout << dp[a][b] << endl;
}
  
