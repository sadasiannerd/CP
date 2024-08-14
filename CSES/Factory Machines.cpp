#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;

const int N = 2e5 + 1;

bool satisfy(ll t, ll *k, ll len_k, ll n){
  ll m = 0;
  for(int i = 0; i < len_k; i ++){
    m += t/k[i];
  }
  return m >= n;
}

ll first_true(ll lo, ll hi, bool (*f)(ll, ll*, ll, ll) , ll *k, ll n, ll t){
  ll ans = -1;
  while(lo <= hi){
    ll mid = (lo + hi)/2;
    if(f(mid,k,n,t)){
      ans = mid;
      hi = mid - 1;
    }else{
      lo = mid + 1;
    }
  }
  return ans;
}

int main() 
{
  ll n, t;
  cin >> n >> t;
  ll k[n];
  for(int i = 0; i < n; i ++) cin >> k[i];
  cout << first_true(0, 1e18, &satisfy, k, n, t) << endl;
}