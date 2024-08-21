#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){
    ll n;
    cin >> n;
    cout << n << spc;
    while(n != 1){
        if (n%2 == 1) n = n * 3 + 1;
        else n = n / 2;
        cout << n << spc;
    }
    cout << endl;

}

int main(){

 int t = 1;
 //cin >> t;

 while(t--) solve();

}
