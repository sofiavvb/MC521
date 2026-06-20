#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Friend {
    int money;
    int friendship;
};

//sliding window
int main()
{   
    int n, diff;
    cin >> n >> diff;
    vector<Friend> friends(n);
    for (int i = 0; i < n; i++) {
        int money, friendship;
        cin >> money >> friendship;
        friends[i] = {money, friendship};
    }
    //poderia ter feito um vetor de pair com a amizade no first:
    //o sort padrão iria ordenar os amigos do mais pobre para o mais rico automaticamente.
    sort(friends.begin(), friends.end(), [](const Friend& a, const Friend& b) {
        return a.money < b.money;
    });

    int i = 0; //comeco da janela
    long long max_factor = friends[i].friendship;
    long long window = max_factor;

    for (int j = 1; j < n; j++){ //aponta pro final da janela
        window += friends[j].friendship;

        while (friends[j].money -  friends[i].money >= diff){ //enquanto se sentir pobre, diminui o inicio
            window -= friends[i].friendship;
            i++;
        }

        if (window > max_factor){
            max_factor = window;
        }
    }
    cout << max_factor << endl;
    return 0;
}