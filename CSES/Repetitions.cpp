#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){
    string s;
    cin >> s;
    int res = 0;
    int cur = 0;
    for(int i = 1; i < s.size(); i ++){
        if(s[i] == s[i - 1]){
            cur = cur + 1;
            res = max(res, cur);
        }else{
            cur = 0;
        }
    }

    cout << res + 1 << spc;


}

int main(){

 solve();

}
