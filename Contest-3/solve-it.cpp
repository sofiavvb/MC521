#include <iostream>
#include <cmath>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
using namespace std;

double binary_search(int p, int q, int r, int s, int t, int u, double low, double high){
    double mid;

    while(high - low > EPS){
        mid = (high + low) / 2.0;
        double result = p * exp(-mid) + q * sin(mid) + r * cos(mid) + s * tan(mid) + t * pow(mid, 2) + u;
        if (result > 0) {
            low = mid;
        } else{
            high = mid;
        }
    }
    return high;
}

int check(int p, int q, int r, int s, int t, int u){
    double a = p * exp(-0.0) + q * sin(0.0) + r * cos(0.0) + s * tan(0.0) + t * pow(0.0, 2) + u;
    double b = p * exp(-1.0) + q * sin(1.0) + r * cos(1.0) + s * tan(1.0) + t * pow(1.0, 2) + u;
    if (a * b > 0){
        return 0; 
    }
    return 1; 
}

int main(){
    int p, q, r, s, t, u;
    while(cin >> p >> q >> r >> s >> t >> u){
        if (check(p, q, r, s, t, u)) {
            double result = binary_search(p, q, r, s, t, u, 0.0, 1.0);
            cout.precision(4);
            cout << fixed << result << endl;
        }
        else{
            cout << "No solution" << endl;
        }
    }
    return 0;
}
