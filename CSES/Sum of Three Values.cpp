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
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; i ++){
    int a; cin >> a;
    v[i] = {a, i};
  }
  sort(v.begin(), v.end(), cmp);
  bool found = false;
  for(int i = 0; i < n; i ++){
    int l=0, h=n-1;
    while(l<h){
      if(l != i && h != i)
      {
        if(v[l].F + v[h].F > x - v[i].F) h--;
        else if(v[l].F + v[h].F < x - v[i].F) l ++;
        else{
          cout << v[i].S + 1 << " " << v[l].S + 1 << " " << v[h].S + 1 << endl;  
          found = true;
          break;
        }
      }
      if(l == i) l ++;
      if(h == i) h --;
    }
    if(found) break;
  }
  
  if(!found) cout << "IMPOSSIBLE" << endl;
  
}