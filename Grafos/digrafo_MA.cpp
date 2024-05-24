#include <iostream>
#include <list>

using namespace std;

typedef unsigned int Vertex;
typedef float Weight;

class DigraphAM {
private:
    unsigned int num_vertex = 0, num_edges = 0;
    Weight **adj;

public:
    DigraphAM(unsigned int num_vertex);

    ~DigraphAM();

    int add_edge(Vertex u, Vertex v, Weight w);

    void remove_edge(Vertex u, Vertex v);

    unsigned int get_num_vertex() { return num_vertex; }

    unsigned int get_num_edges() { return num_edges; }

    list<Vertex> get_adj(Vertex v) {
        list<Vertex> values;
        for (int i = 0; i < num_vertex; ++i) {
            if (adj[v][i] != 0) {
                values.push_back(i);
            }
        }
        return values;
    }

    Weight get_weight_edge(Vertex u, Vertex v) { return adj[u][v]; }
};

DigraphAM::DigraphAM(unsigned int num_vertice) {
    num_vertex = num_vertice;
    num_edges = 0;
    const unsigned int linhas = num_vertex;
    const unsigned int colunas = num_vertex;
    adj = new Weight *[linhas];
    for (int i = 0; i < linhas; ++i) {
        adj[i] = new Weight[colunas];
        for (int j = 0; j < colunas; ++j) {
            adj[i][j] = 0;
        }
    }
}

DigraphAM::~DigraphAM() {
    const unsigned int linhas = num_vertex;
    for (int i = 0; i < linhas; ++i) {
        delete[] adj[i];
    }
    delete[] adj;
}

int DigraphAM::add_edge(Vertex u, Vertex v, Weight w) {
    if(u == v){
        return 0;
    }
    if (adj[u][v] != 1) {
        adj[u][v] = w;
        num_edges++;
        return 1;
    }
    return 0;
}

void DigraphAM::remove_edge(Vertex u, Vertex v) {
    if (adj[u][v]) {
        adj[u][v] = 0;
        num_edges--;
    }
}

void display_matadj(DigraphAM &g) {
    for (unsigned int i = 0; i < g.get_num_vertex(); i++) {
        for (unsigned int j = 0; j < g.get_num_vertex(); j++) {
            cout << g.get_weight_edge(i, j) << " ";
        }
        cout << endl;
    }
}

void input_digraph(DigraphAM &g, unsigned int num_arcs) {
    Vertex u, v;
    for (int i = 0; i < num_arcs; ++i) {
        cin >> u >> v;
        g.add_edge(u, v, 1);
    }
}

int main() {
    unsigned int num_vertices, num_arcs;
    cin >> num_vertices >> num_arcs;

    DigraphAM g{num_vertices};
    input_digraph(g, num_arcs);
    cout << "num_vertices: " << num_vertices << endl;
    cout << "num_edges: " << g.get_num_edges() << endl;
    display_matadj(g);

    return 0;
}