#include <bits/stdc++.h>
using namespace std;

int bellman_ford(vector<vector<int>> &edges, int n, int src, int dst) {
  vector<int> distance(n, INT_MAX);
  distance[src] = 0;

  // Relax all edges n-1 times
  for (int i = 0; i < n - 1; i++) {
    for (auto &edge : edges) {
      if (distance[edge[0]] != INT_MAX &&
          distance[edge[0]] + edge[2] < distance[edge[1]]) {
        distance[edge[1]] = distance[edge[0]] + edge[2];
      }
    }
  }

  // Check for negative weight cycles
  for (auto &edge : edges) {
    if (distance[edge[0]] != INT_MAX &&
        distance[edge[0]] + edge[2] < distance[edge[1]]) {
      return -1; // Negative cycle detected
    }
  }

  if (distance[dst] == INT_MAX)
    return -1;
  return distance[dst];
}

int main() {
  int e, n, src, dst, s, d, w;
  cin >> n;
  cin >> e;
  vector<vector<int>> edges;
  for (int i = 0; i < e; i++) {
    cin >> s >> d >> w;
    edges.push_back({s, d, w});
  }
  while (cin >> src >> dst) {
    cout << bellman_ford(edges, n, src, dst) << endl;
  }
}
