#include "graphs.h"
namespace crunch {
    // Graphs (MAY PRODUCE A NON-SIMPLE GRAPH WHERE NODE IS CONNECTED TO ITSELF, or multiple edges to one neighbor, OR A NOT CONNECTED AT ALL)
    std::vector<std::vector<int>> random_adj_list(int nodes) {
        std::vector<std::vector<int>> graph;
        graph.resize(nodes);
        for (int i = 0; i < nodes; i++) {
            int degree = (rand()/(double)INT_MAX)*nodes;
            for (int j = 0; j < degree; j++) {
                graph[i].push_back(rand()/(double)INT_MAX*nodes);
            }
        }
        return graph;
    }
}