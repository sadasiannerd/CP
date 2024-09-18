#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<int> diamonds(n);
  for(int i = 0; i < n; i ++) cin >> diamonds[i];
  sort(all(diamonds));
  
  
  vector<int> pref_max(n);
  pref_max[0] = 1;
  
  map<int, int> cnt;
  cnt[diamonds[0]] = 1;
  for(int i = 1; i < n; i ++){
    // first element that is no less than current element - k
    auto it = cnt.lower_bound(diamonds[i] - k);
    int num_elems = 0;
    while(it != cnt.end()){
       num_elems += (*it).s;
       it ++;
    }
    num_elems ++; // count the current element
    cnt[diamonds[i]] ++;
    pref_max[i] = max(pref_max[i - 1], num_elems);
  }
  
  
  vector<int> suf_max(n);
  suf_max[n - 1] = 1;
  
  cnt.clear();
  cnt[diamonds[n - 1]] = 1;
  for(int i = n - 2; i >= 0; i --){ 
  // first element that is greater than current element + k
  auto it = cnt.upper_bound(diamonds[i] + k);
  int num_elems = 0;
  if(it != cnt.begin()){
    while(it != cnt.begin()){
    num_elems += (*--it).s;
    }
  }
    num_elems ++; // count the current element
    cnt[diamonds[i]] ++;
    suf_max[i] = max(suf_max[i + 1], num_elems);
  }
  
  
  int ans = INT_MIN;
  for(int i = 0; i < n - 2; i ++){
    ans = max(ans, pref_max[i] + suf_max[i + 1]);
  }
  
  cout << ans << endl;
  
}

  
  
  
  
  
  
  
  
