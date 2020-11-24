#include <iostream>
#include <vector>
#include "arrays.h"

using namespace std;
int partition(vector<int>&, int, int);
void qsort(vector<int>&, int, int);

int main() {
    vector<int> A = crunch::random_vec(0, 100, 100);
    qsort(A, 0, A.size()-1);
    for (auto x : A) cout << x << ' ';
    cout << '\n';    
}

void qsort(vector<int>& A, int p, int r) {
    if (p < r) {
        int pivot = partition(A, p, r);
        qsort(A, p, pivot-1);
        qsort(A, pivot+1, r); 
    }
}

int partition(vector<int>& A, int p, int r) {
    int x = A[r];
    int i = p-1;
    for (int j = p; j <= r-1; j++) {
        if (A[j] <= x) {
            i++;
            int temp = A[j]; 
            A[j] = A[i];
            A[i] = temp;
        }
    } 
    A[r] = A[i+1];
    A[i+1] = x; 
    return i+1;
}
