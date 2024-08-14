#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<int, int> interval;

bool comparefn(const int &left, const int &right){
  return (left <= right);
}

void printQueue(queue<int> q){
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}
int main() 
{
  int n;
  cin >> n;
   queue<int> q;
  for(int i = 1; i <= n; i++)  q.push(i);
  bool isKilled = false;
  while(!q.empty()){
    //printQueue(q);
    queue <int> new_q;
    while(!q.empty()){
      if(!isKilled) new_q.push(q.front());
      else cout << q.front() << " ";
      isKilled = !isKilled;
      q.pop();
    }
    queue<int> &new_q_ref = new_q;
    q = new_q_ref;
  }
  
  cout << endl;
  
}