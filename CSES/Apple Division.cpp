#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

ll S = 0;
ll curS = 0;
ll res = INT_MAX;
int a[21];

void BackTrack(int i){
    if(i == -1){
        ll tmp = S - curS;
        res = min(res, abs(tmp - curS));
        return;
    }
    BackTrack(i - 1);
    curS += a[i];
    BackTrack(i - 1);
    curS -= a[i];
}

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> a[i];
        S += a[i];
    }

    BackTrack(n - 1);

    cout << res << endl;

}
