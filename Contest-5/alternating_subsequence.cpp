#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN (int)(1e6 + 10)
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

int main()
{_
    
    int t, n;
    ll curr, prev;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        vector<ll> numbers(n);
        for (int j = 0; j < n; j++){
            cin >> numbers[j];
        }
        ll sum = 0;
        ll max = numbers[0];
        prev = max;
        for (int j = 1; j < n; j++){
            curr = numbers[j];
            if (curr * prev < 0){
                sum += max;
                max = curr;
            }else{
                if (curr > max) {
                    max = curr;
                }
            }
            prev = curr;
        }
        sum += max;
        cout << sum << endl;
    }

}