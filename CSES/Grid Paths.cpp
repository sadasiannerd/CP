#include <bits/stdc++.h>
#define ll long long
#define spc " "
using namespace std;

string s;
ll cache[50][50][50];
// bool visited[7][7];
vector<pair<int, int>> path;

ll solve(int i, int x, int y){
  //cout << x << spc << y << endl;
  path.push_back({x, y});
  if(i == 48){
    if(x == 6 && y == 0){
      // for(auto v: path) cout << "(" << v.first << spc << v.second << ")" << spc;
      // cout << endl;
      path.pop_back();
      return 1;
    }
    else {
      //cout << "not valid path" << endl;
      path.pop_back();
      return 0;
    }
  }
  if(x < 0 || x > 6 || y < 0 || y > 6) {
    //cout << "out of grid" << endl;
    path.pop_back();
    return 0;
  }
  
  if(cache[x][y][i] != -1){
    return cache[x][y][i];
    path.pop_back();
  }
  
  // if(visited[x][y]) 
  // {
  //   cout << "visited" << "(" << x << spc << y << ")" << endl;
  //   path.pop_back();
  //   return 0;
  // }else visited[x][y] = true;
  
  ll paths = 0;
  
  if(s[i] == '?'){
    ll U = solve(i + 1, x + 1, y);
    ll D = solve(i + 1, x - 1, y);
    ll R = solve(i + 1, x, y + 1);
    ll L = solve(i + 1, x, y - 1);
    
    paths = U + D + R + L;
    
  }else{
    if(s[i] == 'D') paths = solve(i + 1, x + 1, y);
    if(s[i] == 'U') paths = solve(i + 1, x - 1, y);
    if(s[i] == 'L') paths = solve(i + 1, x, y - 1);
    if(s[i] == 'R') paths = solve(i + 1, x, y + 1);
  }
  // visited[x][y] = false;
  cache[x][y][i] = paths;
  path.pop_back();
  return cache[x][y][i];
  
  
}

int main() 
{
  cin >> s;
  for(int i = 0; i < 50; i ++)
    for(int j = 0; j < 50; j ++)
      for(int k = 0; k < 50; k ++)
        cache[i][j][k] = -1;
  // for(int i = 0; i < 7; i ++)
  //   for(int j = 0; j < 7; j ++)
  //     visited[i][j] = false;
  cout << solve(0, 0, 0) << endl;
  
}