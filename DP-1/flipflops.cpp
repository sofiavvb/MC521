#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e6 + 10)
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

int32_t main()
{_
    int t;
    cin >> t;

    int n, c, flipflops;
    vector<int> monsters;


    while(t--) {
        cin >> n >> c >> flipflops;

        monsters.resize(n);
        for(int i=0; i<n; i++) {
            cin >> monsters[i];
        }

        sort(all(monsters));

        for(int i=0; i< n; i++) {
            if(c < monsters[i]) {
                break;
            }

            int dif;
            dif = c - monsters[i];
            if(flipflops > dif) {
                monsters[i] += dif;
                flipflops -= dif;
            } else {
                monsters[i] += flipflops;
                flipflops = 0;
            }
            
            c += monsters[i];
        }

        cout << c << '\n';
    }
}
