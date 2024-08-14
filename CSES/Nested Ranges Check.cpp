#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct range{
  int l, r, in;
};

bool comparefn(const range &left, const range &right){
  if(left.l == right.l) return(left.r >= right.r);
  return (left.l <= right.l);
}

int main() 
{
  int n;
  cin >> n;
  vector<range> ranges(n);
  for(int i = 0; i < n; i ++){
    cin >> ranges[i].l >> ranges[i].r;
    ranges[i].in = i;
  }
  
  sort(ranges.begin(), ranges.end(), comparefn);
  
  int minEnd = INT_MAX;
  vector<int> contains (n, 0);
  vector<int> contained (n, 0);
  for(int i = n - 1; i >= 0; i --){
    if(ranges[i].r >= minEnd) contains[ranges[i].in] = 1;
    minEnd = min(minEnd, ranges[i].r);
  }
  int maxEnd = 0;
  for(int i = 0; i < n; i ++){
    if(ranges[i].r <= maxEnd) contained[ranges[i].in] = 1;
    maxEnd = max(maxEnd, ranges[i].r);
  }
  
  for(int i = 0; i < n; i ++) cout << contains[i] << " ";
  cout << endl;
  for(int i = 0; i < n; i ++) cout << contained[i] << " ";
  cout << endl;
  
}