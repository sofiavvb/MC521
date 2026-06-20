
#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

/* 
There is a n × n grid D where each cell contains either 1 or 0.
Your task is to create a program that takes the gird data as input and computes the
greatest number of consecutive 1s in either vertical, horizontal, or diagonal direction.

Estratégia: para cada célula, checar o número de 1s consecutivos em cada direção.
Abaixo, Direita, e as duas diagonais. Para cada direção, checar se não estamos fora dos limites e se ainda estamos vendo 1s.
*/
int main()
{
    int n;
    int di[4] = {0, 1, 1, 1}; //direita, baixo, diagonal direita, diagonal esquerda
    int dj[4] = {1, 0, 1, -1};

    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<vector<int>> grid(n, vector<int>(n)); 

        for (int i = 0; i < n; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < n; j++) {
                line[j] == '1' ? grid[i][j] = 1 : grid[i][j] = 0;
            }
        }

        int count = 0, max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) { continue; }
                //olho pra direita, dps baixo, dps diag direita e dps esquerda
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    count = 1;
                    //checar se nao ta out of bounds e se ainda ta vendo 1
                    while (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                        count++;
                        ni += di[d];
                        nj += dj[d];
                    }
                    if (count > max){
                        max = count;
                    }
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}