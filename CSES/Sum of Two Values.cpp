#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> mv;

bool comparefn(const mv &left, const mv &right){
  return (left.second <= right.second);
}



int main() 
{
  int n, x;
  cin >> n >> x;
  vector<int> vals(n);
  map<int, vector<int>> pos;
  for(int i = 0; i < n; i ++){
    cin >> vals[i];
    pos[vals[i]].push_back(i);
  }
  pair<int, int> res = {-1, -1};
  for(auto &val: vals){
    int first = val;
    int second = x - first;
    if(!pos.count(second)) continue;
    else{
      int pos_first = pos[first][0];
      int i_pos_sec = 0;
      vector<int> &pos_sec = pos[second];
      int num_pos_sec = pos_sec.size();
      while(i_pos_sec < num_pos_sec && pos_sec[i_pos_sec] == pos_first) i_pos_sec ++; 
      if(i_pos_sec < num_pos_sec){
        res = {pos_first, pos_sec[i_pos_sec]};
        break; 
      }
    }
  }
  
  if(res.first == res.second && res.first == -1) cout << "IMPOSSIBLE" << endl;
  else cout << res.first + 1 << " " <<  res.second + 1<< endl;
}