#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#define MAXN 100001
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

vector<int> graph [MAXN]; 
vector<bool> visited(MAXN, false);
vector<bool> path (MAXN, false);

bool dfs(int v) {
    visited[v] = true;
    path[v] = true;
    for(int u : graph[v]){
        if(!visited[u]){
            if(dfs(u)){
                return true;
            }
        }else if(path[u]){
            return true;
        }
    }
    path[v] = false;
    return false;

}

bool hasCycle(int n){
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            if (dfs(i)){
                return true;
            }
        }
    }
    return false;
}

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
    for(int i=0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }
    //checar se tem ciclo
    if (hasCycle(n)){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    //topo sort
    vector<int> order = topological_sort(n);
    for(int i =0; i < n; i++){
        if (i == n-1){
            cout << order[i] << endl;
        }else{
            cout << order[i] << " ";
        }
    }
    return 0;
}

/*

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int in_degree[MAXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    // pega as fontes 
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    // adiciona os vertices "fontes" (grau de entrada 0) na fila
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(in_degree[i] == 0) q.push(i);
    }

    vector<int> result;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for(int v : adj[u]) {
            in_degree[v]--;
            if(in_degree[v] == 0) q.push(v);
        }
    }
    // se o tamanho do resultado for diferente de n, tem ciclo
    if(result.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(int i = 0; i < n; i++) {
            cout << result[i] << (i == n-1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}

\*/