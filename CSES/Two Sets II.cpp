#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXSUM = 1e5 + 1;
const int mod = 1e9 + 7;
ll dp[MAXSUM];

int main() 
{
  int n;
  cin >> n;
  if((n%4!=0)&&(n%4!=3)) cout << 0 << endl;
  else{
    dp[0] = 1;
    ll s = (n + 1)*n/4;
    vector<int> v;
    for(int i = 1; i <= n; i ++) v.push_back(i);
    
    for(int i = 1; i <= n; i ++)
      for(int j = s; j > 0; j --)
        if(j - v[i] >= 0) dp[j] += dp[j - v[i]] %= mod;
    
    cout << dp[s]/2 % mod << endl;
  }
}