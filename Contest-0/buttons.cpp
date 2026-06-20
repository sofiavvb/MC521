#include <iostream>
#define MAXN (int)(1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)å
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{_
    int a, b;
    int sum = 0, first = 0, second = 0;
    cin >> a >> b;

    //aperta os dois
    sum = a + b;
    //aperta o primeiro duas vezes
    first += a;
    a--;
    first += a;
    //aperta o segundo duas vezes
    second += b;
    b--;
    second += b;

    cout << max({first, second, sum}) << endl;
    return 0;
}
