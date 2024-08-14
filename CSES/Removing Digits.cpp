#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1e6 + 5;
int dp[MAXN];

void getDigits(int x, set<int> &digits){
  while(x>0){
    digits.insert(x % 10);
    x /= 10;
  }
}

int main() 
{
  int n; cin >> n;
  memset(dp, MAXN, sizeof dp);
  dp[0] = 0;
  for(int i = 1; i <= n; i++){
    set<int> digits;
    getDigits(i, digits);
    for(auto &digit: digits){
      dp[i] = min(dp[i], 1 + dp[i - digit]);
    }
  }
  
  cout << dp[n] << endl;
}