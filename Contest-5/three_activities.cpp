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
    int t, n, day;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        vector<ii> ski(n), movie(n), games(n);
        for (int j = 0; j < n; j++){
            cin >> day;
            ski[j] = {day, j};
        }
        for (int j = 0; j < n; j++){
            cin >> day;
            movie[j] = {day, j};
        }
        for (int j = 0; j < n; j++){
            cin >> day;
            games[j] = {day, j};
        }
        sort(all(ski)); sort(all(movie)); sort(all(games));
        int max = -1, sum = 0;
        for(int k = n - 1; k > n - 4; k--){
            int a = ski[k].first, day = ski[k].second;
            for (int j = n - 1; j > n - 4; j--){
                int b = movie[j].first, day2 = movie[j].second;
                if (day == day2) continue;
                for (int l = n - 1; l > n - 4; l--){
                    int c = games[l].first, day3 = games[l].second;
                    if (day == day3 || day2 == day3) continue;
                    sum = a + b + c;
                    if (sum > max){
                        max = sum;
                    }
                }
            }
        }
        cout << max << endl;
    }
}