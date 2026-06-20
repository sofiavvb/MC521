#include <bits/stdc++.h>
#include <string.h>
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
    vector<ii> mov;
    set<int> trees;
    vector<int> x(n), h(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> h[i];
        trees.insert(x[i]);
    }
    for (int i=0; i<n; ++i) {
        trees.erase(x[i]);
        auto q = trees.lower_bound(x[i] - h[i]);
        if (q == trees.end() || *q > x[i]) {
            mov.push_back({x[i], x[i] - h[i]});
        }
        q = trees.lower_bound(x[i]);
        if (q == trees.end() || *q > x[i] + h[i]) {
            mov.push_back({x[i] + h[i], x[i]});
        }
        trees.insert(x[i]);
    }


    sort(all(mov));

    int tot = 1, curr = 0;
    for(int i = 1; i < mov.size(); i++){
        if (mov[i].second > mov[curr].first){
            tot++;
            curr = i;
        }
    }
    cout << tot << endl;
    return 0;
}
