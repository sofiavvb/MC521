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
    int n, s, j, d;
    while(cin >> n >> s >> j >> d){
        int a = 0, b = 0;
        int sa = 0, sb = 0;
        string line;
        cin >> line;
        
        loop(i, line.size()){
            if (line[i] == 'A') a++;
            else b++;
            if (a >= j && a-b >=d){
                sa++;
                a = 0;
                b = 0;
            }
            if(b >= j && b-a >= d){
                sb++;
                a = 0;
                b = 0;
            }
        }

        cout << sa << ' ' << sb << endl;

    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}