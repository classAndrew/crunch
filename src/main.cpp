#include "main.h"
#include "arrays.h"
#include "graphs.h"
#include "trie.h"
using namespace std;

void graph_vec_test();
void bin_trie_test();
void traverse_trie_test(crunch::bin_trie *trie, int val);
int main() {
    srand(time(NULL));
    bin_trie_test();
}

void bin_trie_test() {
    crunch::bin_trie *trie = new crunch::bin_trie();
    crunch::bin_trie_insert(trie, 0b1010, 0);
    // crunch::bin_trie_insert(trie, 0b1011, 0);
    traverse_trie_test(trie, 0);
}

void traverse_trie_test(crunch::bin_trie *trie, int val) {
    if (!trie->children[0] && !trie->children[1]) {
        cout << val << "\n";
        return;
    }
    if (trie->children[1]) {
        traverse_trie_test(trie->children[1], (val << 1) + 1);
    } 
    if (trie->children[0]) {
        traverse_trie_test(trie->children[0], val << 1);
    }

}

void graph_vec_test() {
    vector<int> v = crunch::random_vec(1, 10, 20);
    crunch::print_vec(v);
    vector<vector<int>> graph = crunch::random_adj_list(10);
    crunch::print_graph_adj(graph);
}
