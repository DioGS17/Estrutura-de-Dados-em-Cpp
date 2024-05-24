#include <iostream>
#include <list>

using namespace std;

class Fila{
private:
    list<int> fila;
public:

    list<int> get_fila(){ return fila; }

    void clear(){ fila.clear(); }

    bool isEmpty(){ return fila.empty(); }

    int first(){ return fila.front(); }

    void enqueue(int elem){ fila.push_back(elem); }

    void dequeue(){ fila.pop_front(); }

};

void printFila(Fila &f){
    list<int> fila = f.get_fila();
    for (auto i: fila){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    Fila fila;
    fila.enqueue(5);
    fila.enqueue(1);
    fila.enqueue(21);
    fila.enqueue(546);
    fila.enqueue(10);

    printFila(fila);

    fila.dequeue();

    printFila(fila);

    fila.clear();
}
