#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){
    int n;
    cin >> n;

    int i = 2;
    int ni = 0;

    while(i <= n){
        ni += n / i;
        i *= 2;
    }

    int j = 5;
    int nj = 0;
    while(j <= n){
        nj += n / j;
        j *= 5;
    }

    cout << min(ni, nj)<< endl;
}

int main(){

 int t = 1;

 while(t--) solve();

}
