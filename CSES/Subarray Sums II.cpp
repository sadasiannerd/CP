#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;

bool cmp(const pair<int,int> &left, const pair<int,int> &right){
  return left.F < right. F;
}

int main() 
{
  int n, x;
  cin >> n >> x;
  map<ll,int> mp;
  ll prefix_sum = 0;
  ll ans = 0;
  mp[0] = 1;
  for(int i = 0; i < n; i++){
    int v;
    cin >> v;
    prefix_sum += v;
    ans += mp[prefix_sum - x];
    mp[prefix_sum] += 1;
  }
  cout << ans << endl;
  
  
}