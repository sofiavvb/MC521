
#include <iostream>
using namespace std;

//3-sum
int main()
{
    int x, n, count;
    while (true) {
        cin >> n >> x;
        if (n == 0 && x == 0) break;
        count = 0;
        for (int i = 1; i <= n; i++) {
            int ini = i + 1;
            int last = n;
            int sum = x - i;
            while(ini < last){
                if (ini + last > sum){
                    last--;
                }else if (ini + last == sum){
                    count++;
                    ini++;
                    last--;
                }else{
                    ini++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}