#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

/*
    Find the connected component(room) of each '.' and increment the room count
*/


int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void floodfill(int row, int col, char color){
  if(row >= n || col >= m || row < 0 || col < 0 || visited[row][col] || grid[row][col] != color){ return; }
  
  visited[row][col] = true;
  
  floodfill(row + 1, col, color);
  floodfill(row, col + 1, color);
  floodfill(row - 1, col, color);
  floodfill(row, col - 1, color);
}


int main() {
  cin >> n >> m;
  grid.resize(n, vector<char>(m));
  visited.resize(n, vector<bool>(m, false));
  
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < m; j ++){ 
      cin >> grid[i][j];
    }
  }
  
  int res = 0;
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < m; j ++){
      if(!visited[i][j] && grid[i][j] == '.'){
        res += 1;
        floodfill(i, j, '.');
      }
    }
  }
  
  cout << res << endl;
  
}