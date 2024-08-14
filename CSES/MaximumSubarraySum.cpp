#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<int, int> mv;

bool comparefn(const mv &left, const mv &right){
  return (left.second <= right.second);
}



int main() 
{
  int n;
  cin >> n;
  vector<int> v(n);
  ll max_sofar = 0, cur_max = INT_MIN;
  for(int i = 0; i < n; i ++)
  {
    cin >> v[i];
    max_sofar += v[i];
    cur_max = max(cur_max, max_sofar);
    max_sofar = (max_sofar < 0? 0 : max_sofar);
  }
  cout << cur_max << endl;
  
}