#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>
using namespace std;

int check(string substr) {
    if (substr == "axa" || substr == "ixi" || substr == "exe" || 
        substr == "oxo" || substr == "uxu") {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    //da primeira ate a antepenultima, checo se a tupla de 3 entra nas combinacoes la
    //se sim, replace por ... e pulo 3 caracteres
    //se n, ando 1 e checo de novo
    for (int i = 0; i < n - 2; i++) {
        if (check(s.substr(i, 3))) {
            s[i] = '.';
            s[i + 1] = '.';
            s[i + 2] = '.';
            i += 2;
        }
    }
    
    cout << s << endl;
    return 0;
}