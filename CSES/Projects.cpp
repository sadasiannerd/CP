#include <bits/stdc++.h>
#define ll long long
using namespace std;

class MaxSegTree{
  private:
    int len;
    vector<int> segtree;
  public:
    MaxSegTree(int len) : len(len), segtree(len * 2) {}
    
    void update(int ind, int val){
      for(segtree[ind += len]=val; ind>1; ind>>=1)
        segtree[ind >> 1] = max(segtree[ind], segtree[ind^1]);
    }
    
    //return max on [from, to)
    ll query(int from, int to){
      int res = 0;
      for(from += len, to += len; from < to ; from >>= 1, to >>= 1){
        if(from % 2 != 0) res = max(res, segtree[from ++]);
        if(to % 2 != 0) res = max(res, segtree[--to]);
      }
      
      return res;
    }
};


MaxSegTree dp (10e6);

bool Comparefnc(pair<pair<int,int>,int> &left, pair<pair<int,int>,int> &right){
  return left.first.first < right.first.first;
}

int main() 
{
  int n; cin >> n;
  
  map<int,int> cmp;
  
  vector<pair<pair<int, int>,int>> projects(n);
  
  for(int i = 0; i < n; i ++){
    int a,b,c; cin >> a >> b >> c;
    cmp[a] = 0;
    cmp[b] = 0;
    projects[i].first = {a,b};
    projects[i].second = c;
  }
  sort(projects.begin(), projects.end(), Comparefnc);
  
  int cnt = 0;
  for(auto &pr: cmp){
    cmp[pr.first] = cnt ++;
  }
  
  int res = 0;
  for(auto &project:projects){
    int cur_max = dp.query(0, cmp[project.first.first]);
    int new_max = cur_max + project.second;
    int res = max(res, new_max);
    dp.update(cmp[project.first.second], new_max);
  }
  
  cout << res << endl;
  
  
}