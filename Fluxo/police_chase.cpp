#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#define MAXN 501
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
    int n, m, u, v, c;
    cin >> n >> m;
    for(int i=0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cap[u][v] = 1; 
        cap[v][u] = 1;
    }
	int quantidade = max_flow(1, n);
	cout << quantidade << endl; // max flow - min cut amo

    // componente S
    vector<bool> visited(MAXN, false);
    queue<int> fila;
    fila.push(1);
    visited[1] = true;
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        for(int v : graph[u]){
            if(!visited[v] && cap[u][v] > 0){
                visited[v] = true;
                fila.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int v : graph[i]){ 
            if (visited[i] && !visited[v]){  // i em S e v nao
                cout << i << " " << v << endl; 
            }
        }
    }
}
