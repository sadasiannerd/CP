#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<int, int> mv;

bool comparefn(const int &left, const int &right){
  return (left <= right);
}

int main() 
{
  ll n;
  cin >> n;
  vector<ll> v(n);
  for(int i = 0; i < n; i ++)
  {
    cin >> v[i];
  }
  
  sort(v.begin(), v.end(), comparefn);
  
  ll cur_sum = 0;
  ll res = -1;
  
  for(auto &val: v){
    if(val > cur_sum + 1)
    {
      res = cur_sum + 1;
      break;
    }
    else cur_sum += val;
  }
  if(res == -1) cout << cur_sum + 1 << endl;
  else cout << res << endl;
  
  
  
  
}