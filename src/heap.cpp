#include <iostream>
#define left(x) 2*x+1
#define right(x) 2*x
#define parent(x) x/2

using namespace std;

struct Heap {
    int *A;
    int size; 
    Heap(int s) {
        size = s; 
    }
    void max_heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < size && A[l] > A[i]) {
            largest = l;
        }
        if (r < size && A[r] > A[largest]) {
            largest = r;
        }
        if (largest != i) {
            int temp = A[i];
            A[i] = A[largest];
            A[largest] = temp; 
            max_heapify(largest);
        }
    }
    void build() {
        for (int i = size/2; i >= 0; i--) {
            max_heapify(i); 
        }
    }
    void sort() {
        int tempsize = size;
        while (size >= 2) {
            int temp = A[0];
            A[0] = A[size-1];
            A[size-1] = temp;
            size--;
            max_heapify(0);
        } 
        size = tempsize;
    }
}; 

int main() {
    int A[3] = {0,1, 2}; 
    int B[100];
    Heap h = Heap(3);
    h.A = A;
    h.build();
    Heap h1 = Heap(100);
    h1.A = B;
    h1.build();
    h1.sort();
    for (int i = 0; i < 4; i++) {
        cout << A[i] << ' ';
    } 
    cout << '\n';
    for (int i = 0; i < 100; i++) {
        cout << B[i] << ' ';
    }
    cout << '\n';
}
