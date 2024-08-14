#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> mv;

bool comparefn(const mv &left, const mv &right){
  return (left.second <= right.second);
}


int main() 
{
  int n;
  cin >> n;
  vector<mv> v;
  for(int i = 0; i < n; i ++){
  int first, second;
  cin >> first >> second;
  v.push_back({first, second});
  }
  sort(v.begin(), v.end(), comparefn);
  int res = 0;
  int prev_end = NULL;
  for(auto &tup: v){
    if(!prev_end){
      prev_end = tup.second;
      res += 1;
      continue;
    }else if(prev_end && tup.first >= prev_end){
    prev_end = tup.second;
    res ++;
    }
  }

  cout << res << endl;  
}