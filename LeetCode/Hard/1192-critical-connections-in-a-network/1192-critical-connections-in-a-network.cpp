// Tarjan's Algorithm. Bridge Finding Algorithm.
class Solution {
private:
    vector<int> discoveryTime; // Time when a node is first visited
    vector<int> lowestTime;    // Earliest discovery time reachable from node
    vector<bool> visited;      // Marks whether a node is visited
    int globalTimer = 0;       // Global DFS timer
    vector<vector<int>> bridges;

    void tarjan_dfs(auto& graph, int node, int parent) {
        discoveryTime[node] = globalTimer;
        lowestTime[node] = globalTimer;
        globalTimer++;
        visited[node] = true;
        for (auto nextNode : graph[node]) {
            if (nextNode == parent) {
                continue;
            }
            if (!visited[nextNode]) {
                tarjan_dfs(graph, nextNode, node);
                lowestTime[node] = min(lowestTime[node], lowestTime[nextNode]);
            } else {
                int mn = min(lowestTime[node], discoveryTime[nextNode]);
                lowestTime[node] = mn;
            }
            if (lowestTime[nextNode] > discoveryTime[node]) {
                bridges.push_back({node, nextNode});
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, auto& connections) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < connections.size(); i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        discoveryTime.assign(n, -1);
        lowestTime.assign(n, -1);
        visited.assign(n, false);
        tarjan_dfs(graph, 1, -1);
        return bridges;
    }
};