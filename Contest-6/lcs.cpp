#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
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

// LCS mas printar a subsquencia
void lcs(string &s1, string &s2){
    int s = s1.size(); int t = s2.size();
    vector<vector<int>> dp(s + 1, vector<int>(t + 1, 0));

    for(int i = 1; i <= s; i++){
        for(int j = 1; j <= t; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string lcs = "";
    while(s > 0 && t >0 && dp[s][t] > 0){
        if (s1[s-1] == s2[t-1]){
            lcs.push_back(s1[s-1]);
            s--;
            t--;
        }else{
            if(dp[s-1][t] > dp[s][t-1]){
                s--;
            }else{
                t--;
            }
        }
    }
    reverse(all(lcs));
    cout << lcs << endl;
}

int main()
{_
    string s, t;
    cin >> s >> t;
    lcs(s, t);
    return 0;

}
