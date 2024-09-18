#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ar array
using namespace std;

/*
    Each connected component is a set of all cows that can reach each other without crossing a road
*/

int n;
vector<vector<bool>> grid;
vector<vector<bool>> visited;
set<ar<int, 4>> roads;

int floodfill(int row, int col, int prev_row, int prev_col){
  if(row >= n || col >= n || row < 0 || col < 0 || visited[row][col] || roads.count({prev_row, prev_col, row, col})){ return 0; }
  
  visited[row][col] = true;
  
  int cur_sz = grid[row][col];
  
  cur_sz += floodfill(row + 1, col, row, col);
  cur_sz += floodfill(row, col + 1, row, col);
  cur_sz += floodfill(row - 1, col, row, col);
  cur_sz += floodfill(row, col - 1, row, col);
  
  return cur_sz;
}


int main() {
  int k, r; cin >> n >> k >> r;
  grid.resize(n, vector<bool>(n, false));
  visited.resize(n, vector<bool>(n, false));
  
  for(int i = 0; i < r; i ++){
    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;
    roads.insert({--sr, --sc, --er, --ec});
    roads.insert({er, ec, sr, sc});
  }
  
  for(int i = 0; i < k; i ++){
    int r,c; cin >> r >> c;
    grid[--r][--c] = true;
  }
  
  
  vector<int> component_sizes;
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < n; j ++){
      if(!visited[i][j] && grid[i][j]){
        int cur_sz = floodfill(i, j, -1, -1);
        component_sizes.push_back(cur_sz);
      }  
    }
  }
  
  int num_components = component_sizes.size();
  int res = 0;
  for(int i = 0; i < num_components - 1; i ++){
    for(int j = i + 1; j < num_components; j ++){
      res += (component_sizes[i] * component_sizes[j]);
    }
  }
  
  cout << res << endl;
  
}