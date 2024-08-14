#include <bits/stdc++.h>
#define ll long long
#define isValid(a) (a <= n)&&(a >= 1)
using namespace std;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

ll dp[5001][5001]; //dp[N][M]

int main() {
  string s1;
  string s2;
  cin >> s1 >> s2;
  int N = s1.length();
  int M = s2.length();
  dp[0][0] = 0;
  for(int i = 1; i <= N; i ++)
    dp[i][0] = 1 + dp[i - 1][0];
  for(int j = 1; j <= M; j ++)
    dp[0][j] = 1 + dp[0][j - 1];
  
  for(int i = 1; i <= N; i ++)
    for(int j = 1; j <= M; j ++){
      dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1]);
      if(s1[i - 1] == s2[j - 1]) dp[i][j] = min(dp[i][j],dp[i - 1][j - 1]);
      else dp[i][j] = min(dp[i][j],1 + dp[i - 1][j - 1]);
    }
    
  // for(int i = 0; i <= N; i ++){
  //   for(int j = 0; j <= M;j ++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
    
    
  cout << dp[N][M] << endl;
}
  
