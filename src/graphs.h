#ifndef CRUNCH_GRAPHS_H__
#define CRUNCH_GRAPHS_H__
#include <bits/stdc++.h>

namespace crunch 
{
    std::vector<std::vector<int>> random_adj_list(int nodes);
    void print_graph_adj(std::vector<std::vector<int>>& graph);
}

#endif