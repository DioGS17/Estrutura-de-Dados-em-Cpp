#include <iostream>
#include <list>

using namespace std;

class Tab_Hash{
private:
    list<int> *tab;
    unsigned int tam;

public:
    Tab_Hash(unsigned int _tam);
    
    ~Tab_Hash();

    int get_tam(){ return tam; }

    list<int> get_tab(int i){ return tab[i]; }

    int hash(int k);

    void insere(int n);

};

Tab_Hash::Tab_Hash(unsigned int _tam){
    tam = _tam;
    tab = new list<int>[_tam];
    
}

Tab_Hash::~Tab_Hash(){
    tam = 0;
    delete[] tab;
    
}

int Tab_Hash::hash(int k){
    return k % tam;
}

void Tab_Hash::insere(int n){
    int i = hash(n);
    tab[i].push_back(n);
}

void print_tab(Tab_Hash &t){
    for(int i = 0; i < t.get_tam(); i++){
        cout << i << ": ";
        list<int> lst = t.get_tab(i);
        for(auto j : lst){
            cout << j << ", ";
        }
        cout << endl;
    }
}

int main(){
    Tab_Hash t(26);

    t.insere(25);
    t.insere(3);
    t.insere(12);
    t.insere(1);
    t.insere(0);
    t.insere(11);

    print_tab(t);

    return 0;
}