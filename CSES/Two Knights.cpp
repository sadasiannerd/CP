#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(int k){
    ll n = k * k - 1;

    cout << (n + 1) * n / 2 - max(4*(k - 2)*(k - 1), 0);

    cout << endl;

}

int main(){

 int t;
 cin >> t;
 int i = 1;
 while(i <= t) {
    solve(i);
    i ++;
 }

}
