/*
Description: try splitting by x-axis and y-axi, and get the min of them
(2 rectangles overlap if both horizontal and vertical edges overlap)

- sort the edges by first coordinate, using a prefix and suffix array to keep track of min and max of second coordinate
*/
#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

int n;

bool comp(ar<int,2> &left, ar<int,2> &right){
  if(left[0] == right[0]) return left[1] < right[1];
  return left[0] < right[0];
}

ll search(vector<ar<int,2>> pts){
  
  sort(all(pts));
  
  vector<ar<int,2>> pref(n), suf(n);
  pref[0] = pts[0];
  suf[n - 1] = pts[n - 1];
  
  for(int i = 1; i < n; i ++){
    pref[i][0] = min(pref[i - 1][0], pts[i][1]);
    pref[i][1] = max(pref[i - 1][1], pts[i][1]);
  }
  
  for(int i = n - 2; i >= 0; i --){
    suf[i][0] = min(suf[i + 1][0], pts[i][1]);
    suf[i][1] = max(suf[i + 1][1], pts[i][1]);
  }
  
  int original_fence_area = (pts[n - 1][0] - pts[0][0]) * (pref[n - 1][1] - pref[n - 1][0]);
  
  ll best = INT_MAX;
  for(int i = 0; i < n - 1; i ++){
    if(pts[i][0] != pts[i + 1][0]){
      ll rect1 = (ll) ((pts[i][0] - pts[0][0]) * (pref[i][1] - pref[i][0]));
      ll rect2 = (ll) ((pts[n - 1][0] - pts[i + 1][0]) * (suf[i + 1][1] - suf[i + 1][0]));
      
      best = min(best, rect1 + rect2);
    }
  }
  
  return original_fence_area - best;
}

int main() {
  cin >> n;
  vector<ar<int,2>> pts(n);
  for(int i = 0; i < n; i ++) cin >> pts[i][0] >> pts[i][1];
  int res1 = search(pts);
  //flip the rectangle and search again
  for(int i = 0; i < n; i ++) swap(pts[i][0], pts[i][1]);
  int res2 = search(pts);
  
  cout << min(res1, res2) << endl;
  
}

  
  
  
  
  
  
  
  
