#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int32_t main()
{_
    int n;
    cin >> n;
    vector<ii> mov(n);
    for(int i = 0; i < n; i++){
        cin >> mov[i].second >> mov[i].first;
    }
    sort(all(mov));

    int time = 0;
    bool skipped = false;
    for(int i = 0; i < n; i++){
        time += mov[i].second;
        if (mov[i].first < time){
            skipped = true;
            break;
        }
    }
// comentando pra submeter dnv
    if (skipped) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
