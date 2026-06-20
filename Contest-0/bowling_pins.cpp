#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
    //fiz assim para aprender um pouco de bitset mas a logica desse problema mais simples seria:

    // Mapeamento direto: pino i pertence à coluna col_map[i]
    // int col_map[] = {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};
    // vector<bool> has_pin(7, false);

    // for(int i = 0; i < 10; i++) {
    //     if(s[i] == '1') has_pin[col_map[i]] = true;
    // }

    // tambem daria para fazer com essa logica mais rapida o loop.
    // FSM: Procura o padrão 1 -> 0 -> 1 (Pino, Buraco, Pino)
    // int state = 0; 
    // for (bool ok : has_pin) {
    //     if (state == 0 && ok) state = 1;      // Encontrou primeiro pino
    //     else if (state == 1 && !ok) state = 2; // Encontrou buraco
    //     else if (state == 2 && ok) return true; // Encontrou segundo pino após buraco
    // }
    // return false;

    string pinsStr;
    bitset<10> columns[7] = {
        0b0001000000,
        0b0000001000,
        0b0010000010,
        0b0000010001,
        0b0100000100,
        0b0000100000,
        0b1000000000,
    };
    cin >> pinsStr;
    reverse(pinsStr.begin(), pinsStr.end());
    bitset<10> pins(pinsStr);
    bool hasPin[7];

    //se o pin zero ta levantado, n eh split
    if (pins[0]){
        cout << "No" << endl;
        return 0;
    }

    //para cada coluna, ve se temos algum pin up nela
    for(int i = 0; i < 7; i++){
        hasPin[i] = (columns[i] & pins).any();
    }

    //checar condicao 2
    for(int i = 0; i < 7; i++){
        if(hasPin[i]){
            for(int j = i + 1; j < 7; j++){
                if(!hasPin[j]){
                    for(int k = j + 1; k < 7; k++){
                        if(hasPin[k]){
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}