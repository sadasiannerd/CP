#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<int, int> mv;

bool comparefn(const int &left, const int &right){
  return (left <= right);
}

int main() 
{
  int n;
  cin >> n;
  vector<int> v(n);
  map <int, int>pos;
  for(int i = 0; i < n; i ++)
  {
    cin >> v[i];
    pos[v[i]] = i;
  }
  int cur_val = 1;
  int res = 0;
  while(cur_val <= n){
    res += 1;
    int prev = pos[cur_val];
    cur_val += 1;
    while(cur_val <= n && pos[cur_val] > prev){
      prev = pos[cur_val];
      cur_val += 1;
    }
  }
  
  cout << res << endl;
  
  
  
}