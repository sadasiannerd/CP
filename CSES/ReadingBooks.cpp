#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;

int main() 
{
  ll n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  ll remainingBooks = 0;
  for(int i = 0; i < n - 1; i ++) remainingBooks += v[i];
  if(remainingBooks < v[n - 1]) cout << remainingBooks + v[n - 1] + (v[n - 1] - remainingBooks) << endl;
  else cout << remainingBooks + v[n - 1] << endl;
  
}