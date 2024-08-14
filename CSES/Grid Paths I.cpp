#include <bits/stdc++.h>
#define ll long long
#define isValid(a) (a <= n)&&(a >= 1)
using namespace std;

const int mod = 1e9 + 7;

int n;
ll dp[1000][1000] = {0};
char matrix[1000][1000];

int main() 
{
  cin >> n;
  for(int i = 0; i < n; i ++)
    for(int j = 0; j < n; j ++){
      cin >> matrix[i][j];
    }
  if(matrix[n - 1][n - 1] == '*'){
    dp[n - 1][n - 1] = 0;
  }
  else{
    dp[n - 1][n - 1] = 1;
  }
  for(int i = n - 2; i >= 0; i --){
    if(matrix[n - 1][i] == '*') continue;
    dp[n - 1][i] = dp[n - 1][i + 1];    
  }
  
  for(int i = n - 2; i >= 0; i --){
    if(matrix[i][n - 1] == '*') continue;
    dp[i][n - 1] = dp[i + 1][n - 1];
  }
  
  
  for(int i = n - 2; i >= 0; i --){
    for(int j = n - 2; j >= 0; j--){
      if(matrix[i][j] == '*') continue;
      dp[i][j] = (dp[i][j] + dp[i + 1][j] + dp[i][j + 1]) % mod;
    }
  }
  
  cout << dp[0][0] << endl;
  
}