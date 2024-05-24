
#include <iostream>
#include <list>

using namespace std;

typedef unsigned int Vertex;

class GraphAL{
private:
    unsigned int num_vertex = 0;
    unsigned int num_edges = 0;
    list<Vertex> *adj;

public:
    GraphAL(unsigned int num_vertices);

    ~GraphAL();
    int add_edge(Vertex u, Vertex v);

    void remove_edge(Vertex u, Vertex v);

    unsigned int get_num_vertex(){ return num_vertex; }

    unsigned int get_num_edges(){ return num_edges; }

    list<Vertex> get_adj(Vertex v){ return adj[v]; }
};

GraphAL::GraphAL(unsigned int num_vertices){
    num_vertex = num_vertices;
    adj = new list<Vertex>[num_vertex];
}

GraphAL::~GraphAL(){
    for (unsigned int i = 0; i < num_vertex; ++i){
        adj[i].clear();
    }
    delete[] adj;
    num_edges = num_vertex = 0;
}

int GraphAL::add_edge(Vertex u, Vertex v){
    for(Vertex i : adj[u]){
        if (i == v){
            return 0;
        }
    }
    adj[v].push_back(u);
    adj[u].push_back(v);
    num_edges++;
    return 1;
}

void GraphAL::remove_edge(Vertex u, Vertex v){
    bool existe = 0;
    for(Vertex i : adj[u]){
        if(i == v){
            existe = 1;
        }
    }

    if(existe){
        adj[u].remove(v);
        adj[v].remove(u);
        num_edges--;
    }
}

void display_list(list<Vertex> lst){
    for (Vertex vertex : lst){
        cout << vertex << ", ";
    }
    cout << endl;
}

void display_graph(GraphAL &g){
    for (int v = 0; v < g.get_num_vertex(); v++){
        cout << v << ": ";
        list<Vertex> lst = g.get_adj(v);
        display_list(lst);
    }
}

void input_graph(GraphAL &g, unsigned int num_arestas){
    Vertex u = 0, v = 0;
    for (int i = 0; i < num_arestas; ++i){
       cin >> u >> v;
       g.add_edge(u, v);
    }
}

int main(){
    unsigned int num_edges, num_vertex;
    cin >> num_vertex >> num_edges;
    
    GraphAL g{num_vertex};
    input_graph(g, num_edges);
    cout << "num_vertices: " << num_vertex << endl;
    cout << "num_edges: " << g.get_num_edges() << endl;
    display_graph(g);
    return 0;
}