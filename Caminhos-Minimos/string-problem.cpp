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
#define MOD (int)(1e9 + 7) 
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
    int n = 26; // total de caracteres possiveis
    int m;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++){
        adj[i][i] = 0;
    }
    cin >> s >> t >> m;

    if(s.length() != t.length()){
        cout << -1 << endl;
        return 0;
    }

    char a, b;
    int c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a - 'a'][b - 'a'] = min(adj[a - 'a'][b-'a'], c);
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

    //se s[i] for igual a t[i], continue
    // ou troco s[i] por t[i] se der
    // ou troco t[i] por s[i] se der
    // ou troco s[i] para um x e t[i] para o mesmo x, se der
    // tenho que pegar o menor desses custos
    // se nao tiver nenhum que der (custo ficar INF), eh impossivel.
    int sum = 0;
    string res = "";
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        char d = t[i];

        if (c == d){
            res += c;
            continue;
        }

        int best_cost = INF;
        char best_char = ' ';
        for(char ch = 'a'; ch <= 'z'; ch++){
            // se nao der para troca um deles para ch, so vai pro proximo
            if (adj[c - 'a'][ch - 'a'] == INF || adj[d - 'a'][ch - 'a'] == INF){
                continue;   
            }
            int cost = adj[c - 'a'][ch - 'a'] + adj[d - 'a'][ch - 'a'];
            if (cost < best_cost){
                best_cost = cost;
                best_char = ch;
            }
        }   
        if (best_cost == INF){
            cout << -1 << endl;
            return 0;
        }
        sum += best_cost;
        res += best_char;
    }

    cout << sum << endl;
    cout << res << endl;
    return 0;
}
