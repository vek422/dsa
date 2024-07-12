#include <bits/stdc++.h>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;
typedef tuple<int, int, int> w_edge; // src dst wieght
typedef unordered_map<int, vector<pair<int, int>>> Graph;
struct Edge_Comparator {
  bool operator()(w_edge left, w_edge right) {
    return get<2>(left) > get<2>(right);
  }
};

vector<w_edge> prism_mst(Graph graph, int src) {
  priority_queue<w_edge, vector<w_edge>, Edge_Comparator> tmp;
  set<int> visited;
  visited.insert(src);
  int cost = 0;
  vector<w_edge> mst;
  for (auto &adj : graph[src]) {
    tmp.push(make_tuple(src, adj.first, adj.second));
  }

  // start the algorithm
  while (!tmp.empty()) {
    int s, d, w;
    tie(s, d, w) = tmp.top();
    tmp.pop();
    if (visited.count(d))
      continue;
    mst.push_back(make_tuple(s, d, w));
    visited.insert(d);
    cost += w;
    for (auto &adj : graph[d]) {
      tmp.push(make_tuple(d, adj.first, adj.second));
    }
  }
  cout << endl << "total cost" << cost << endl;
  return mst;
}

int main() {
  // adk list represenation of graph
  Graph graph;
  int e;
  cin >> e;
  int src, dst, weight;
  for (int i = 0; i < e; i++) {
    cin >> src >> dst >> weight;
    graph[src].push_back({dst, weight});
    graph[dst].push_back({src, weight});
  }
  auto mst = prism_mst(graph, 0);

  for (auto edge : mst) {
    int src, dst, w;
    tie(src, dst, w) = edge;
    cout << endl;
    cout << src << " " << dst << " " << w;
  }
}
