/*
Name: Vu Thanh Loc Mai
Problem link: https://codeforces.com/problemset/problem/581/D
Category: Complete Search
Description: 
- Try all possible rotations of the rectangles
- One thing to note is because the area is a square,
we don't need to account for the order of the rectangles to be placed.
This is because there will always be a way to rotate the rectangles so that the
first rectangle is placed on the top left corner.
*/
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define valid(n) ((n) >= 0 && (n) < len)

using namespace std;

const int N = 3;

int main(){
  int x1,y1,x2,y2,x3,y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  
  vector<pair<int,int>> rectangles;
  
  rectangles.push_back({x1,y1});
  rectangles.push_back({x2,y2});
  rectangles.push_back({x3,y3});
  
  int area=0;
  for(pair<int,int> &rectangle: rectangles){
    area += rectangle.F * rectangle.S;
  }
  
  int len=0;
  while(len * len < area) len ++;
  
  if(len * len > area) cout << -1 << endl;
  
  cout << len << endl;
  
  for(int rotate_state=0; rotate_state < (1 << N); rotate_state ++){
    vector<string> grid(len, string(len, 'Z'));
    int num_placed=0;
    for(int i=0; i < len; i ++){
      for(int j=0; j < len; j ++){
        if(grid[i][j] == 'Z'){
          
          int w = rectangles[num_placed].F;
          int h = rectangles[num_placed].S;
          if(rotate_state & (1 << num_placed)) swap(w, h);

          for(int n=i; n < i + h; n ++){
            for(int m=j; m < j + w; m ++){
              if(!valid(n) || !valid(m) || grid[n][m] != 'Z') goto outer;
              grid[n][m] = 'A' + num_placed;
            }
          }
          
          num_placed++;
        }
      }
    }
    
    assert(num_placed == N);
    
    for(int i=0; i < len; i ++){
    for(int j=0; j < len; j ++) cout << grid[i][j];
    cout << endl;
    }
    return 0;
    
    outer:;
    
  }
  
  
}
