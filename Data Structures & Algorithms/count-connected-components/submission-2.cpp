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

    void connectNode(int a, int b) {
        int parA = findParent(a);
        int parB = findParent(b);
        if(parA == parB)
        {
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
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSetUnion* dsu = new DisjointSetUnion(n);
        for (auto it : edges) {
            dsu->connectNode(it[0], it[1]);
        }
        int connectedComponentsCount = 0;
        for (int i = 0; i < n; i++) {
            if (i == dsu->findParent(i)) {
                connectedComponentsCount++;
            }
        }
        return connectedComponentsCount;
    }
};
