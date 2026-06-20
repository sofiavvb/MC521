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

    int n, cost;
    cin >> n;
    vector<int> costs(n);
    for (int i = 0; i < n; i++){
        cin >> cost;
        costs[i] = cost;
    }   
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(costs[1] - costs[0]);
    for (int i = 2; i < n; i++){
        dp[i] = min(dp[i-1] + abs(costs[i] - costs[i-1]), dp[i-2]+ abs(costs[i] - costs[i-2]));
    }
    cout << dp[n-1] << endl;
    return 0;
}
