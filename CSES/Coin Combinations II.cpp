#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int MOD = 1e9 + 7;

bool cmp(const pair<int,int> &left, const pair<int,int> &right){
  return left.second < right.second;
}

int main() 
{
  int n, x; cin >> n >> x;
  vector<int> v(n);
  for(int i = 0; i < n; i ++) cin >> v[i];
  ll dp[x + 1] = {0};
  dp[0] = 1;
  for(int &val: v){
    for(int i = 1; i <= x; i ++){
      if(i - val >= 0) dp[i] = (dp[i] + dp[i - val])%MOD;
    }
  }
  
  cout << dp[x]%MOD << endl;
}