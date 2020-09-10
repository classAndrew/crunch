#include <bits/stdc++.h>
#ifndef CRUNCH_H__
#define CRUNCH_H__
using namespace std;
vector<int> random_vec(int lower, int upper, int num_elements);
vector<vector<int>> random_adj_list(int nodes);
void print_graph_adj(vector<vector<int>>& graph);
#endif