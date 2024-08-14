#include <bits/stdc++.h>
#define ll long long 
using namespace std;

bool is_valid(vector<ll> v, ll x, ll k){
  ll sum=0;
  ll curk=1;
  for(ll &val: v){
    if(val > x) return false;
    if(sum + val > x){
      curk ++;
      sum = 0;
    }
    sum += val;
  }
  return curk <= k;
}

ll first_true(ll lo, ll hi, bool (*f)(vector<ll>, ll, ll), vector<ll> v, ll k){
  ll ans= -1;
  while(lo <= hi){
    ll mid = (lo + hi) / 2;
    if(f(v, mid, k)){
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
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  cout << first_true(0, 2e5*1e9, is_valid, v, k) << endl;
}