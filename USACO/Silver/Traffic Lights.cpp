#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
  int street_len, light_num;
  
  cin >> street_len >> light_num;
  
  set<int> lights{0, street_len};
  multiset<int> dist{street_len};
  while(light_num --){
    int cur_light; cin >> cur_light;
    auto it1 = lights.upper_bound(cur_light);
    auto it2 = it1;
    --it2;
    
    lights.insert(cur_light);
    dist.erase(dist.find(*it1 - *it2));
    dist.insert(*it1 - cur_light);
    dist.insert(cur_light - *it2);
  
    auto ans_it = dist.end();
    -- ans_it;
    
    cout << *ans_it  << " ";
  }
  

  
}
  
  
  
  
