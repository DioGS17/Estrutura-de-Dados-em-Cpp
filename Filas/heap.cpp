#include <iostream>

using namespace std;

class Heap{
    private:
        int heap[1000];
        int tam_heap = 0;

    public:
        int *get_heap(){ return heap; }
        int get_tam_heap(){ return tam_heap; }

        int parent(int i){ return i/2; }
        int left(int i){ return 2*i; }
        int right(int i){ return 2*i+1; }

        // Funções para uma fila de prioridade máxima
        void insertMax(int i);
        void max_heapfy(int i);
        void build_max_heap();
        int extractMax();

        // Funções para uma fila de prioridade miníma
        void insertMin(int i);
        void min_heapfy(int i);
        void build_min_heap();
        int extractMin();
};

void Heap::max_heapfy(int i){
    int maior;

    int l = left(i);
    int r = right(i);

    if (l <= tam_heap && heap[l-1] > heap[i-1]){
        maior = l;
    }else{
        maior = i;
    }

    if (r <= tam_heap && heap[r-1] > heap[maior-1]){
        maior = r;
    }

    if (maior != i){
        int temp = heap[i-1];
        heap[i-1] = heap[maior-1];
        heap[maior-1] = temp;
        max_heapfy(maior);
    }
}

void Heap::build_max_heap(){
    for (int i = tam_heap/2; i > 0; i--){
        max_heapfy(i);
    }
}

void Heap::insertMax(int i){
    heap[tam_heap++] = i;
    build_max_heap();
}

int Heap::extractMax(){
    int max = heap[0];
    heap[0] = heap[tam_heap-1];
    tam_heap--;
    max_heapfy(1);

    return max;
}

void Heap::min_heapfy(int i){
    int menor;

    int l = left(i);
    int r = right(i);

    if (l <= tam_heap && heap[l-1] < heap[i-1]){
        menor = l;
    }else{
        menor = i;
    }

    if (r <= tam_heap && heap[r-1] < heap[menor-1]){
        menor = r;
    }

    if (menor != i){
        int temp = heap[i-1];
        heap[i-1] = heap[menor-1];
        heap[menor-1] = temp;
        min_heapfy(menor);
    }
}

void Heap::build_min_heap(){
    for (int i = tam_heap/2; i > 0; i--){
        min_heapfy(i);
    }
}

void Heap::insertMin(int i){
    heap[tam_heap++] = i;
    build_min_heap();
}

int Heap::extractMin(){
    int min = heap[0];
    heap[0] = heap[(tam_heap--)-1];
    min_heapfy(1);

    return min;
}

void print_heap(Heap &h){
    int *heap = h.get_heap();

    for(int i = 0; i < h.get_tam_heap(); i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main(){
    Heap heap;

    // heap.insertMax(3);
    // heap.insertMax(14);
    // heap.insertMax(5);
    // heap.insertMax(1);
    // heap.insertMax(2);
    // heap.insertMax(29);
    // heap.insertMax(1);
    // heap.insertMax(15);
    // heap.insertMax(8);
    // heap.insertMax(4);
    // heap.insertMax(10);

    // print_heap(heap);

    // int max = heap.extractMax();
    // cout << "max extraido = " << max << endl;

    // print_heap(heap);

    heap.insertMin(3);
    heap.insertMin(14);
    heap.insertMin(5);
    heap.insertMin(1);
    heap.insertMin(2);
    heap.insertMin(29);
    heap.insertMin(1);
    heap.insertMin(15);
    heap.insertMin(8);
    heap.insertMin(4);
    heap.insertMin(10);

    print_heap(heap);

    int min = heap.extractMin();
    cout << "min extraido = " << min << endl;

    print_heap(heap);

    return 0;
}