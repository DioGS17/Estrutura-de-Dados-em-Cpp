#include <iostream>
#include <list>

using namespace std;

typedef unsigned int Vertex;

class DigraphAL {
private:
    unsigned int num_vertex = 0;
    unsigned int num_edges = 0;
    list<Vertex> *adj;

public:
    DigraphAL(unsigned int num_vertices);

    ~DigraphAL();

    int add_edge(Vertex u, Vertex v);

    void remove_edge(Vertex u, Vertex v);

    unsigned int get_num_vertex() { return num_vertex; }

    unsigned int get_num_edges() { return num_edges; }

    list<Vertex> get_adj(Vertex v) { return adj[v]; }
};

DigraphAL::DigraphAL(unsigned int num_vertices) {
    num_vertex = num_vertices;
    adj = new list<Vertex>[num_vertex];
}

DigraphAL::~DigraphAL() {
    for (unsigned int i = 0; i < num_vertex; ++i) {
        adj[i].clear();
    }
    delete[] adj;
    num_edges = num_vertex = 0;
}

int DigraphAL::add_edge(Vertex u, Vertex v) {
    if(u == v){
        return 0;
    }
    for (Vertex i : adj[u]) {
        if (i == v) {
            return 0;
        }
    }

    adj[u].push_back(v);
    num_edges++;
    return 1;
}

void DigraphAL::remove_edge(Vertex u, Vertex v) {
    bool existe = 0;
    for(Vertex i : adj[u]){
        if(i == u){
            existe = 1;
        }
    }
    
    if(existe){
        adj[u].remove(v);
        num_edges--;
    }
}

void display_list(list<Vertex> lst) {
    for (Vertex vertex : lst) {
        cout << vertex << ", ";
    }
    cout << endl;
}

void display_digraph(DigraphAL &g) {
    for (int v = 0; v < g.get_num_vertex(); v++) {
        cout << v << ": ";
        list<Vertex> lst = g.get_adj(v);
        display_list(lst);
    }
}

void input_digraph(DigraphAL &g, unsigned int num_edges) {
    Vertex u, v;
    for (int i = 0; i < num_edges; ++i) {
       cin >> u >> v;
       g.add_edge(u, v);
    }
}

int main() {
    unsigned int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;
    
    DigraphAL g{num_vertices};
    input_digraph(g, num_edges);
    cout << "num_vertices: " << num_vertices << endl;
    cout << "num_edges: " << g.get_num_edges() << endl;
    display_digraph(g);

    return 0;
}