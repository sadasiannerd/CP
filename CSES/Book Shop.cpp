#include <bits/stdc++.h>
#define ll long long
#define isValid(a) (a <= n)&&(a >= 1)
using namespace std;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

int n;
ll dp[1000][1000] = {0};
char matrix[1000][1000];

int main() 
{
  int n, x; cin >> n >> x;
  vector<int> h(n);
  vector<int> s(n);
  for(int i = 0 ; i < n; i ++){
    cin >> h[i];
  }
  for(int i = 0; i < n; i ++){
    cin >> s[i];
  }
  ll dp[MAXN] = {0};
  for(int i = 0; i < n; i ++)
    for(int j = 0; j <= x; j ++){
      if(j + h[i] <= x) dp[j] = max(dp[j], s[i] + dp[j + h[i]]);
    }
    
  cout << dp[0] << endl;
}
  
