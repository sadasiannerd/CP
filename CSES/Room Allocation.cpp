#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define F first
#define S second
using namespace std;

const int N = 2e5 + 1;

bool cmp(pair<pair<int, int>,int> &left, pair<pair<int, int>,int> &right){
  return left.F.F < right.F.F;
}

void print_pq(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq){
  while(!pq.empty()){
    cout << pq.top().F << " " << pq.top().S << " ";
    pq.pop();
  }
  cout << endl;
}


int main() 
{
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> v(n);
  for(int i = 0; i < n; i ++){
    int x, y; cin >> x >> y;
    v[i].F = {x, y};
    v[i].S = i;
  }
  sort(v.begin(), v.end(), cmp);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  
  int num_rooms = 0;
  int ans[n];

  
  for(auto &ve: v){
    int arival = ve.F.F;
    int departure = ve.F.S;
    int idx = ve.S;
    if(pq.empty() || arival <= pq.top().F){
      num_rooms += 1;
      ans[idx] = num_rooms;
      pq.push({departure, num_rooms});
    }else{
      int room_num = pq.top().S; 
      ans[idx] = room_num;
      pq.pop();
      pq.push({departure, room_num});
    }
    
    //print_pq(pq);
  }
  
  cout << num_rooms << endl;
  for(int i = 0; i < n; i ++) cout << ans[i] << " ";
  cout << endl;
  
  
}