#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct find_union
{
    find_union(vector<int>& v){
        auto n = v.size();
        rank.resize(n);
        fill(rank.begin(), rank.end(), 0);
        parent.resize(n);
        for (auto i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int get_parent(int i){
        auto p = parent[i];
        if(p == i)
            return p;
        return parent[i] = get_parent(p);
    }

    void union_(int i, int j){
        auto p1 = get_parent(i);
        auto p2 = get_parent(j);
        if(p1 == p2)
            return;
        if(rank[p1] < rank[p2])
            parent[p1] = p2;
        else if(rank[p1] > rank[p2])
            parent[p2] = p1;
        else{
            parent[p1] = p2;
            ++rank[p2];
        }
        return;
    }

    vector<int> rank;
    vector<int> parent;
};