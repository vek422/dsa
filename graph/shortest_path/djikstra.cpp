#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
using namespace std;

struct PairComparator {
  bool operator()(pair<int, int> left, pair<int, int> right) {
    return left.second > right.second;
  }
};

int dijkstra(vector<vector<int>> &edges, int n, int src, int dst) {
  unordered_map<int, vector<pair<int, int>>> graph;
  for (auto &edge : edges) {
    graph[edge[0]].push_back({edge[1], edge[2]});
  }

  vector<int> dist(n, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, PairComparator>
      minHeap;
  vector<bool> visited(n, false);
  minHeap.push({src, 0});
  while (!minHeap.empty()) {
    auto [u, w] = minHeap.top();
    minHeap.pop();
    if (visited[u])
      continue;
    visited[u] = true;
    if (u == dst)
      return w;
    for (auto &adj : graph[u]) {
      if (visited[adj.first])
        continue;
      if (w + adj.second < dist[adj.first]) {
        dist[adj.first] = w + adj.second;
        minHeap.push({adj.first, dist[adj.first]});
      }
    }
  }
  return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
  vector<vector<int>> edges;
  int src, n, w, dest, e;
  cin >> n;
  cin >> e;
  for (int i = 0; i < e; i++) {
    cin >> src >> dest >> w;
    edges.push_back({src, dest, w});
  }
  cout << "enter src and dst" << endl;
  while (cin >> src >> dest) {
    int result = dijkstra(edges, n, src, dest);
    if (result != -1) {
      cout << "Shortest path from " << src << " to " << dest << " is " << result
           << endl;
    } else {
      cout << "There is no path from " << src << " to " << dest << endl;
    }
  }
  return 0;
}
