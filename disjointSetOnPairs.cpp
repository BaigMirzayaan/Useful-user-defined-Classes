class disjointSet{
    public:
    map<pair<int, int>, pair<int, int>> parent;
    map<pair<int, int>, int> rank;

    disjointSet(vector<vector<int>> stones){
        for(auto s: stones){
            int x = s[0], y = s[1];
            pair<int, int> node = make_pair(x, y);

            parent[node] = node;
            rank[node] = 0;
        }
    }

    pair<int, int> find_parent(pair<int, int>& v){
        if(parent[v] == v) return v;

        return parent[v] = find_parent(parent[v]);
    }

    void unionByRank(pair<int, int>& u, pair<int, int>& v){
        pair<int, int> ulp_u = find_parent(u);
        pair<int, int> ulp_v = find_parent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v] ++;
        }
    }
};
