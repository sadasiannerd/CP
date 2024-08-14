#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 2e5 + 1;
int T[N] = {0};

ll query(int k){
  ll ans = 0;
  for(;k>0;k-=(k&-k)) ans += T[k];
  return ans;
}

void update(int k, int val){
  for(;k<N;k+=(k&-k)) T[k] += val;
}

int main() 
{
  int n, A, B; cin >> n >> A >> B;
  vector<ll> pfxsum(n);
  cin >> pfxsum[0];
  for(int i = 1; i < n; i++){
    int a; cin >> a;
    pfxsum[i] = pfxsum[i - 1] + a;   
  }
  multiset<ll> curPfxSum;
  curPfxSum.insert(0);
  ll ret = pfxsum[A - 1];
  for(int i = A; i < n; i++){
    curPfxSum.insert(pfxsum[i - A]);
    if(i >= B){
      curPfxSum.erase(curPfxSum.find(pfxsum[i - B]));
    }
    ret = max(ret, pfxsum[i] - *curPfxSum.begin());
  }
  
  cout << ret << endl;
  
  
  
}