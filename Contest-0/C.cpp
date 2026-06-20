#include <iostream>
#include <string>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

//problema de rotacao ciclica de string
//sacada: apontar para o inicio da string e ir mudando ele a cada rotacao
int main()
{_
    int lenght, queries, option, x;
    int start = 0;
    string s;
    cin >> lenght >> queries >> s;
    while(queries--){
        cin >> option >> x;

        //"rotaciono" x vezes
        if(option == 1){
            //move = (move + x) % lenght;
            start = (start + lenght - x) % lenght;
        }else {
            //printar a x-esima letra
            //cout << s[(x - 1 - move + lenght) % lenght] << endl;
            cout << s[(start + x - 1) % lenght] << endl;
        }
    }
    return 0;
}