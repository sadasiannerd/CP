#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n; cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i ++) cin >> b[i];

    vector<int> pref_max(n);
    vector<int> suff_max(n);

    for(int i = 0; i < n; i ++){
        pref_max[i] = b[i] + i;
        suff_max[i] = b[i] - i;
    }

    for(int i = 1; i < n; i ++){
        pref_max[i] = max(pref_max[i - 1], pref_max[i]);
    }



    for(int i = n - 2; i >= 0; i --){
        suff_max[i] = max(suff_max[i + 1], suff_max[i]);
    }

    int res = INT_MIN;
    for(int i = 1; i < n - 1; i ++){
        res = max(res, pref_max[i - 1] + b[i] + suff_max[i + 1]);
    }

    cout << res << endl;

}


int main(){
    int t; cin >> t;
    while(t--) solve();
}
