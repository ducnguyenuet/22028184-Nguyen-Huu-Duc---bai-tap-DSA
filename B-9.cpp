#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Graph {
public:
    Graph(int vertices) : V(vertices), graph(vertices) {}

    void addEdge(int from, int to) {
        graph[from].push_back(to);
    }

    bool isConnected() {
        std::vector<bool> visited(V, false);
        dfs(0, visited);

        return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }

    bool hasEulerianCycle() {
        if (!isConnected()) {
            return false;
        }

        for (int vertex = 0; vertex < V; ++vertex) {
            if (graph[vertex].size() != outDegree(vertex)) {
                return false;
            }
        }

        return true;
    }

    std::string eulerianCycle() {
        if (!hasEulerianCycle()) {
            return "No Eulerian cycle exists in the graph.";
        }

        std::stack<int> eulerianPath;
        std::vector<int> circuit;

        eulerianPath.push(0);

        while (!eulerianPath.empty()) {
            int currentVertex = eulerianPath.top();

            if (!graph[currentVertex].empty()) {
                int nextVertex = graph[currentVertex].back();
                graph[currentVertex].pop_back();
                eulerianPath.push(nextVertex);
            } else {
                circuit.push_back(eulerianPath.top());
                eulerianPath.pop();
            }
        }

        std::reverse(circuit.begin(), circuit.end());

        std::string result = "Eulerian cycle: ";
        for (int vertex : circuit) {
            result += std::to_string(vertex) + " -> ";
        }
        result.pop_back(); // Remove the last space
        result.pop_back(); // Remove the last arrow
        return result;
    }

private:
    int V;
    std::vector<std::vector<int>> graph;

    void dfs(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    int outDegree(int vertex) const {
        return graph[vertex].size();
    }
};

int main() {
    int n;
    std::cin >> n;

    Graph g(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        g.addEdge(x, y);
    }

    std::cout << g.eulerianCycle() << std::endl;

    return 0;
}

