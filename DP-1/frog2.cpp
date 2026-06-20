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

    int n, k, cost;
    cin >> n >> k;
    vector<int> costs(n);
    for (int i = 0; i < n; i++){
        cin >> cost;
        costs[i] = cost;
    }   

    if(k >= n) {
        k = n-1;
    }
    vector<int> dp(n, 0);
    dp[n - 1] = 0;

    for(int i = n - 2; i >= 0; i--){
        dp[i] = INF;
        for (int j = i + 1; (j < n && j <= i + k); j++){
            int atual = abs(costs[j] - costs[i]) + dp[j];
            if (atual < dp[i]){
                dp[i] = atual;
            }
        }
    }
    
    cout << dp[0] << endl;
    return 0;
}
