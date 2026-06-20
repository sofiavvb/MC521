#include <iostream>
#include <queue>
using namespace std;

/* 
A store has n cashiers numbered sequentially from 1 to n, with c customers in a queue.
A customer at the front of the queue is constantly assigned to the first unoccupied cashier,
i.e., cashier with the smallest number. The ith customer’s shopping cart takes ti seconds to process.

SACADA: pensar numa timeline mesmo, estamos ordenando pelos instantes em relação ao tempo 0 que cada
caixa ficará liberado de novo.
*/
struct Caixa {
    int timeReady;
    int id;
    
    bool operator<(const Caixa& other) const {
        if (timeReady != other.timeReady) {
            return timeReady > other.timeReady;
        }
        return id > other.id; 
    }
};

int main()
{
    int n, c, time;
    cin >> n >> c;
    priority_queue<Caixa> pq; 

    //instante zero, todos os caixas estão prontos: inicialização
    for(int i = 0; i < n; i++){
        pq.push({0, i + 1});
    }
    //a ideia eh que a cada cliente, escolhemos o caixa com o instante mais próximo que ele ficará pronto (tempo menor).
    //então aqui a sacada eh fazer tudo em relação ao tempo inicial.
    //ex: se o cliente q leva 87 segundos começou no t0, junto com o cliente que leva 406 segundos e o de 430 segundos,
    //no instante 87, o cliente de 87 segundos ficará pronto. Assim, a gente tira ele da fila e o próximo cliente
    //começa a ser atendido no instante 87, e ficará pronto no instante 87 + tempo do próximo cliente.
    for(int i = 0; i < c; i++){
        Caixa c = pq.top();
        pq.pop();
        cout << c.id << " ";
        cin >> time;
        pq.push({time + c.timeReady, c.id});
    }
    cout << endl;
    return 0;
}