#include "main.h"
#include "arrays.h"
using namespace std;

int main() {
    srand(time(NULL));
    vector<int> v = crunch::random_vec(1, 10, 20);
    for (auto x : v) cout << x << " ";
    cout << "\n";
    vector<vector<int>> graph = random_adj_list(10);
    print_graph_adj(graph);
}


// Graphs (MAY PRODUCE A NON-SIMPLE GRAPH WHERE NODE IS CONNECTED TO ITSELF, or multiple edges to one neighbor, OR A NOT CONNECTED AT ALL)
vector<vector<int>> random_adj_list(int nodes) {
    vector<vector<int>> graph;
    graph.resize(nodes);
    for (int i = 0; i < nodes; i++) {
        int degree = (rand()/(double)INT_MAX)*nodes;
        for (int j = 0; j < degree; j++) {
            graph[i].push_back(rand()/(double)INT_MAX*nodes);
        }
    }
    return graph;
}

void print_graph_adj(vector<vector<int>>& graph) {
    for (auto x : graph) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}