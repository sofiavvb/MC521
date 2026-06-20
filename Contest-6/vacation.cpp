#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAXN 200000
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

using namespace std;

struct activity {
    int a,b,c;
};

int main()
{_

    int n;
    cin >> n;
    int dp[n+1][3];
    vector<activity> days(n+1);
    for (int i = 1; i <= n; i++){
        cin >> days[i].a >> days[i].b >> days[i].c;
    }

    dp[1][0] = days[1].a;
    dp[1][1] = days[1].b;
    dp[1][2] = days[1].c;

    for (int i = 2; i <= n; i++){
        dp[i][0] = days[i].a + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = days[i].b + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = days[i].c + max(dp[i-1][0], dp[i-1][1]);
    }
    int aux = max(dp[n][1], dp[n][2]);
    cout << max(dp[n][0], aux) << endl;
    return 0;
}
