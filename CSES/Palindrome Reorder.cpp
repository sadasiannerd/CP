#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){
    string s;
    cin >> s;

    map<char, int> m;

    for(const char &c: s){
        m[c] ++;
    }

    int mid = -1;

    bool res = false;

    for(auto itr = m.begin(); itr != m.end(); itr ++){
        if(itr -> second % 2 == 0) continue;

        if(mid == -1){
          mid = (int) itr -> first;
          m[itr->first] -= 1;
        }else{
            res = true;
            break;
        }
    }
    if(res) cout << "NO SOLUTION" << endl;
    else{
        for(auto itr = m.begin(); itr != m.end(); itr ++){
            for(int i = 0; i < itr -> second / 2; i ++)
                cout << itr -> first;
        }

        if(mid != -1){
            cout << (char) mid;
        }
        for (auto it = m.cend(); it != m.begin(); it--) {
            auto itr = it;
            itr--;
            for (int i = 0; i < itr->second / 2; i++) {
                cout << itr->first;
        }
}
    }

}

int main(){

 int t = 1;

 while(t--) solve();

}
