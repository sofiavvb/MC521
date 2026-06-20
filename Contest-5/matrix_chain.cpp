#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN (int)(1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)å
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

using namespace std;

int matrixChain(vector<ll> &dimensions, int i, int j, vector<vector<ll>> &m){
    if (m[i][j] < INF) return m[i][j];
    if (i == j) return m[i][j] = 0;

    for (int k = i; k < j; k++){
        ll curr = matrixChain(dimensions, i, k, m) + matrixChain(dimensions, k+1, j, m) + dimensions[i] * dimensions[k+1] * dimensions[j+1];
        
        if (curr < m[i][j]){
            m[i][j] = curr;
        }
    }
    return m[i][j];
}

int solve(vector<ll> &dimensions)
{
    int n = dimensions.size();
    vector<vector<ll>> m(n, vector<ll>(n, INF));
    return matrixChain(dimensions, 0, n - 2, m);
}

int main()
{_
    int n, buff;
    cin >> n;
    vector<ll> dimensions(n+1);
    for (int i = 0; i < n - 1; i++){
        cin >> dimensions[i] >> buff;
    }
    cin >> dimensions[n-1] >> dimensions[n];
    cout << solve(dimensions) << endl;
}