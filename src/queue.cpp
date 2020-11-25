#include <iostream>

using namespace std;

struct cqueue {
    int *A;
    int size;
    int head = 0;
    int tail = 0; 
    
    cqueue(int *a, int sz) : A(a), size(sz) {

    }

    void enqueue(int n) {
        if ((tail+1)%size == head) {
            cout << "queue overflow!\n";
            return;
        } 
        A[tail] = n; 
        tail = (tail+1) % size;   
    }

    void dequeue() {
        if (tail == head+1) {
            cout << "queue underflow!\n";
            return;
        }
        head = (head + 1) % size; 
    }

    int front() {
        return A[head];
    }
};

int main() {
    int data[3] = {};
    cqueue q(data, 3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.front() << '\n';
    q.dequeue();
    cout << q.front() << '\n';
}
