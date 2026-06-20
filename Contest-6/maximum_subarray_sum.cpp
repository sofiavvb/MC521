#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 200000
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)å
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

using namespace std;

// Maximum Subarray Sum
int main()
{_
    int numbers[MAXN];
    ll dp[MAXN + 1];
    int n, choice;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    dp[0] = 0;
    ll max_sum = 0;
    for (int i = 0; i < n; i++){
        dp[i + 1] = max((ll) 0, dp[i] + numbers[i]);
        max_sum = max(max_sum, dp[i+1]);
    }
    choice = numbers[0];
    // se for 0
    if (!max_sum) {
        for (int i = 1; i < n; i++){
            if (numbers[i] <= 0){
                choice = max(choice, numbers[i]);
            }
        }
        max_sum = choice;
    }
    cout << max_sum << endl;
    return 0;

}