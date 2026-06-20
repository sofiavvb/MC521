#include <iostream>
#include <cmath>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
#define ll long long
using namespace std;

ll s(ll x){
    ll n = x;
    ll sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }
    return sum;
}

double f(ll x, ll n){
    return x * x + s(x) * x - n;
}

int main(){
    ll n;
    cin >> n;
    return 0;
}

//duas ideias de solucao:

/* 
PRIMEIRA:

como x e s sao sempre positivos, temos que x^2 < x^2 + s(x)* x = n -> x < √n  (bem matematica mesmo)
se o maior valor possivel para x = 10^9, entao o maior valor para s(999.999.999) = 81 (pequeno).
podemos entao fazer um brute force nos valores de s indo de 1 ate 81, para cada um desses nos sobra uma eq quadratica.
calculamos a raiz positiva e vemos se x é estritamente inteiro (já que nem toda equação terá raízes inteiras). 
se sim, precisamos ainda checar se para esse x, s(x) eh o valor 
que chutamos de fato. Se sim, achamos. 

SEGUNDA: 

podemos usar o valor 81 como teto de s. ou seja, queremos achar o valor de x tal que x^2 + s(x)* x = n. Se comecamos pelo maior valor de x possivel (raiz de n),
podemos ir iterando ate "quebrar", ou seja, se x^2 + 81 * x < n eh impossivel que x^2 + s(x)* x seja igual a n, para qualquer outro s menor que 81. Assim, fazemos um
loop enquanto essa condicao que viola nao chega. Dentro do loop, precisamos calcular o valor da equacao para o x da iteracao, se ela bater atualizamos o valor da melhor solucao encontrada. para a proxima iteracao fazemos x--.

importante inicializar a solucao com -1 antes de comecar isso, para no final printarmos o valor nessa variavel solucao.

*/