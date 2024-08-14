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
  int n;
  cin >> n;
  stack<int> s;
  vector<int> v(n);
  cin >> v[0];
  cout << 0 << " ";
  for(int i = 1; i < n; i ++){
    cin >> v[i];
    if(v[i] > v[i - 1]){
      cout << i - 1 + 1<< " ";
      s.push(i - 1);
    }else{
      while(!s.empty() && v[s.top()] >= v[i]) s.pop();
      if(s.empty()) cout << 0 << " ";
      else cout << s.top() + 1 << " ";
    }
  }
  
}