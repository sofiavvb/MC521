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

    int n;
    int counter = 1;
    while(true){
        cin >> n;
        if (!n){
            break;
        }

        unordered_map<string, int> nomes;
        string moeda;
        for(int i = 0; i < n; i++){
            cin >> moeda;
            nomes[moeda] = i;
        }

        int m;
        double value;
        cin >> m;
        vector<vector<double>> adj(n, vector<double>(n, INF));
        for(int i = 0; i < n; i++){
            adj[i][i] = 0;
        }
        string a, b;
        for(int i = 0; i < m; i++){
            cin >> a >> value >> b;
            int idA = nomes[a];
            int idB = nomes[b];
            adj[idA][idB] = -log(value);
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
        string res = "No";
        for(int i = 0; i < n; i++){
            if (adj[i][i] < 0){
                res = "Yes";
            }
        }
        cout << "Case " << counter << ": " << res << endl;
        counter++;
    }

    return 0;
}
