#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n - 1];
    bool b[n + 1];

    for(int i = 0; i <= n; i ++){
        b[i] = false;
    }

    for(int i = 0; i < n - 1; i ++){
        cin >> a[i];
        b[a[i]] = true;
    }
    for (int i = 1; i <= n; i ++){
        if(!b[i])
        {cout << i; break;}
    }

    cout << endl;


}

int main(){

 int t ;
 //cin >> t;

 while(t--) solve();

}
