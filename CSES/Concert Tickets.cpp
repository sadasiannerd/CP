#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;



bool comparefn(const int &left, const int &right){
    return (left <= right);
}

int bSearchLeft(vector<int> x, int y){
    int low = 0, high = x.size() - 1;
    while(low <= high){
    int mid = (low + high)/2;
    if(x[mid] == y) return mid;
    else if(x[mid] < y) low = mid + 1;
    else high = mid - 1;
    }
    return ((high < x.size() && x[high] == min(x[low],x[high]))?high:low);
}

void solve(){
    int n, m;
    cin >> n >> m;

    map<int, int> freq;

    for(int i = 0; i < n; i ++){
        int h;
        cin >> h;
        freq[h] ++;
    }


    for(int i = 0; i < m; i ++){
        int t;
        cin >> t;
        auto u = freq.upper_bound(t);
        if(u == freq.begin()){
            cout << "-1" << endl;
        }
        else{
            cout << ((--u)->first) << endl;
            u->second --;
            if(u->second == 0) freq.erase(u);
        }

    }




    /*int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), comparefn);

    cout << a[bSearchLeft(a, m)] << endl;*/




}

int main(){

 solve();

}
