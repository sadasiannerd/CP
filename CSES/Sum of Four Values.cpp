 #include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;

bool cmp(const pair<int,int> &left, const pair<int,int> &right){
  return left.F < right. F;
}

int main() 
{
  ll n, x;
  cin >> n >> x;
  vector<int> v(n);
  for(int i = 0; i < n; i ++){
    cin >> v[i];
  }
  bool found = false;
  map<int, pair<int, int>> hm;
  for(int i = n - 1; i > 0; i --){
    for(int j = i + 1; j >= 0; j --)
      if(hm.find(x - v[i] - v[j]) != hm.end()){
        found = true;
        cout << i + 1 << " " << j + 1 << " " << hm[x - v[i] - v[j]].F + 1 << " " << hm[x - v[i] - v[j]].S  + 1<< endl;
        break;
      }
    if(found) break;
    for(int j = i + 1; j < n; j ++) hm[v[i] + v[j]] = {i,j};
  }
  
  if(!found) cout << "IMPOSSIBLE" << endl;
  
 
  
  
  
}