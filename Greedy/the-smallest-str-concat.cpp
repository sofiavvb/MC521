#include <bits/stdc++.h>
#include <string.h>
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

bool comp(string a, string b){
    string opt1 = a + b;
    string opt2 = b + a;
    return (opt1 < opt2);
}

int32_t main()
{_
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(all(s), comp);
    for (int i = 0; i < n; i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}