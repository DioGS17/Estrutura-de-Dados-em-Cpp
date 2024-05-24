#include <iostream>
#include <list>
#include <limits>

using namespace std;

typedef unsigned int Vertex;
typedef float Weight;

class WeightedDigraphAM{
private:
    unsigned int num_vertex = 0, num_edges = 0;
    Weight **adj;

public:
    WeightedDigraphAM(unsigned int num_vertice);

    ~WeightedDigraphAM();

    int add_edge(Vertex u, Vertex v, Weight w);
    
    void remove_edge(Vertex u, Vertex v);
    
    unsigned int get_num_vertex(){ return num_vertex; }
    
    unsigned int get_num_edges(){ return num_edges; }
    
    list<Vertex> get_adj(Vertex v){
        list<Vertex> values;
        for (int i = 0;  i < num_vertex; ++i){
            if(adj[v][i] != 0){
                values.push_back(v);
            }
        }
        return values;
    }

    Weight get_weight_edge(Vertex u, Vertex v){ return adj[u][v]; }
};

WeightedDigraphAM::WeightedDigraphAM(unsigned int num_vertice){
    num_vertex = num_vertice;
    num_edges = 0;
    const unsigned int linhas = num_vertex;
    const unsigned int colunas = num_vertex;
    adj = new Weight*[linhas];
    for (int i = 0; i < linhas; ++i){
        adj[i] = new Weight[colunas];
        for (int j = 0; j < colunas; ++j){
            adj[i][j] = numeric_limits<float>::infinity();
        }
        
    } 
}

WeightedDigraphAM::~WeightedDigraphAM(){
    const unsigned int linhas = num_vertex;
    for (int i = 0; i < linhas; ++i){
        delete[] adj[i];
    }
    delete[] adj;
}

int WeightedDigraphAM::add_edge(Vertex u, Vertex v, Weight w){
    if(adj[u][v] == numeric_limits<float>::infinity()){
        adj[u][v] = w;
        adj[v][u] = w;
        num_edges++;
        return 1;
    }
    return 0;
}

void WeightedDigraphAM::remove_edge(Vertex u, Vertex v){
    if(adj[u][v]){
        adj[u][v] = numeric_limits<float>::infinity();
        adj[v][u] = numeric_limits<float>::infinity();
        num_edges--;
    }
}

void input_graph(WeightedDigraphAM &g, unsigned int num_aretas){
    Vertex u, v;
    Weight w;
    for (int i = 0; i < num_aretas; ++i){
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }   
}

void display_matadj(WeightedDigraphAM &g){
    for (unsigned int i = 0; i < g.get_num_vertex(); ++i){
        for (unsigned int j = 0; j < g.get_num_vertex(); ++j){
            cout << g.get_weight_edge(i, j) << " ";
        }
        cout << endl;
    }
}

int main(){
    unsigned int num_vertices, num_arestas;
    cin >> num_vertices >> num_arestas;

    WeightedDigraphAM g{num_vertices};
    input_graph(g, num_arestas);
    display_matadj(g);

    return 0;
}