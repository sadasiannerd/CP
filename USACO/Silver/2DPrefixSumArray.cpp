#include <bits/stdc++.h>
#define ll long long
#define ar array
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
using namespace std;

ll query_sum(int x1, int y1, int x2, int y2, vector<vector<int>> &pref_sum_matrix){
  return (pref_sum_matrix[x2 + 1][y2 + 1] - 
          pref_sum_matrix[x1][y2 + 1] - 
          pref_sum_matrix[x2 + 1][y1] +
          pref_sum_matrix[x1][y1]);
}


int main(){
  int rows, cols; cin >> rows >> cols;
  
  vector<vector<int>> matrix(rows, vector<int>(cols, 0));
  for(int row = 0; row < rows; row ++){
    for(int col = 0; col < cols; col ++){
      cin >> matrix[row][col];
    }
  }
  
  vector<vector<int>> pref_sum_matrix(rows + 1, vector<int>(cols + 1, 0));
  
  for(int row = 1; row < rows + 1; row ++){
    for(int col = 1; col < cols + 1; col ++){
      pref_sum_matrix[row][col] = pref_sum_matrix[row - 1][col] + 
                                  pref_sum_matrix[row][col - 1] -
                                  pref_sum_matrix[row - 1][col - 1] +
                                  matrix[row - 1][col- 1];
    }
  }
  
  int t;
  cin >> t;
  while(t --){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    assert(x1 <= x2 && y1 <= y2);
    cout << query_sum(x1, y1, x2, y2, pref_sum_matrix) << endl;
  }
  
}
