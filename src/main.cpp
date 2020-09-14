#include "main.h"
#include "arrays.h"
#include "graphs.h"
using namespace std;

int main() {
    srand(time(NULL));
    vector<int> v = crunch::random_vec(1, 10, 20);
    crunch::print_vec(v);
    vector<vector<int>> graph = crunch::random_adj_list(10);
    print_graph_adj(graph);
}



void print_graph_adj(vector<vector<int>>& graph) {
    for (auto x : graph) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}