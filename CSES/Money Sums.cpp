#include <bits/stdc++.h>
#define ll long long
#define isValid(a) (a <= n)&&(a >= 1)
using namespace std;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i ++) cin >> v[i];
  
  set<int> s;
  for(int i = 0; i < n; i ++){
    int val = v[i];
    vector<int> new_vals;
    for(const int &ans: s)
      new_vals.push_back(ans + val);
    for(int &new_val:new_vals)
      s.insert(new_val);
    s.insert(val);
  }
  
  cout << s.size() << endl;
  for(const int &ans: s) cout << ans << " ";
  cout << endl;
}
  
