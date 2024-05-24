#include <iostream>
#include <list>

using namespace std;

typedef unsigned int Vertex;
typedef float Weight;

class VertexWeightPair {
public:
    Vertex vertex;
    Weight weight;
    VertexWeightPair(Vertex _vertex, Weight _weight) {
        vertex = _vertex;
        weight = _weight;
    };
};

class WeightedDigraphAL {
private:
    unsigned int num_vertex = 0, num_edges = 0;
    list<VertexWeightPair>* adj;

public:
    WeightedDigraphAL(unsigned int num_vertices);

    ~WeightedDigraphAL();

    int add_edge(Vertex u, Vertex v, Weight w);

    void remove_edge(Vertex u, Vertex v);

    unsigned int get_num_vertex() { return num_vertex; }

    unsigned int get_num_edges() { return num_edges; }

    list<VertexWeightPair> get_adj(Vertex v) { return adj[v]; }
};

WeightedDigraphAL::WeightedDigraphAL(unsigned int num_vertices) {
    num_vertex = num_vertices;
    adj = new list<VertexWeightPair>[num_vertex];
}

WeightedDigraphAL::~WeightedDigraphAL() {
    for (unsigned int i = 0; i < num_vertex; i++) {
        adj[i].clear();
    }

    delete[] adj;
    num_edges = num_vertex = 0;
}

int WeightedDigraphAL::add_edge(Vertex u, Vertex v, Weight w) {
    if(u == v){
        return 0;
    }
    for (VertexWeightPair edge : adj[u]) {
        if (edge.vertex == v) {
            return 0;
        }
    }
    VertexWeightPair edge_u(v, w);
    adj[u].push_back(edge_u);
    num_edges++;
    return 1;
}

void WeightedDigraphAL::remove_edge(Vertex u, Vertex v) {
    bool existe = 0;
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
        if (i->vertex == v) {
            existe = 1;
            adj[u].erase(i);
            break;
        }
    }
    if(existe){
        num_edges--;
    }
}

void input_graph(WeightedDigraphAL& g, unsigned int num_edges) {
    Vertex u, v;
    Weight w;

    for (int i = 0; i < num_edges; ++i) {
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
}

void display_list(list<VertexWeightPair> lst) {
    for (VertexWeightPair vw : lst) {
        cout << "(" << vw.vertex << ", " << vw.weight << "), ";
    }
    cout << endl;
}

void display_graph(WeightedDigraphAL& g) {
    for (int i = 0; i < g.get_num_vertex(); i++) {
        cout << i << ": ";
        list<VertexWeightPair> lst = g.get_adj(i);
        display_list(lst);
    }
}

int main() {
    unsigned int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    WeightedDigraphAL g(num_vertices);
    input_graph(g, num_edges);
    display_graph(g);

    return 0;
}