#include <iostream>
#include <list>

using namespace std;

typedef unsigned int Vertex;
typedef float Weight;

class VertexWeightPair{
public:
    Vertex vertex;
    Weight weight;
    VertexWeightPair(Vertex _vertex, Weight _weight){
        vertex = _vertex;
        weight= _weight;
    };
};

class WeightedGraphAL{
private:
    unsigned int num_vertex = 0, num_edges = 0;
    list<VertexWeightPair> *adj;

public:
    WeightedGraphAL(unsigned int num_vertice);

    ~WeightedGraphAL();

    int add_edge(Vertex u, Vertex v, Weight w);

    void remove_edge(Vertex u, Vertex v);

    unsigned int get_num_vertex(){ return num_vertex; }

    unsigned int get_num_edges(){ return num_edges; }

    list<VertexWeightPair> get_adj(Vertex v){ return adj[v]; }
};

WeightedGraphAL::WeightedGraphAL(unsigned int num_vertice){
    num_vertex = num_vertice;
    adj = new list<VertexWeightPair>[num_vertex];
}

WeightedGraphAL::~WeightedGraphAL(){
    for (unsigned int i = 0; i < num_vertex; i++){
        adj[i].clear();
    }

    delete[] adj;
    num_edges = num_vertex = 0;
}

int WeightedGraphAL::add_edge(Vertex u, Vertex v, Weight w){
    for(VertexWeightPair i : adj[u]){
        if(i.vertex == v){
            return 0;
        }
    }
    
    VertexWeightPair edge_u(v, w);
    adj[u].push_back(edge_u);
    VertexWeightPair edge_v(u, w);
    adj[v].push_back(edge_v);
    num_edges++;
    return 1;
}

void WeightedGraphAL::remove_edge(Vertex u, Vertex v){
    bool existe = 0;
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i){
        if(i->vertex == v){
            existe = 1;
            adj[u].erase(i);
            break;
        }
    }

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i){
        if(i->vertex == u){
            existe = 1;
            adj[v].erase(i);
            break;
        }
    }
    if(existe){
        num_edges--;
    }
}

void input_graph(WeightedGraphAL &g, unsigned int num_arestas){
    Vertex u, v;
    Weight w;

    for (int i = 0; i < num_arestas; ++i){
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
    
}

void display_list(list<VertexWeightPair> lst){
    for(VertexWeightPair vw : lst){
        cout << "(" << vw.vertex << ", " << vw.weight << "), ";
    }
    cout << endl;
}

void display_graph(WeightedGraphAL &g){
    for (int i = 0; i < g.get_num_vertex(); i++){
        cout << i << ": ";
        list<VertexWeightPair> lst = g.get_adj(i);
        display_list(lst);
    }
    
}

int main(){
    unsigned int num_vertex, num_edges;
    cin >> num_vertex >> num_edges;
    
    WeightedGraphAL g{num_vertex};
    input_graph(g, num_edges);
    cout << "num_vertices: " << num_vertex << endl;
    cout << "num_edges: " << g.get_num_edges() << endl;
    display_graph(g);

    return 0;
}