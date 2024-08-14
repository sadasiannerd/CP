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
  for(int i = 0 ; i < n; i ++) cin >> v[i];
  queue<int> q;
  set<int> cur_elems;
  int res = 0;
  int cur_len = 0;
  for(auto &val: v) {
    if(!cur_elems.count(val)){
      cur_elems.insert(val);
      q.push(val);
      cur_len ++;
      res = max(res, cur_len);
    }else{
      while(q.front() != val){
        cur_elems.erase(q.front());
        q.pop();
        cur_len --;
      }
      q.pop();
      q.push(val);
    }
  }
  cout << res << endl;
  
}