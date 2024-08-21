#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){
    int x, y;
    cin >> x >> y;

    int layer = max(x, y);
    int pos = min(x, y);

    if (layer % 2 == 0)
    {
        if (pos == x) cout << (ll) (layer - 1)*(layer - 1) + pos;
        else  cout << (ll) layer * layer - pos + 1;
    }else{
        if (pos == x) cout << (ll) layer * layer - pos + 1;
        else cout << (ll) (layer - 1)*(layer - 1) + pos;
    }
    cout << endl;
}

int main(){

 int t;
 cin >> t;

 while(t--) solve();

}
