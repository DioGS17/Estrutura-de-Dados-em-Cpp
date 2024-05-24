#include <iostream>
#include <list>
#include <limits>

using namespace std;

typedef unsigned int Vertex;
typedef float Weight;

class WeightedDigraphAM {
private:
    unsigned int num_vertex = 0, num_edges = 0;
    Weight **adj;

public:
    WeightedDigraphAM(unsigned int num_vertices);

    ~WeightedDigraphAM();

    int add_edge(Vertex u, Vertex v, Weight w);

    void remove_edge(Vertex u, Vertex v);

    unsigned int get_num_vertex() { return num_vertex; }

    unsigned int get_num_edges() { return num_edges; }

    list<Vertex> get_adj(Vertex v) {
        list<Vertex> values;
        for (int i = 0; i < num_vertex; ++i) {
            if (adj[v][i] != numeric_limits<float>::infinity()) {
                values.push_back(i);
            }
        }
        return values;
    }

    Weight get_weight_edge(Vertex u, Vertex v) { return adj[u][v]; }
};

WeightedDigraphAM::WeightedDigraphAM(unsigned int num_vertices) {
    num_vertex = num_vertices;
    num_edges = 0;
    const unsigned int linhas = num_vertex;
    const unsigned int colunas = num_vertex;
    adj = new Weight *[linhas];
    for (int i = 0; i < linhas; ++i) {
        adj[i] = new Weight[colunas];
        for (int j = 0; j < colunas; ++j) {
            adj[i][j] = numeric_limits<float>::infinity();
        }
    }
}

WeightedDigraphAM::~WeightedDigraphAM() {
    const unsigned int linhas = num_vertex;
    for (int i = 0; i < linhas; ++i) {
        delete[] adj[i];
    }
    delete[] adj;
}

int WeightedDigraphAM::add_edge(Vertex u, Vertex v, Weight w) {
    if(u == v){
        return 0;
    }
    if (adj[u][v] == numeric_limits<float>::infinity()) {
        adj[u][v] = w;
        num_edges++;
        return 1;
    }
    return 0;
}

void WeightedDigraphAM::remove_edge(Vertex u, Vertex v) {
    if (adj[u][v] != numeric_limits<float>::infinity()) {
        adj[u][v] = numeric_limits<float>::infinity();
        num_edges--;
    }
}

void input_digraph(WeightedDigraphAM &g, unsigned int num_edges) {
    Vertex u, v;
    Weight w;
    for (int i = 0; i < num_edges; ++i) {
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
}

void display_matadj(WeightedDigraphAM &g) {
    for (unsigned int i = 0; i < g.get_num_vertex(); ++i) {
        for (unsigned int j = 0; j < g.get_num_vertex(); ++j) {
            cout << g.get_weight_edge(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    unsigned int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    WeightedDigraphAM g{num_vertices};
    input_digraph(g, num_edges);
    cout << "num_vertices: " << num_vertices << endl;
    cout << "num_edges: " << g.get_num_edges() << endl;
    display_matadj(g);

    return 0;
}