#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

bool comparefn(const int &left, const int &right){
    return (left <= right);
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> p((const int) n);
    for(int i = 0; i < n; i ++) cin >> p[i];

    sort(p.begin(), p.end(), comparefn);

    int ptr1 = 0;
    int ptr2 = n - 1;

    int res = 0;

    while(ptr1 <= ptr2){
        res ++;
        int prev = p[ptr2];
        ptr2 --;
        if(prev + p[ptr1] <= x) ptr1 ++;
    }

    cout << res << endl;

}

int main(){

 solve();

}
