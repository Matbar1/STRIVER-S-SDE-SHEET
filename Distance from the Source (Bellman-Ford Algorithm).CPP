class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
     vector<int> bellman_ford(int N, vector<vector<int>>& edges, int src) {
        int inf = 100000000;
        vector<int> dist(N, inf);

        dist[src] = 0;

        for (int i = 1; i <= N - 1; i++) {
            for (auto it : edges) {
                if (dist[it[0]]!=inf && dist[it[0]] + it[2] < dist[it[1]]) {
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }

        int fl = 0;
        for (auto it : edges) {
            if (dist[it[0]]!=inf && dist[it[0]] + it[2] < dist[it[1]]) {
                return {-1};
            }
        }

        if (!fl) {
            return dist;
        }
    }
};