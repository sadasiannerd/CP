#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int MOD = 1e9 + 7;

const int possible_values[6] = {1,2,3,4,5,6};

int main() 
{
  int n;
  cin >> n;
  ll dp[n + 1] = {0};
  dp[0] = 1;
  for(int i = 1; i <= n; i++){
    for(const int &val: possible_values){
      if(i - val >= 0) dp[i] += (dp[i - val] % MOD);
    }
  }
  
  cout << dp[n] % MOD << endl;
} 
