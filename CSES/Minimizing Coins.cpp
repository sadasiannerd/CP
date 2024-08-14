#include <bits/stdc++.h>
#define ll long long 
using namespace std;

bool cmp(const pair<int,int> &left, const pair<int,int> &right){
  return left.second < right.second;
}

int main() 
{
  int n, x; cin >> n >> x;
  vector<int> v(n);
  for(int i = 0; i < n; i ++) cin >> v[i];
  int dp[x + 1];
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for(int i = 1; i <= x; i ++){
    for(int &val:v){
      if(i - val >= 0 && dp[i - val] != -1){
        if(dp[i] == -1) dp[i] = 1 + dp[i - val];
        else dp[i] = min(dp[i], dp[i - val] + 1);
      }
    }
  }
  
  cout << dp[x] << endl;

}