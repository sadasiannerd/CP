#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

bool comp(ar<int,2> &left, ar<int,2> &right){
  if(left[0] == right[0]) return left[1] > right[1];
  return left[0] < right[0];
}

int main() {
  int mountain_num; cin >> mountain_num;
  
  vector<ar<int,2>> mountains(mountain_num, {0, 0});
  for(int m = 0; m < mountain_num; m ++){
    int x, y; cin >> x >> y;
    mountains[m] = {x - y, x + y};
  }
  sort(all(mountains), comp);
  
  
  int max_so_far = mountains[0][1];
  int num_visible = 1;
  for(int i = 1; i < mountain_num; i ++){
    if(mountains[i][1] > max_so_far){
      num_visible ++;
      max_so_far = mountains[i][1];
    }
  }
  
  
  cout << num_visible << endl;
  
  
  
}

  
  
  
  
  
  
  
  
