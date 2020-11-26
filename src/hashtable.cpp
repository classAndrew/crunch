#include <iostream>
#include <cmath>

using namespace std;

template <typename D>
struct node {
    int k;
    D data;
    node<D> *next = NULL; 
    node(int key, D d) : k(key), data(d) {}
};

template <int m, typename D>
struct chained_table {
    node<D> *table[m];
    chained_table() {
        for (int i = 0; i < m; i++) table[i] = nullptr; 
    }
    ~chained_table() {
        for (int i = 0; i < m; i++) {
            node<D> *n = table[i];
            if (!n) continue; 
            while (n->next) {
                node<D> *temp = n->next;
                delete n;
                n = temp;
            }    
        } 
    } 
    void insert(int k, int v) {
        node<D> *cell = table[hash(k)%m];
        if (!cell) table[hash(k)%m] = new node<D>(k, v);
        else {
            while (cell->next) {
                cell = cell->next;
            }
            cell->next = new node<D>(k, v);
        }
    }
    // return pointer to it
    node<D> *get(int k) {
        node<D> *cell = table[hash(k)%m];
        while (cell && cell->k != k) {
            cell = cell->next;
        }
        return cell;
    } 
    // 8-bits multiplication hash 
    char hash(int k) {
        // this s divide by 2^32 is close to (sqrt(5)-1)/2
        static const long long s = 2654435769;
        // it's all truncated down for us and grab upper 8 bits 
        int h = k * s;
        return h & 0xFF00;
    } 
};

template <int m, typename D>
struct open_table {
    pair<int, D> table[m];
    open_table() {
        for (int i = 0; i < m; i++) table[i].first = -1;
    } 
    void insert(int k, D v) {
        int i = 0;
        while (i < m) {
            int ind = hash(k, i);
            if (table[i].first == -1) {
                table[i].second= v;
                table[i].first = k;
                return; 
            } 
            i++;
        }
        cout << "open addressing overflow\n"; 
    }
    D get(int k) {
        int i = 0;
        while (i < m) {
            int ind = hash(k, i);
            if (table[i].first == k) {
                return table[i].second; 
            } 
            i++;
        }
        return {};
    } 
    int hash(int k, int i) {
        return (hash1(k)+i*hash2(k))%m;
    }
    int hash1(int k) {
        return k % m; 
    } 
    int hash2(int k) {
        return 1 + (k % (m-1));
    }
};

int main() {
    // chained_table<256, int> t;
    int testdata[300] = {1,2,3};  
    // for (int i = 0; i < 300; i++) {
    //     t.insert(i, testdata[i]);
    //     cout << '(' << i << ' ' << testdata[i] << ')' << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < 300; i++) {
    //     cout << '(' << i << ' ' << t.get(i)->data << ')' << ' ';
    // }
    // cout << '\n';

    open_table<701, int> ot;
    for (int i = 0; i < 300; i++) {
        cout << testdata[i] << ' '; 
        ot.insert(i, testdata[i]);
    }
    cout << '\n';
    for (int i = 0; i < 300; i++) {
        cout << '(' << i << ' ' << ot.get(i) << ')' << ' ';
    }
    cout << '\n';

}
