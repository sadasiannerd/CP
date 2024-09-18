#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v){
  if(visited[v]) { return; }
  
  visited[v] = true;
  
  for(const int &nei: adj[v]){ dfs(nei); }
}


int main() {
  int n, m; cin >> n >> m;
  
  adj.resize(n);
  visited.resize(n);
  for(int i = 0; i < m; i ++){
    int a, b; cin >> a >> b;
    adj[--a].push_back(--b);
    adj[b].push_back(a);
  }
  
  vector<int> city_reps;
  for(int i = 0; i < n; i ++){
    if(!visited[i]){
      dfs(i);
      city_reps.push_back(i);
    }
  }
  
  int num_city_reps = city_reps.size();
  cout << num_city_reps - 1 << endl;
  
  for(int i = 1; i < num_city_reps; i ++){ cout << city_reps[i - 1] + 1 << " " << city_reps[i] + 1 << endl; }
  
}

  
  
  
  
  
  
  
  
