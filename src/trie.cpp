#include <bits/stdc++.h>
#include "trie.h"

namespace crunch {
    void bin_trie_insert(bin_trie *node, int val, int depth) {
        bool bit = val & (1 << (31-depth));
        std::cout << bit << "\n";
        if (depth == 5) {
            return;
        }
        if (node->children[0] == NULL && node->children[1] == NULL) {
            node->children[bit] = new bin_trie();
            bin_trie_insert(node->children[bit], val, depth+1);
            return;
        }
        else if (bit) {
            bin_trie_insert(node->children[1], val, depth+1);
            return;
        } else if(!bit) {
            bin_trie_insert(node->children[0], val, depth+1);
        }
    }
}
