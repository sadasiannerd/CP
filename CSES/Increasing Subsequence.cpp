#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXSUM = 1e5 + 1;
const int mod = 1e9 + 7;
ll dp[MAXSUM];

class MaxSegTree{
  private:
    int len;
    vector<int> segtree;
  public:
    MaxSegTree(int len) : len(len), segtree(2 * len) {}
  
    void update(int i, int val){
    for(segtree[i += len]=val; i >= 1; i >>= 1)
      segtree[i >> 1] = max(segtree[i], segtree[i^1]);
  }
  
    //return max value in [from, to)
    int query(int from, int to){
    int max_ = INT32_MIN;
    for(from+=len, to+=len; from < to; from >>= 1, to >>= 1){
      if((from & 1) != 0) max_ = max(max_, segtree[from++]);
      if((to & 1) != 0) max_ = max(max_, segtree[--to]);
    }
    
    return max_;
  }
};


int main() 
{
  int n;
  cin >> n;
  vector<int> v(n);
  map<int,int> compressed;
  for(int i = 0; i < n; i ++){
    cin >> v[i];
    compressed[v[i]] = 0;
  }
  
  int cnt = 0;
  for(auto &p: compressed) compressed[p.first] = cnt ++;
  
  auto cmp = [&](int i) -> int { return compressed[v[i]]; };
  
  MaxSegTree dp(cnt);
  
  dp.update(cmp(0), 1);
  for(int i = 1; i < n; i ++){
    int prev_max = dp.query(0, cmp(i));
    if(prev_max == INT32_MIN)
      dp.update(cmp(i), 1);
    else
      dp.update(cmp(i), prev_max + 1);
  }
  
  cout << dp.query(0, cnt) << endl;
}




