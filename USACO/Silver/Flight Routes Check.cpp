#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

vector<int> adj[100005][2];
vector<bool> visited;


/*
- If there is an edge from 1 to x and from x to 1 then the graph is strongly connected
- We check 1 to x in G and x to 1 in G^R
*/


void dfs(int v, int x){
  if(visited[v]){ return; }
  visited[v] = true;
  
  for(int &nei: adj[v][x]){ dfs(nei, x); }
}

int main() {
  int n, m; cin >> n >> m; 
  visited.resize(n);
  
  for(int i = 0; i < m; i ++){
    int a, b;
    cin >> a >> b;
    adj[--a][0].push_back(--b);
    adj[b][1].push_back(a);
  }
  
  
  dfs(0, 0);
  for(int i = 0; i < n; i ++){
    if(!visited[i]){
      cout << "NO" << endl;
      cout << 1 << " " << i + 1 << endl;
      return 0;
    }
  }
  
  for(int i = 0; i < n; i ++){ visited[i] = false; }
  dfs(0, 1);
  for(int i = 0; i < n; i ++){
    if(!visited[i]){
      cout << "NO" << endl;
      cout << i + 1 << " " << 1 << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
}

  
  
  
  
  
  
  
  
