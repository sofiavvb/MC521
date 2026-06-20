#include <iostream>
#include <vector>
using namespace std;

/*
In some social network, there are n users communicating with each other in m groups of friends.

Initially, some user x receives the news from some source. Then he or she sends the news to his or her friends (two users are friends if there is at least
one group such that both of them belong to this group). Friends continue sending the news to their friends, and so on.
The process ends when there is no pair of friends such that one of them knows the news, and another one doesn't know.

For each user x you have to determine what is the number of users that will know the news if initially only user x starts distributing it.

Estratégia: utilizar um Union-Find para unir os usuários que estão no mesmo grupo. Manter a conta do tamanho de cada set, no final
para cada usuário, achar o pai dele e imprimir o tamanho do set do pai (que eh o que a função getSize faz).
*/

class DisjointUnionSets {
    vector<int> rank, parent, setSize;
    
public:
  
    DisjointUnionSets(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        setSize.resize(n, 1); 

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        int root = parent[i];
      
        //path compression
        if (parent[root] != root) {
            return parent[i] = find(root);
        }
      
        return root;
    }

    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot) return;
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot; //ligo x na arvore maior
            setSize[yRoot] += setSize[xRoot]; //atualizo o tamanho do conjunto
        } else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot; //ligo y na arvore maior
            setSize[xRoot] += setSize[yRoot]; 
        } else {
            parent[yRoot] = xRoot;
            setSize[xRoot] += setSize[yRoot];
            rank[xRoot]++;
        }
    }
    int getSize(int i){
        return setSize[find(i)];
    }
};

int main() {

    int n, m, size, first, element;
    cin >> n >> m; 
    vector<int> v(n, 0);
    DisjointUnionSets dus(n);
    for(int i = 0; i < m; i++){
        //para cada grupo, eu uno os elementos com o primeiro
        cin >> size;
        if (size == 0) continue; 
        cin >> first;
        for(int j = 1; j < size; j++){
            cin >> element;
            dus.unionSets(first - 1, element - 1);
        }
    }

    //contar quantos elementos possuem o mesmo pai;
    //para cada elemento, acho o pai e somo um na contagem no v
    // for(int i = 0; i < n; i++){
    //     int parent = dus.find(i);
    //     v[parent]++;
    // }

    for(int i = 0; i < n; i++){
        // int parent = dus.find(i);
        // cout << v[parent] << " ";
        int size = dus.getSize(i);
        cout << size << " ";
    }
    cout << endl;

    return 0;
}