#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
  vector<vector<int>> mat;
  int n, k;
  vector<int> v;
  cin >> n >> k;
  int row=0, col=0, count=0;
  int step=sqrt(n);
  for(int i = 1; i <= n; i ++){
    if(count > step){
        count = 0;
        mat.push_back(v);
        v.clear();        
    }
    v.push_back(i);
    count ++;
  }

  if(v.size() > 0) mat.push_back(v);

  for(int i = 0; i < n; i ++){
    int this_k = k % (n - i);
    while(this_k){
      if(col + this_k < mat[row].size()){
        col += this_k;
        this_k = 0;
      }else{
        this_k -= mat[row].size() - col;
        row ++;
        col = 0;
      }
      if(row >= mat.size()){
        row = 0;
      }
    }
    while(col >= mat[row].size()){
      col = 0;
      row ++;
      if(row >= mat.size()) row = 0;
    }
    
    cout << mat[row][col] << " ";
    
    mat[row].erase(mat[row].begin() + col);
    if(i != n - 1){
      while(col >= mat[row].size()){
      col = 0;
      row ++;
      if(row >= mat.size()) row = 0;
    } 
    }
    
  }
  
}