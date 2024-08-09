/*
Name: Vu Thanh Loc Mai
Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=783
Category: Geometry
Description: Initially set the barn's area to the area of the lawnmower billboard. Then, we check if the width and the height can be reduced. 
*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct Rec{
  int bl_x;
  int bl_y;
  int tr_x;
  int tr_y;
};

struct Edge{
  int lx;
  int by;
  int rx;
  int ty;
  
  Edge(int lx, int by, int rx, int ty){
    assert(lx == rx || ty == by);
    
    this->lx = lx;
    this->by = by;
    this->rx = rx;
    this->ty = ty;
    
  }
};

bool checkHorEdgeInRec(Edge e, Rec r){
  if (r.bl_x <= e.lx && e.rx <= r.tr_x && r.bl_y <= e.by && e.by <= r.tr_y)
    return true;
  
  return false;
}

bool checkVerEdgeInRec(Edge e, Rec r){
  if (r.bl_y <= e.by && e.ty <= r.tr_y && r.bl_x <= e.lx && e.lx <= r.tr_x) 
    return true;
  
  return false;
}


int main(){
  Rec a, b;
  cin >> a.bl_x >> a.bl_y >> a.tr_x >> a.tr_y;
  cin >> b.bl_x >> b.bl_y >> b.tr_x >> b.tr_y;
  
  //set the barn's area to the area of lawnmower billboard
  int width = a.tr_x - a.bl_x;
  int height = a.tr_y - a.bl_y;
  
  
  //horizontal edges:
  Edge bh(a.bl_x, a.bl_y, a.tr_x, a.bl_y);
  Edge th(a.bl_x, a.tr_y, a.tr_x, a.tr_y);
  
  //vertical edges:
  Edge lv(a.bl_x, a.bl_y, a.bl_x, a.tr_y);
  Edge rv(a.tr_x, a.bl_y, a.tr_x, a.tr_y);
  
  //horizontal cases:
  if(checkHorEdgeInRec(bh, b)){
    //we got b.bl_y <= a.bl_y <= b.tr_y
    int reducedHeight = b.tr_y - a.bl_y;
    height = max(0, height - reducedHeight);
  }else if(checkHorEdgeInRec(th, b)){
    //we got b.bl_y <= a.tr_y <= b.tr_y 
    int reducedHeight = a.tr_y - b.bl_y;
    height = max(0, height - reducedHeight);
  }
  
  //vertical cases:
  if(checkVerEdgeInRec(lv, b)){
    //we got b.bl_x <= a.bl_x <= b.tr_y
    int reducedWidth = b.tr_y - a.bl_x;
    width = max(0, height - reducedWidth);
  }else if(checkVerEdgeInRec(rv, b)){
    //we got b.bl_x <= a.tr_x <= b.tr_y
    int reducedWidth = a.tr_x - b.bl_x;
    width = max(0, height - reducedWidth);
  }
  
  
  cout << height * width << endl;
  
  
  
  
}