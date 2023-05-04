#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <list>
using std::list; //evitar ter que digitar std::palavra

#include <iostream>
using std::cout; //evitar ter que digitar std::palavra
using std::cin;  //evitar ter que digitar std::palavra
using std::endl; //evitar ter que digitar std::palavra




#include <vector>
using std::vector;//evitar ter que digitar std::palavra

#include <queue>
using std::queue; //evitar ter que digitar std::palavra


list<int> BFS(int start, int end, vector<list<int>> graph, int v);

//função principal do codigo
int main(){

    //declaração de variaveis
    int v, e; 
    int a, b;
    int start, end;

    //quantidade de vertices
    cout << "vertice: ";
    cin >> v;
    
    //quantidade de arestas
    cout << "aresta: ";
    cin >> e;

    //ponto de partida
    cout << "ponto de partida: ";
    cin >> start;

    //destino
    cout << "destino: ";
    cin >> end;

    //craição do grafo usando lista de 
    vector<list<int>> graph;

    //criação de uma lista para guardar o caminho 
    list<int> finded(v);
    //criação de uma fila
    queue<int>q;
    //criação de 2 vectores
    vector<int> past(v, -2); //cria o vetor com tamanho v e popula com o valor de -2
    vector<bool> visited(v, false); //cria um vetor de tamanho v e ja popula com o valor false


    //definindo o tamnho do vetor
    graph.resize(v);
    for (int i = 0; i < e; i++) {
        graph[i].resize(e);
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int j;
    for (int i = 0; i < v; i++)
    {
        cout << i << " " ;
        for(auto j: graph[i]){
            cout << j << " ,";
        }
        cout << endl;
    }
    
    /*
    finded = BFS(start, end, graph, v);

    for(auto v: finded)
        cout << v << " ";
*/
}



list<int> BFS(int start, int end, vector<list<int>> graph, int v){
    
    queue<int>q;
    vector<int> past(v, -2);
    vector<bool> visited(v, -2);

    int elements, count;

    

    visited[start] = true;
    past[start] = -1;
    q.push(start);
    while (!q.empty())
    {
        start = q.front();
        q.pop();
        list<int> aux(graph[start].size());
        aux = graph[start];

        for(auto i: aux){
            if(i == end){
                for (auto elements: past)
                {
                    if (past[elements] != -2)
                        count ++;
                }
                
                list<int> finded(count);
                int numbers = i;
                while(numbers != -1)
                {
                    finded.push_back(numbers);
                    numbers = past[numbers];
                }
                return finded;
            }
            else {
                q.push(i);

                if(!visited[i]){
                    if (past[i] == -2)
                    {
                        past[i] = start;
                    }
                    visited[i] = true;
                }
            }
        }
    }
}
