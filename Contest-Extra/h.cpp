#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define rloop(i, n) for(int i = n-1; i >=0; i--)
#define pb push_back
#define srt(a) sort(a.begin(), a.end())

#define MOD 1000000007

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vc = vector<char>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;
using vll = vector<ll>;
bool sortB(pair<int, int> i, pair<int, int> j){ return (i.first < j.first);}
bool sortE(pair<int, int> i, pair<int, int> j){ return (i.second < j.second);}

void solve(){
    int n;
    string a;


    while(cin >> n){

        int cnt = 0;
        while (n > 0){
            a = to_string(n);
            srt(a);
            n = n-stoi(a);
            cnt++;
        }
        cout << cnt << endl;
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}