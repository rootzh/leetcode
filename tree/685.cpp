class Solution {
public:
    vector<int> parent;
    int count;
    int root(int num) {
        while (num != parent[num]) {
            parent[num] = parent[parent[num]];
            num = parent[num];
        }
        return num;
    }
    void connect(int u, int v) {
        int p1 = root(u);
        int p2 = root(v);
        if (p1 == p2) {
            return;
        }
        parent[v] = p1;
        count--;
        return;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        count = edges.size();
        parent.resize(count);
        vector<int> innum;
        innum.resize(count);
        for (int i = 0;i<count;++i) {
            parent[i] = i;
        }
        int end = -1;
        for (int i = 0; i<count;++i) {
            ++innum[edges[i][1] - 1];
            if (innum[edges[i][1] - 1] == 2) {
                end = edges[i][1] - 1;
            }
        }
        if (end == -1 ) {
            for (int i = 0; i<edges.size(); ++i) {
                if (root(edges[i][0] -1) == root(edges[i][1] - 1)) {
                    return edges[i];
                }
                connect(edges[i][0]-1, edges[i][1] - 1);
            }
        } else {
            vector<int> first,second;
            bool isFirst = true;
            for (int i = 0; i< edges.size(); i++ ) {
                if (end == edges[i][1] - 1) {
                    if (isFirst ) {
                        first = edges[i];
                        connect(edges[i][0] - 1, edges[i][1] - 1);
                        isFirst = false;
                    } else {
                        second = edges[i];
                    }
                } else {
                    connect(edges[i][0] - 1, edges[i][1] - 1);
                }
            }
            if (count == 1) {
                return second;
            }
            return first;

        }
        return edges[0];
    }
};
