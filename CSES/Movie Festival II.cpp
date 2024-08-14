#include <bits/stdc++.h>
#define ll long long 
using namespace std;

bool cmp(const pair<int,int> &left, const pair<int,int> &right){
  return left.second < right.second;
}

int main() 
{
  int n, k; cin >> n >> k;
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; i ++){
    int a, b; cin >> a >> b;
    v[i] = {a, b};
  }
  sort(v.begin(), v.end(), cmp);
  int ans = 0;
  multiset<int> endTimes;
  for(int i = 0; i < k; i ++){
    endTimes.insert(0);
  }
  for(int i = 0; i < n; i ++){
    auto it = endTimes.upper_bound(v[i].first); 
    if(it == endTimes.begin()) continue;
    
    ans += 1;
    endTimes.erase(--it);
    endTimes.insert(v[i].second);
  }
  
  cout << ans << endl;
} 