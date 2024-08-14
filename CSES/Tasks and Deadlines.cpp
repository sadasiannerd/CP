#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;


bool cmp(pair<int,int> &left, pair<int,int> &right){
  return left.F < right.F;
}

int main() 
{
  ll n;
  cin >> n;
  vector<pair<int,int>> tasks(n);
  for(int i = 0; i < n; i ++){
    int x, y; cin >> x >> y;
    tasks[i] = {x,y};
  }
  sort(tasks.begin(), tasks.end(), cmp);
  ll ans = 0;
  for(auto &task: tasks){
    ans += task.S;
    ans -= task.F *(n--);
  }
  cout << ans << endl;
}