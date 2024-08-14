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
  vector<int> v(n);
  for(int i = 0; i < n; i ++) cin >> v[i];
  int l=0,r=0;
  int sum = 0;
  int ans = 0;
  while(r < n){
  sum += v[r];
  while(sum >= x){
    if(sum == x) ans ++;
    sum -= v[l];
    l ++;
  }
  r ++;
  }
  
  cout << ans << endl;
  
}