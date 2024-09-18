#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
  int n, target; cin >> n >> target;
  vector<pair<int,int>> vals(n);
  for(int i = 0; i < n; i ++){
    int tmp; cin >> tmp;
    vals[i] = {tmp, i};
  }
  sort(all(vals));
  
  for(int start = 0; start < n - 2; start ++){
  target -= vals[start].f;
  int left = start + 1, right = n - 1;
  while(left < right){
    int cur_sum = vals[left].f + vals[right].f;
    if(cur_sum < target) left ++;
    else if(cur_sum > target) right --;
    else{
      cout << vals[start].s << " " << vals[left].s << " " << vals[right].s << endl;
      return 0;
    }
  }
  target += vals[start].f; 
  }
  
  cout << "IMPOSSIBLE" << endl;
}

  
  
  
  
  
  
  
  
