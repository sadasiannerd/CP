#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;

int main() 
{
  int n;
  cin >> n;
  map<int, int> same_remainder;
  ll ans = 0;
  ll cur_remainder = 0;
  for(int i = 0; i < n; i++){
    int v; cin >> v;
    cur_remainder = ((cur_remainder + v) % n + n) %n;
    if(cur_remainder == 0) ans += 1;
    ans += same_remainder[cur_remainder];
    same_remainder[cur_remainder] ++;
  }
  
  cout << ans <<endl;
  
}