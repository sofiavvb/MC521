#include <bits/stdc++.h>
// #define int long long
#define MAXN (int)(1e5 + 10)
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

ii dfs(vector<vector<int>> &graph, vector<int> &visited, int u){
    int vertices = 1, edges =0;
    visited[u]++;
    for(auto v: graph[u]){
        edges++;
        if(!visited[v]){
            ii p = dfs(graph, visited, v);
            vertices += p.first;
            edges += p.second;
        }
    }
    return {vertices, edges};
}

int32_t main()
{_

    int n, m, r,e;
    int a,b;
    while(cin >> n >> m >> r >> e){
        vector<vector<int>> graph(n+1, vector<int>());
        for(int i=0; i<m; i++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> visited(n+1, 0);
        int cost_stadium = 0;
        int cost_rodovias = 0;
        int cost =0;
        for(int i = 1; i <= n; i++){
            int cost_stadium = 0;
            int cost_rodovias = 0;
            if(!visited[i]){
                auto [vertices, edges] = dfs(graph, visited, i);
                if(vertices == 1){
                    continue;
                }
                cost_stadium = vertices * e;
                edges /= 2;
                cost_rodovias = ((vertices * (vertices -1))/2 - edges) * r;
                cost += min(cost_rodovias, cost_stadium);
            }
        }
        cout << cost << endl;
    }
    return 0;
}
