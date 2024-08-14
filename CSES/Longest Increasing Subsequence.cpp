#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define FOR(N) for(int i = 0; i < n; i ++)
using namespace std;


int DFS(int *arr, int i, int v, vector<int> cache, int N){
  if(cache[i] != -1) return cache[i];
  
  if(i == N) return 0;
  
  int res = 0;
  
  for(int j = i; j < N; j ++){
  if (arr[j] > v) res = max(res, 1 + DFS(arr, j + 1, arr[j], cache, N)); 
  }
  cache[i] = res;
  
  return cache[i];
  
}


int main() 
{
  int n;
  cin >> n;
  int arr[n];
  FOR(n) cin >> arr[i];
  vector<int> cache(n, -1);
  cout << DFS(arr, 0, INT_MIN, cache, n) << "\n";
}