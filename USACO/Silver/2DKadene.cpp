#include <bits/stdc++.h>
#define ll long long
#define ar array
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
using namespace std;

ll kadene(vector<int> a){
  int n = a.size();
  assert(n > 0);
  int global_max = a[0];
  int local_max = a[0];
  for(int i = 1; i < n;i ++){
    local_max = max(local_max + a[i], a[i]);
    global_max = max(global_max, local_max);
  }
  return global_max;
}


int main(){
  int rows, cols; cin >> rows >> cols;
  
  vector<vector<int>> matrix(rows, vector<int>(cols, 0));
  for(int row = 0; row < rows; row ++){
    for(int col = 0; col < cols; col ++){
      cin >> matrix[row][col];
    }
  }
  
  ll global_max = INT_MIN;
  for(int start = 0; start < rows; start ++){
    vector<int> sum_of_cols(cols, 0);
    for(int end = start; end < rows; end ++){
      for(int col = 0; col < cols; col ++){
        sum_of_cols[col] += matrix[end][col];
      }
    ll local_max = kadene(sum_of_cols);
    global_max = max(global_max, local_max);
    }
  }
  
  cout << global_max << endl;
  
}
