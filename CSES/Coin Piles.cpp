#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){

    ll a, b;
    cin >> a >> b;

    ll c = (a + b) / 3;

    ll d = (b - a) + c;

    ll e = c - (b - a);


    cout << ((a + b) % 3 == 0 && d % 2 == 0 && d >= 0 && e >= 0? "YES" : "NO");

    cout << endl;
}

int main(){

 int t;
 cin >> t;

 while(t--) solve();

}
