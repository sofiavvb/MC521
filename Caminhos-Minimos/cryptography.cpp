#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#define MAXN 100001
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x << 1)
#define dir(x) ((x << 1) | 1)
#define MOD (int)(1e9 + 7) å
#define MAXL 20
#define INF (int)(1LL << 30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

using namespace std;

int main() {
    _ 
    string s, t;
    int n = 94; // total de caracteres possiveis
    int m;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++){
        adj[i][i] = 0;
    }
    cin >> s >> t >> m;
    char a, b;
    int c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a - 33][b-33] = min(adj[a - 33][b-33], c);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (i == k || adj[i][k] == INF)
                continue;
            for (int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int sum = 0;
    for (int i=0; i < s.length(); i++){
        a = s[i] - 33;
        b = t[i] - 33;
        if (adj[a][b] == INF){
            cout << -1 << endl;
            return 0;
        }
        sum += adj[a][b];
    }
    cout << sum << endl;
    return 0;
}
