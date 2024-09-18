/*
Name: Vu Thanh Loc Mai
Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=940
Category: Graph
Description: 
- The original representation is a tree. With directed edges, the graph is a DAG
- Node that can be reached by all other nodes must be node with out-degree = 0 and there is 1 single node like that in the graph
- Therefore the DAG is also a successor graph to satisfy the condition
- For any node with multiple child we know that there is no node that satisfies
- Exclude those cases we are left with linked nodes, we try to reach the end of each chain
- Return the answer if all nodes end up at the same node
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int find(int a, map<int, int> &next){
  if(next[a] != a){
    next[a] = find(next[a], next);
  }
  return next[a];
}


int main() 
{
  int n; cin >> n;
  map <int, int> next;
  for(int i = 1; i <= n; i ++){
    next[i] = i;
  }
  for(int i = 1; i <= n - 1; i ++){
    int a, b; cin >> a >> b;
    if(next[a] != a){
      cout << -1 << endl;
      return 0;
    }
    next[a] = b;
  }
  
  int prev_dest = find(1, next);
  for(int i = 2; i <= n; i ++){
    int dest = find(i, next);
    if(dest != prev_dest){
      cout << -1 << endl;
      return 0;
    }
  }
  
  cout << prev_dest << endl;
  
}