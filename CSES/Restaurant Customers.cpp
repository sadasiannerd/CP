#include <bits/stdc++.h>
#define ll long long
#define spc " "
const ll mod = 1e9 + 7;
using namespace std;

typedef pair<int, int> ctm;

bool comparefn(const ctm &left, const ctm &right){
    return (left.second <= right.second);
}

void print_queue(std::queue<int> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}

void solve(){
    int n;
    cin >> n;
    vector<ctm> v;

    for(int i = 0; i < n; i ++){
        int first, second;

        cin >> first >> second;

        pair<int, int> p = {first, second};

        v.push_back(p);
    }

    sort(v.begin(), v.end(), comparefn);

    //for(auto &pr: v) cout << pr.first << spc << pr.second << endl;

    queue<int> q;

    int res = 0;

    for(const auto &tup: v){
        if(q.empty()) q.push(tup.second);
        else{
            if((tup.first) < q.front())
                q.push(tup.second);
            else{
                    while((tup.first) >= q.front()) q.pop();
                    q.push(tup.second);
            }
        }
        //print_queue(q);
        res = max(res, (int)q.size());
    }

    cout << res << endl;

}

int main(){

 solve();

}
