#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define MAXN 100001
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
vector<int> graph [MAXN]; 

queue<int> get_sources(vector<int> &incoming, int n){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(incoming[i]==0)
            q.push(i);
    }
    return q;
}

vector<int> get_incoming(int n){
    // grau de entrada de cada vertice
    vector<int> incoming(MAXN, 0);
    for(int i=1; i<=n; i++){
        for(int neighbour : graph[i]){
            incoming[neighbour]++;
        }
    }
    return incoming;
}

vector<int> get_order(vector<int> &incoming, queue<int> &sources){
    vector<int> order;
    // tipo bfs
    while(!sources.empty()){
        int node = sources.front();
        sources.pop();
        order.push_back(node);
        for(int neighbour : graph[node]){
            incoming[neighbour]--;
            if(incoming[neighbour]==0)
                sources.push(neighbour);
        }
    }
    return order;
}

vector<int> topological_sort(int n){
    vector<int> incoming = get_incoming(n);
    queue<int> sources = get_sources(incoming, n);
    return get_order(incoming, sources);
}

int main()
{_
    int n, m, u, v;
    cin >> n >> m;
    for (int i=0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> dp(n+1, 0);
    // mesmo usado no problema H
    vector<int> order = topological_sort(n);
    dp[1] = 1;
    for (int u = 0; u < n; u++){
        int node = order[u];
        for(int v : graph[node])
            dp[v] = (dp[node] + dp[v]) % MOD;
    }
    cout << dp[n] % MOD << endl;
    return 0;
}
