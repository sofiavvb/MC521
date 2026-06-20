#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#define MAXN 2000
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define MAXL 20
#define INF (int)(1<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

using namespace std;

vector<int> graph [MAXN]; 
int cap[MAXN][MAXN];

/*
cap[u][v] (sentido original) = capacidade restante (capacidade - fluxo já usado)
cap[v][u] (sentido reverso) = fluxo já enviado nessa aresta
*/

int bfs(int s, int t, vector<int> &parent){
	fill(all(parent), -1);
	parent[s] = 0;
	queue<ii> fila;
	fila.push({s, INF}); // vertice, fluxo
	while (!fila.empty()) 
	{
		auto[u, flow] = fila.front(); fila.pop();
		if (u == t) return flow;
		for (int v : graph[u])
		{
			if (parent[v] == -1 && cap[u][v])
			{
				parent[v] = u;
				int new_flow = min(cap[u][v], flow);
				fila.push({v, new_flow});
			}
		}
	}
	return 0;
}

int max_flow(int s, int t){
	vector<int> parent(MAXN);
	int flow = 0, new_flow;
	while ((new_flow = bfs(s, t, parent))) 
	{
		flow += new_flow;
		int u = t;
		while (u != s) 
		{
			int p = parent[u];
			cap[u][p] += new_flow;
			cap[p][u] -= new_flow;
			u = p;
		}
	}
	return flow;
}

int main()
{_
    // 1 ate n meninos
    // n + 1 ate n + m meninas
    int n, m, u, v, p;
    cin >> n >> m >> p;
    for(int i=0; i < p; i++){
        cin >> u >> v;
        u += 1; // para nao usar o vertice 0
        v += n + 1; 
        if (cap[u][v] == 0 && cap[v][u] == 0) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cap[u][v]++;
    }

    // fonte
    for (int i = 1; i <= n; i++){
        graph[0].push_back(i);
        graph[i].push_back(0);
        cap[0][i] = 1;
    }

    // sorvedouro
    for (int i = n + 1; i <= n + m; i++){
        graph[i].push_back(n + m + 1);
        graph[n + m + 1].push_back(i);
        cap[i][n + m + 1] = 1;
    }

	cout << max_flow(0, n + m + 1) << endl;

    for (int i = 1; i <= n; i++){
        for (int v : graph[i]){
            if (cap[v][i] > 0 && v != 0){
                cout << i - 1 << " " << v - n - 1 << endl;
                break;
            }
        }
    }
    return 0;
}
