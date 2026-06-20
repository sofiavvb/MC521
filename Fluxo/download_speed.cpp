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
#define INF (ll)(1LL<<60)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

using namespace std;

vector<int> graph [MAXN]; 
ll cap[MAXN][MAXN];

ll bfs(int s, int t, vector<int> &parent){
	fill(all(parent), -1);
	parent[s] = 0;
	queue<pair<int, ll>> fila;
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
				ll new_flow = min(cap[u][v], flow);
				fila.push({v, new_flow});
			}
		}
	}
	return 0;
}

ll max_flow(int s, int t){
	vector<int> parent(MAXN);
	ll flow = 0, new_flow;
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
    int n, m, u, v;
    ll c;
    cin >> n >> m;
    for(int i=0; i < m; i++){
        cin >> u >> v >> c;
        if (cap[u][v] == 0 && cap[v][u] == 0) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cap[u][v] += c;
    }
	cout << max_flow(1, n) << endl;
}
