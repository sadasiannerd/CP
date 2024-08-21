#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

ll Pow(ll i){
    if(i <= 0) return 1;

    return 2* Pow(i - 1) % mod;

}

int main(){

 ll n;

 cin >> n;

 cout << Pow(n) % mod;

}
