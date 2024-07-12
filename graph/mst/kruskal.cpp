#include <bits/stdc++.h>
#include <ostream>
#include <queue>
#include <unordered_map>
using namespace std;

typedef tuple<int, int, int> w_edge;
typedef unordered_map<int, vector<pair<int, int>>> Graph;

struct Edge_Comparator_min {
  bool operator()(w_edge left, w_edge right) {
    return get<2>(left) > get<2>(right);
  }
};

int find(vector<int> &parent, int x) {
  if (parent[x] != x) {
    parent[x] = find(parent, parent[x]); // path compression
  }
  return parent[x];
}
void union_set(vector<int> &parent, int x, int y) {
  parent[find(parent, y)] = find(parent, x);
}
vector<w_edge> kruskal_mst(Graph &graph, int src, int n) {
  if (graph.size() == 0)
    return {};

  if (!graph.count(src))
    return {};

  vector<w_edge> result;
  // get edges in tuple format
  priority_queue<w_edge, vector<w_edge>, Edge_Comparator_min> pq;

  for (auto &pair : graph) {
    for (auto edge : pair.second) {
      pq.push({pair.first, edge.first, edge.second});
    }
  }

  // initialising parent vector
  vector<int> parent(n);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  while (!pq.empty()) {
    int s, d, w;
    tie(s, d, w) = pq.top();
    pq.pop();
    if (find(parent, s) == find(parent, d))
      continue;
    union_set(parent, s, d);
    result.push_back({s, d, w});
  }
  return result;
}

int main() {
  Graph graph;

  int n;
  int e;
  cin >> n >> e;
  int src, dst, w;
  for (int i = 0; i < e; i++) {
    cin >> src >> dst >> w;
    graph[src].push_back({dst, w});
  }
  vector<w_edge> mst = kruskal_mst(graph, 0, n);
  cout << "\nMinimum Spanning Tree" << endl;
  int total_cost = 0;
  for (auto x : mst) {
    cout << endl;
    cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x);
    total_cost += get<2>(x);
  }
  cout << endl << "Total Cost : " << total_cost << endl;
}
