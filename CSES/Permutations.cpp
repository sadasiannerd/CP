#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

void solve(){


}

int main(){

 int n;
 cin >> n;

 if(n == 1) cout << "1" << endl;

 if(n <= 3 && n > 1) cout << "NO SOLUTION" << endl;

 if(n == 4) cout << "2 4 1 3" << endl;

 if(n >= 5){
    for (int i = 1; i <= n; i += 2)
        cout << i << spc;
    for (int i = 2; i <= n; i += 2)
        cout << i << spc;

    cout << endl;
 }


}
