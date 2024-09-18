#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

int max_x, max_y, min_x, min_y;
vector<vector<int>> adj_matrix;
vector<pair<int,int>> cows;
vector<bool> visited;

void dfs(int v){
  if(visited[v]){ return; }
  visited[v] = true;
  
  max_x = max(max_x, cows[v].f);
  max_y = max(max_y, cows[v].s);
  min_x = min(min_x, cows[v].f);
  min_y = min(min_y, cows[v].s);
  
  for(int i = 0; i < adj_matrix[v].size(); i ++){ if(adj_matrix[v][i]) dfs(i); }
}

int get_perimeter(){
  return 2 * (max_x - min_x + max_y - min_y); 
}


int main() {
  int n, m; cin >> n >> m;
  adj_matrix.resize(n, vector<int>(n, 0));
  cows.resize(n);
  visited.resize(n);
  
  for(int i = 0; i < n; i ++){ cin >> cows[i].f >> cows[i].s; }
  
  for(int i = 0; i < m; i ++){
    int a, b; cin >> a >> b;
    adj_matrix[--a][--b] = 1;
    adj_matrix[b][a] = 1;
  }
  
  int min_p = INT_MAX;
  int curr_p;
  for(int i = 0; i < n; i ++){
    if(!visited[i]){
      max_x = cows[i].f;
      max_y = cows[i].s;
      min_x = cows[i].f;
      min_y = cows[i].s;
      dfs(i);
      
      curr_p = get_perimeter();
      min_p = min(min_p, curr_p);
    }
  }
  
  cout << min_p << endl;
}

  
  
  
  
  
  
  
  
