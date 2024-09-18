#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> adj;
int res = 0;

/*
    calculate dp to_leaf
    use to_leaf to calculate diameter of the tree rooted at node
*/

void dfs(int node, int par){
  if(dp[node] != -1) return;
  
  multiset<int> s;
  for(auto &nei: adj[node]){
    if(nei == par) continue;
    dfs(nei, node);
    s.insert(-1*dp[nei]);
  }
  
  dp[node] = 0;
  int mx1, mx2;
  auto it = s.begin();
  int cur_res = 0;
  if(it != s.end()){
    int mx1 = -(*it);
    ++it;
    cur_res += 1 + mx1;
    if(it != s.end()){
      int mx2 = -(*it);
      ++it;
      cur_res += 1 + mx2;
    }
    dp[node] = 1 + mx1;
  }
  res = max(res, cur_res);
}

int main() 
{
  int n; cin >> n;
  dp.resize(n, -1);
  adj.resize(n);
  
  for(int i = 0; i < n - 1; i ++){
    int a, b; cin >> a >> b;
    adj[--a].push_back(--b);
    adj[b].push_back(a);
  }
  
  for(int i = 0; i < n; i ++){
    dfs(i, -1);
  }
  
  cout << res << endl;
  
  
}