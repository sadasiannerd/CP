#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<int, int> interval;

bool comparefn(const int &left, const int &right){
  return (left <= right);
}

int main() 
{
  int x, n;
  cin >> x >> n;
  multiset<pair<int, int>> intervals;
  intervals.insert({0, x});
  multiset<ll> lengths;
  lengths.insert(x);
  for(int i = 0; i < n; i ++)
  {
    int p;
    cin >> p;
    auto it = intervals.upper_bound({p, 0});
    it --;
    
    int start = it -> first;
    int end = it -> second;
  
    lengths.erase(lengths.find(end - start));
    
    lengths.insert(end - p);
    lengths.insert(p - start);
    
    intervals.erase(it);
    intervals.insert({start, p});
    intervals.insert({p, end});
    
    cout << *lengths.rbegin() << endl;
    
  }
}