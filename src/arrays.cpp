#include <bits/stdc++.h>
#include "arrays.h"
// namespace crunch
namespace crunch
{
    std::vector<int> random_vec(int lower, int upper, int num_elements)
    {
        // The point is for this to be copied to some variable, it'll be a bit slow though
        std::vector<int> v;
        for (int i = 0; i < num_elements; i++)
        {
            v.push_back((rand() / (double)INT_MAX) * (upper - lower) + lower);
        }
        return v;
    }
    void print_vec(std::vector<int> v) {
        std::cout << "[";
        for (int i = 0; i < v.size(); i++) {
            std::cout << v[i] << (i==v.size()-1 ? "" : ", "); 
        }
        std::cout << "]\n";
    }
} 
