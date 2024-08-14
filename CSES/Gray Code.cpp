// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

set<string> s;

void printBin(int x, int n){
    string r = "";
    for(int i = 1; i <= n; i ++)
    {
        r = (x % 2 == 0? "0":"1") + r;
        x >>= 1;
    }

    cout << r << endl;
}   



int main() {
    int n;    
    cin >> n;

    vector<int> ans;
    ans.push_back(0);

    for(int y = 1; y <= (1 << n); y++){
        ans.push_back(ans.back() ^ (y&-y));
    }

    for(int i = 0; i < ans.size(); i ++)
    printBin(ans[i], n);
}