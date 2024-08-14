#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;

int main() 
{
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  int v[n];
  for(int i = 0; i < n; i ++){
    cin >> v[i];
  }
  int cur_k = 0;
  int l=0,r=0;
  ll ans = 0;
  while(r < n){
    if(cnt[v[r]] == 0) cur_k ++;
    cnt[v[r]] ++;
    if(cur_k > k){
      while(cnt[v[l]] != 1){
        cnt[v[l]] --;
        l ++;
      }
      cnt[v[l]] --;
      l ++;
      cur_k --;
    }
    ans = ans + (r - l + 1);
    r ++;
  }
  cout << ans << endl;
  
  
}