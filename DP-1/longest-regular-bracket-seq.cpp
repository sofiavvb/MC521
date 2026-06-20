#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e15)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 9)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int32_t main()
{_
    string s;
    cin >> s;

    stack<int> pilha;
    pilha.push(-1); // indice do ultimo ')' que n teve par

    int longest = 0;
    int total = 1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            pilha.push(i);
        } else {
            pilha.pop();

            if (pilha.empty()) { // como tem o -1, checa depois
                // vira o novo indice de quebra
                pilha.push(i);
            } else {
                int tamanho = i - pilha.top();

                if (tamanho > longest) {
                    longest = tamanho;
                    total = 1;
                } else if (tamanho == longest) {
                    total++;
                }
            }
        }
    }

    if (longest == 0) {
        cout << "0 1" << endl;
    } else {
        cout << longest << " " << total << endl;
    }

    return 0;
}