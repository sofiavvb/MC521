#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip> 
#define MAXN 200000
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

// get it correct to a 10^-9 range -> usar double
int main()
{_
    int n;
    double sum = 0;
    cin >> n;
    vector<double> p(n+1);
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }

    vector<vector<double>> probs(n+1, vector<double>(n+1, 0));
    // 0 caras em 0 moedas
    probs[0][0] = 1.0;
    //  nem precisava disso
    probs[1][1] = p[1];

    // 0 caras em i moedas
    for(int i=1; i<=n; i++){
        probs[i][0] = probs[i-1][0] * (1 - p[i]);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            probs[i][j] = probs[i-1][j] * (1-p[i]) + probs[i-1][j-1] * (p[i]);
        }
    }

    //maioria cara
    for (int i = ceil(n/2.0); i <=n; i++){
        sum += probs[n][i];
    }

    cout << fixed << setprecision(10) << sum << endl;
}
