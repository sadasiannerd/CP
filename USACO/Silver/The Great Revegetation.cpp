#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

/*
- For each connected component if we start with color 1 then we know how to color every vertex in the component
- So if it is possible to color the component we have 2 ways of coloring it (either start with color 1 or 2)
- The number of way to color the graphs is the 2^k where k is the number of connected components
*/



vector<vector<pair<int, int>>> adj;
vector<int> assigned;

int dfs(int v){
  int curr = assigned[v];
  
  for(pair<int, int> &nei: adj[v]){
    int nei_v = nei.f;
    int nei_t = nei.s;
    
    int n_color;
    if(nei_t == 'S') { n_color = (curr == 1 ? 1 : 2); }
    else if(nei_t == 'D') { n_color = (curr == 1 ? 2 : 1); }
    
    if(assigned[nei_v]) { if(assigned[nei_v] != n_color) return 0; }
    else{
      assigned[nei_v] = n_color;
      if(!dfs(nei_v)) return 0;
    }
  }
  
  return 1;
}


int main() {
  int n, m; cin >> n >> m;
  
  adj.resize(n);
  assigned.resize(n, 0);
  for(int i = 0; i < m; i ++){
    char t;
    int a, b; 
    cin >> t >> a >> b;
    adj[--a].push_back({--b, t});
    adj[b].push_back({a, t});
  }
  
  int res = 1;
  for(int i = 0; i < n; i ++){
    if(!assigned[i]){
      assigned[i] = 1;
      res *= (2 * dfs(i));
    }
  }
  
  cout << res << endl;
  
  
  
  
}

  
  
  
  
  
  
  
  
