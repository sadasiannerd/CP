/*
Description: always greedily maximize the amount of money you can get at the current time,
whether it is selling milk or renting, selling milk is associated with milk amount so when
renting cows always lend the cow with the current lowest milk amount.
*/

#include <bits/stdc++.h>
#define ll long long
#define ar array
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
using namespace std;

int main() {
  int n, m, r; cin >> n >> m >> r;
  
  vector<int> milk_amt(n);
  for(int i = 0; i < n; i ++) cin >> milk_amt[i];
  
  vector<pair<int,int>> shops(m);
  for(int i = 0; i < m; i ++) cin >> shops[i].s >> shops[i].f;
  
  vector<int> rent(r);
  for(int i = 0; i < r; i ++) cin >> rent[i];
  
  sort(all(milk_amt), greater<int>());
  sort(all(shops), greater<pair<int,int>>());
  sort(all(rent), greater<int>());
  
  int shop_at = 0;
  int rent_at = 0;
  int cow_at = 0;
  ll max_money = 0;
  while(cow_at < n){
    int amt = milk_amt[cow_at];
    int sold_money = 0;
    int curr_shop = shop_at;
    int last = 0; //only update the amount of the last store
    
    while(curr_shop < m){
      int sold = min(amt, shops[curr_shop].s);
      sold_money += shops[curr_shop].f * sold;
      amt -= sold;
      
      if(amt == 0){
        last = sold;
        break;
      }else{
        curr_shop ++;
      }
    }
    
    if(rent_at >= r || sold_money > rent[rent_at]){
      max_money += sold_money;
      shop_at = curr_shop;
      if(shop_at < m){ shops[shop_at].s -= last; }
      cow_at ++;
    }else{
      max_money += rent[rent_at];
      /*
			 * instead of renting this cow, it's better to rent off
			 * the cow that makes the least amount of milk
			 * (we don't process the cow at the end of the list)
			 */
      n --;
      rent_at ++;
    }
  }
  
  cout << max_money << endl;
  
  
  
}

  
  
  
  
  
  
  
  
}
