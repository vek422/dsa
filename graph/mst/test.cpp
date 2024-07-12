
#include <bits/stdc++.h>
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

void union_set(vector<int> &parent, vector<int> &rank, int x, int y) {
  int rootX = find(parent, x);
  int rootY = find(parent, y);
  if (rootX != rootY) {
    if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
  }
}

vector<w_edge> kruskal_mst(Graph &graph, int n) {
  vector<w_edge> result;
  int cost = 0;

  // get edges in tuple format
  priority_queue<w_edge, vector<w_edge>, Edge_Comparator_min> pq;
  for (auto &pair : graph) {
    for (auto edge : pair.second) {
      pq.push({pair.first, edge.first, edge.second});
    }
  }

  // initializing parent and rank vectors
  vector<int> parent(n);
  vector<int> rank(n, 0);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  while (!pq.empty()) {
    int s, d, w;
    tie(s, d, w) = pq.top();
    pq.pop();
    if (find(parent, s) != find(parent, d)) {
      cost += w;
      union_set(parent, rank, s, d);
      result.push_back({s, d, w});
    }
  }
  cout << "Cost: " << cost << endl;
  return result;
}

int main() {
  Graph graph;
  int n, e;
  cin >> n >> e;
  int src, dst, w;
  for (int i = 0; i < e; i++) {
    cin >> src >> dst >> w;
    graph[src].push_back({dst, w});
    graph[dst].push_back({src, w}); // for undirected graph
  }

  vector<w_edge> mst = kruskal_mst(graph, n);
  for (auto x : mst) {
    cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
  }
}
