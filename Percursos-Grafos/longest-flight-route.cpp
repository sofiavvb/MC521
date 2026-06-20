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
#define MOD (int)(1e9 + 7)
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

using namespace std;

vector<int> graph [MAXN]; 
vector<bool> visited(MAXN, false);
vector<int> topoSort;

/* Quase todo problema que pede para contar caminhos,
achar maior/menor caminho ou acumular valores e garante que o grafo é um DAG,
é resolvido com DP processando os vértices na ordem topológica. */


/*
dp[v] indica o maior caminho que termina em v.
dp[v] = max(dp[v], dp[u] + 1).

precisamos ordenar os vértices topologicamente para que quando
calculamos dp[v] já tenhamos calculado o dp de todos os seus predecessores.

*/
void printPath(int u, vector<int> &parent){
    if (u == 1){
        cout << u;
        return;
    };
    printPath(parent[u], parent);
    cout << " " << u;
}

void dfs(int v) {
    visited[v] = true;
    for(int u : graph[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
    topoSort.push_back(v);
}

int main()
{_
    int n, m, u, v;
    topoSort.clear();
    cin >> n >> m;
    for (int i=0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }

    //se nao for alcancavel a partir de 1
    dfs(1);
    if(!visited[n]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    reverse(all(topoSort));
    vector<int> parent(n+1,0);
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for (int u : topoSort){
        for (int vizinho : graph[u]){
            if((dp[u] + 1) > dp[vizinho]){
                dp[vizinho] = dp[u] + 1;
                parent[vizinho] = u;
            }
        }
    }
    cout << dp[n] << endl;
    printPath(n, parent);
    cout << endl;
    return 0;
}
