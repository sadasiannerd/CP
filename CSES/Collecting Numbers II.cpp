#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<int, int> mv;

bool comparefn(const int &left, const int &right){
  return (left <= right);
}

int main() 
{
  ll n, m;
  cin >> n >> m;
  vector<int> v(n);
  map<int, int> pos;
  for(int i = 0; i < n; i ++)
  {
    cin >> v[i];
    pos[v[i]] = i;
  }
  ll count = 1;
  for(int i = 1; i < n; i ++){
    count += (pos[i] > pos[i + 1]); 
  }
  for(int i = 0 ; i < m; i ++){
    ll l, r;
    cin >> l >> r;
    set<pair<int, int>> updatedPairs;
    if(v[l - 1] > 1) updatedPairs.insert({v[l - 1] - 1, v[l - 1]});
    if(v[l - 1] < n) updatedPairs.insert({v[l - 1], v[l - 1] + 1});
    if(v[r - 1] > 1) updatedPairs.insert({v[r - 1] - 1, v[r - 1]});
    if(v[r - 1] < n) updatedPairs.insert({v[r - 1], v[r - 1] + 1});
    
    for(auto &p: updatedPairs){
      // cout << p.first << " " << p.second << endl;
      count -= (pos[p.first] > pos[p.second]);
    }
    
    ll tmp = pos[v[l - 1]];
    pos[v[l - 1]] = pos[v[r - 1]];
    pos[v[r - 1]] = tmp;
    
    for(auto &p: updatedPairs) count += (pos[p.first] > pos[p.second]);
    
    cout << count << endl;
    
  }
  
}