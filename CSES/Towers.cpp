#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;

int bSearchRight(vector<int> v, int x, int N){
  int lo=0, hi=N-1;
  int ans = -1;
  while(lo<=hi){
    int mid = (lo + hi) / 2;
    if(x < v[mid]){
      ans = mid;
      hi = mid - 1;
    }else{
      lo = mid + 1;
    }
  } 
  return ans;
}

int main() 
{
  int n;
  cin >> n;
  vector<int> v;
  int cnt = 0;
  for(int i = 0; i < n; i ++){
    int x; cin >> x;
    int idxOfSmallestLarger = bSearchRight(v, x, cnt);
    if(idxOfSmallestLarger == -1){
      cnt++;
      v.push_back(x);
    }else{
      v[idxOfSmallestLarger] = x;
    }
  }
  cout << cnt << endl;
}