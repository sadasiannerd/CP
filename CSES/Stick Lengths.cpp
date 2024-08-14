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
  for(int i = 0; i < n; i ++)
  {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), comparefn);
  int med_pos = (0 + v.size() - 1) / 2;
  int med = v[med_pos];
  ll res = 0;
  for(auto &val: v){
    res += (med < val? val - med: med - val);
  }
  cout << res << endl;
}