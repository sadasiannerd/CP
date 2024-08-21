#include <bits/stdc++.h>
#define ll long long
#define spc " "
#define isWithin(a,b,k) ((b - k <= a && a <= b + k)?1:0)
const ll mod = 1e9 + 7;
using namespace std;

bool comparefn(const int &left, const int &right){
    return left <= right;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);


    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i ++){
        cin >> b[i];
    }
    sort(a.begin(), a.end(), comparefn);
    sort(b.begin(), b.end(), comparefn);

    int ptr1 = 0, ptr2 = 0;
    int res = 0;

    while(ptr1 < n && ptr2 < m){
        if(isWithin(a[ptr1], b[ptr2], k)){
            res += 1;
            ptr1 ++;
            ptr2 ++;
        }else{
        if(a[ptr1] > b[ptr2]) ptr2 ++;
        else ptr1 ++;
        }
    }
    cout << res << endl;

}

int main(){

 solve();

}
