#include <bits/stdc++.h>
#define ll long long 
using namespace std;


const int N = 2e5 + 1;
int T[N] = {0};

void update(ll k, ll val){
  for(;k<=N;k+=(k&-k)) T[k] += val;
}

int query(ll k){
  ll ans = 0;
  for(;k>0;k-=(k&-k)) ans += T[k];
  return ans;
}


int main() 
{
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  map<ll, ll> compressed;
  map<int, int> decompressed;
  for(int i = 0; i < n; i ++){
    cin >> v[i];
    compressed[v[i]] = 0;
  }
  ll index = 1;
  for(auto &pr: compressed){
    pr.second = index ++;
    decompressed[pr.second] = pr.first;
  }
  ll mid = k / 2 + (k & 1);
  for(int i = 0; i < n; i ++){
    update(compressed[v[i]], 1);
    if(i >= k) update(compressed[v[i - k]], -1);
    if(i >= k - 1){
      ll lo=1,hi=2e5;
      ll ans = -1;
      while(lo <= hi){
        ll m = (lo + hi) / 2;
        if(query(m) >= mid && query(m - 1) < mid){
          ans = m;
          break;
        }else if(query(m) < mid){
          lo = m + 1;
        }else{
          hi = m - 1;
        }
      }
       cout << decompressed[ans] << endl;
    }
  }
  
}