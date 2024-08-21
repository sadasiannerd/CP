#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

set<string> hashSet;
vector<string> ans;

void permutations(string s, int i, int n){
    if(i == n - 1){
        if(!hashSet.count(s)){
            ans.push_back(s);
            hashSet.insert(s);
        }
        return;
    }

    for(int j = i; j < n; j ++){
        swap(s[i], s[j]);
        permutations(s, i + 1, n);
        swap(s[i], s[j]);
    }

}

int cf[9];

int f(int n){
    if(n <= 1)
        return 1;
    if(cf[n] != -1) return cf[n];
    cf[n] =  n * f(n - 1);
    return cf[n];
 }

int main(){

 for(int i = 0; i < 9; i ++){
    cf[i] = -1;
 }

 string s;
 cin >> s;

 int N = s.size();

 map<char, int> m;

 for(const char &c : s){
    m[c] ++;
 }

 int res = f(N);

 for(const auto &v: m)
    res /= f(v.second);

 cout << res << endl;

 permutations(s, 0, N);

 sort(ans.begin(), ans.end());

 for(int i = 0; i < res; i++)
    cout << ans[i] << endl;

}
