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
 int a[n];
 ll res = 0;
 for(int i = 0; i < n; i ++){
    cin >> a[i];
    if(i > 0){
        if(a[i] < a[i - 1]){
                res += (a[i - 1] - a[i]);
                a[i] = a[i - 1];
        }

    }
 }

 cout << res;



}
