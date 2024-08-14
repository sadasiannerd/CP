#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;

const int N = 2e5 + 1;

int T[N] = {0};
map<int, int> mp;

bool cmp(const pair<pair<int,int>,int> &left, const pair<pair<int,int>,int> &right){
  if(left.F.F == right.F.F) return left.F.S >= right.F.S;
  return left.F.F <= right.F.F;
}

int query(int k){
  int ans = 0;
  while(k > 0){
    ans += T[k];
    k -= (k&-k);
  }
  
  return ans;
}

void update(int n, int k, int val){
  while(k <= n){
    T[k] += val;
    k += (k&-k);
  }
}

int main() 
{
  int n;
  cin >> n;
  vector<pair<pair<int, int>,int>> v(n);
  set<int> b;
  for(int i = 0; i < n; i ++){
    int x, y;
    cin >> x >> y;
    v[i].F = {x, y};
    v[i].S = i;
    b.insert(y);
  }

  int cnt = 0;
  for(auto i: b){
    mp[i] = ++cnt;
  }
  
  
  sort(v.begin(), v.end(), cmp);
  int res[n] = {0};
  
  
  for(int i = n - 1; i >= 0; i--){
    res[v[i].S] = query(mp[v[i].F.S]);
    update(cnt, mp[v[i].F.S], 1);
  }
  
  for(int i=0; i < n; i ++) cout << res[i] << " ";
  cout << endl;
  
  memset(res, 0, sizeof res);
  memset(T, 0, sizeof T);
  
  for(int i = 0; i < n; i++){
    res[v[i].S] = query(cnt) - query(mp[v[i].F.S] - 1);
    update(cnt, mp[v[i].F.S], 1);
  }
  
  for(int i=0; i < n; i ++) cout << res[i] << " ";
  cout << endl;
  
  
  
}