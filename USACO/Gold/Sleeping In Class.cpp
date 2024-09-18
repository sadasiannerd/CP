/*
Name: Vu Thanh Loc Mai
Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1203
Category: Basic Complete Search
Description: 
- To minimize the modification, we maximize the number of groups with equal sum
since: num_modification = n - num_groups
- 1 <= num_groups <= n
*/

#include <bits/stdc++.h>
using namespace std;

int solve(){
  int n;
  cin >> n;
  
  vector<int> elsie_log(n);
  int log_sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> elsie_log[i];
    log_sum += elsie_log[i];
  }  
  
  if(log_sum == 0){
    return 0;
  }

  for(int num_grp = n; num_grp >= 1; num_grp --){
    if(log_sum % num_grp != 0) continue;
    int cur_sum = 0;
    int target_val = log_sum / num_grp;
    bool valid = true;
    for(int i = 0; i < n; i ++){
      cur_sum += elsie_log[i];
      if(cur_sum > target_val) valid = false;
      else if(cur_sum == target_val) cur_sum = 0;
    }
    if(valid)
      return n - num_grp;

  }
  
  
  
}


int main() 
{
   int t;
   cin >> t;
   while(t--) cout<<solve()<<endl;
}