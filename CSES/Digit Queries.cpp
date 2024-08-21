#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;


ll pow10[19];

ll quick_pow10(ll n)
{
    return pow10[n];
}

void solve(){
    ll n;
    cin >> n;

    ll c = 1;
    ll N, M;
    N = 1;
    M = 9;

    ll cur = 0;

    while(cur + (M - N + 1)*c < n){
        cur += (M - N + 1) * c;
        M = M * 10 + 9;
        N *= 10;
        c += 1;
    }

    ll remaining = n - cur;
    ll offset = remaining / c;
    ll base = quick_pow10(c - 1) - 1;
    ll loc = base +  offset;
    ll pos = remaining % c;


    if(pos == 0){
        int tmp = loc % 10;
        cout << to_string(tmp) << endl;
    }else{
        loc ++;
        string tmp = to_string(loc);
        cout << tmp[pos - 1] << endl;
    }



}

int main(){

 pow10[0] = 1;
 for(int i = 1; i <= 18;i ++){
    pow10[i] = pow10[i - 1] * 10;
 }

 int t;
 cin >> t;

 while(t--) solve();

}
