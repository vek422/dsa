#include "./adj_list.h"
#include <iostream>
#include <queue>
using namespace std;

void bfs(Graph g, int src) {
  vector<bool> visited(g.vertices, false);
  queue<int> tmp;
  visited[src] = true;
  cout << src << " ";
  tmp.push(src);
  while (!tmp.empty()) {
    int src = tmp.front();
    tmp.pop();
    for (auto u : g.adjList[src]) {
      if (visited[u])
        continue;
      visited[u] = true;
      cout << u << " ";
      tmp.push(u);
    }
  }
}

int main() {
  int size;
  cin >> size;
  Graph g(size);
  int m;
  cin >> m;
  int src, dest;
  for (int i = 0; i < m; i++) {
    cin >> src >> dest;
    g.addEdge(src, dest);
  }
  int start;
  cin >> start;
  cout << "\nBFS : ";
  bfs(g, start);
  return 0;
}
