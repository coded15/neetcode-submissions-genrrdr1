class DisjointSetUnion {
    int size;
    vector<int> rank;
    vector<int> parent;

   public:
    DisjointSetUnion(int size) {
        this->size = size;
        for (int i = 0; i < size; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findParent(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = findParent(parent[a]);
    }

    void connectNode(int a, int b, vector<vector<int>>& repeatedEdges) {
        int parA = findParent(a);
        int parB = findParent(b);
        if (parA == parB) {
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(b);
            repeatedEdges.push_back(temp);
            return;
        }
        if (rank[parA] == rank[parB]) {
            parent[parB] = parent[parA];
            rank[parA]++;
        } else if (rank[parA] > rank[parB]) {
            parent[parB] = parent[parA];
        } else {
            parent[parA] = parent[parB];
        }
    }
};
class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSetUnion dsu(edges.size()+1);
        vector<vector<int>> repeatedEdges;
        for (int i = 0; i < edges.size(); i++) {
            dsu.connectNode(edges[i][0], edges[i][1], repeatedEdges);
        }
        return repeatedEdges[repeatedEdges.size() - 1];
    }
};
