#include <bits/stdc++.h>
#include "trie.h"

namespace crunch {
    void bin_trie_insert(bin_trie *node, int val, int depth) {
        if (depth == 32) {
            return;
        }
        bool bit = val & (1 << (31-depth));
        if (!node->children[bit])
            node->children[bit] = new bin_trie();
        bin_trie_insert(node->children[bit], val, depth+1);
    }
}
