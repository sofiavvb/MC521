#include <iostream>
#include <string>
using namespace std;

int main()
{
    int maxLenght = 0;
    string s;
    cin >> s;
    int lenght = s.size() - 1;
    //para cada possivel tamanho da substring (comeco de n - 1, maiores antes)
    // vejo as substrings e a quantidade de vezes que cada aparece.
    // se a quantidade for maior ou igual a 2, entao atualizo o maxLength
    while (lenght > 0) {
        for (int i = 0; i <= s.size() - lenght; i++) {
            string sub = s.substr(i, lenght);
            int count = 0;
            for (int j = 0; j <= s.size() - lenght; j++) {
                if (s.substr(j, lenght) == sub) {
                    count++;
                }
            }
            if (count >= 2) {
                maxLenght = lenght;
                break;
            }
        }
        if (maxLenght > 0) {
            cout << maxLenght << endl;
            return 0;
        }
        lenght--;
    }
    cout << 0 << endl;
    return 0;
}