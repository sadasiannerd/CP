#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

vector<vector<int>> adj;
vector<int > assigned;

bool dfs(int v){
  int curr = assigned[v];
  int n_color = (curr == 1 ? 2 : 1);
  for(int &nei: adj[v]){
    if(assigned[nei]){
      if(assigned[nei] != n_color){ return false; }
    }else{
      assigned[nei] = n_color;
      if(!dfs(nei)) { return false; }
    }
  }
  
  return true;
}


int main() {
  int n, m; cin >> n >> m;
  
  adj.resize(n);
  assigned.resize(n, 0);
  for(int i = 0; i < m; i ++){
    int a, b; cin >> a >> b;
    adj[--a].push_back(--b);
    adj[b].push_back(a);
  }
  
  bool valid = true;
  for(int i = 0; i < n; i ++){
    if(!assigned[i]){
      assigned[i] = 1;
      if(!dfs(i)){
        valid = false;
        break;
      }
    }
  }
  
  if(!valid){ cout << "IMPOSSIBLE" << endl; }
  else{ 
  for(int i = 0; i < n; i ++) cout << assigned[i] << " "; 
  cout << endl;
  }
  
}

  
  
  
  
  
  
  
  
