#include <bits/stdc++.h>
#define ll long long
#define isValid(a) (a <= n)&&(a >= 1)
using namespace std;

const int MAXN = 100;
const int mod = 1e9 + 7;
const int MAXSUM = 1e5;


int main() {
  int n; cin >> n;
  vector<int> v(n);
  int pfxSum[n];
  cin >> v[0];
  pfxSum[0] = v[0];
  for(int i = 1; i < n; i ++) cin >> v[i];
  
  ll pfxSum_matrix[n][n];
  
  for(int j = 0; j < n; j ++)
    for(int i = j; i >= 0; i--){
      if(i == j) pfxSum_matrix[i][j] = v[i];
      else
        pfxSum_matrix[i][j] = pfxSum_matrix[i + 1][j] + v[i];
    }
  
  // for(int i = 0; i < n; i ++){
  //   for(int j = i; j < n; j ++) cout << pfxSum_matrix[i][j] << " ";
  //   cout << endl;
  // }
  
  ll dp[n][n];
  
  for(int i = 0; i < n; i ++) dp[i][i] = v[i];
  
  for(int j = 1; j < n ; j ++)
    for(int i = j - 1; i >= 0; i --)
      dp[i][j] = max(v[j] + pfxSum_matrix[i][j - 1] - dp[i][j - 1],v[i] + pfxSum_matrix[i + 1][j] - dp[i + 1][j]); 
      
      
  // for(int i = 0; i < n; i ++){
  //   for(int j = i; j < n; j ++) cout << dp[i][j] << " ";
  //   cout << endl; 
  // }
  
  cout << dp[0][n - 1] << endl; 

}