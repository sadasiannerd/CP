#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){

    ll n;

    cin >> n;

    ll s = (n + 1) * n / 2;

    if(s % 2 != 0)
        cout << "NO" <<endl;
    else{
        cout << "YES"<<endl;

        s = s / 2;

        vector <int> m;

        vector <int> set1;

        for(int i = 1; i <= n; i ++)
            m.push_back(i);

        while (s > m.back()){
            int tmp = m.back();
            s -= tmp;
            set1.push_back(tmp);
            m.pop_back();
        }
        set1.push_back(s);

        cout << set1.size() <<endl;

        for(int i = 0; i < set1.size(); i ++)
            cout << set1[i] << spc;

        cout << endl;

        cout << m.size() - 1 << endl;

        for(int i = 0; i < m.size(); i ++){
            if(m[i] != s) cout << m[i] << spc;
        }

        cout << endl;

    }

}

int main(){

 int t = 1;

 while(t--) solve();

}
