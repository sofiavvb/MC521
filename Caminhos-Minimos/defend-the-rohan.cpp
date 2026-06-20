#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <vector>
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
    int t, vertices, r, s, d;
    cin >> t;
    int counter = 1;
    while (counter <= t) {
        cin >> vertices;
        vector<vector<int>> adj(vertices, vector<int>(vertices, INF));
        int n = adj.size();

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cin >> adj[i][j];
            }
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

        cin >> r;
        int total = 0;
        for (int i = 0; i < r; i++) {
        cin >> s >> d;
        s--;
        d--;
        total += adj[s][d];
        }
        cout << "Case #" << counter << ": " << total << endl;
        counter++;
    }
    return 0;
}
