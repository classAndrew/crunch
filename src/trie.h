#ifndef CRUNCH_H_TRIE__
#define CRUNCH_H_TRIE__
#include <stdlib.h>
namespace crunch {
    // Binary prefix tree. Only binary for reasons
    struct bin_trie {
        bin_trie() : children{NULL, NULL} {}
        bin_trie *children[2];
    };

    void bin_trie_insert(bin_trie *node, int val, int depth);
    
}
#endif