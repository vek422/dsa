#include "./adj_list.h"
#include <iostream>
#include <stack>
using namespace std;

void dfs(Graph g, int start) {
  vector<bool> visited(g.vertices, false);
  stack<int> tmp;
  tmp.push(start);
  visited[start] = true;
  cout << start << " ";
  while (!tmp.empty()) {
    int src = tmp.top();
    tmp.pop();
    for (auto adj : g.adjList[src]) {
      if (visited[adj])
        continue;
      visited[adj] = true;
      cout << adj << " ";
      tmp.push(adj);
    }
  }
}

int main() {
  int size;
  cout << "size : ";
  cin >> size;
  Graph g(size);
  cout << "edges : ";
  int edges;
  cin >> edges;
  int src, dest;
  for (int i = 0; i < edges; i++) {
    cin >> src >> dest;
    g.addEdge(src, dest);
  }
  g.printGraph();
  cout << "src : ";
  cin >> src;
  cout << "DFS : ";
  dfs(g, src);
}
