#include <iostream>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{_
    int rounds, a, d;
    int antonia = 100, david = 100;
    cin >> rounds;

    for (int i = 0; i < rounds; i++){
        cin >> a >> d;
        //se antonia ganha
        if(a > d){
            david -= a;
        }else if(a < d){
            antonia -= d;
        }
    }
    cout << antonia << endl;
    cout << david << endl;
    return 0;
}