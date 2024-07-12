#include "./adj_list.h"
#include <iostream>
#include <stack>
using namespace std;

// using dfs
bool isConnected(Graph g) {
  int src = 0;
  vector<bool> visited(g.vertices, false);
  stack<int> tmp;
  visited[src] = true;
  tmp.push(src);
  while (!tmp.empty()) {
    int src = tmp.top();
    tmp.pop();
    for (auto adj : g.adjList[src]) {
      if (visited[adj])
        continue;
      visited[adj] = true;
      tmp.push(adj);
    }
  }
  bool flag = true;

  for (auto i : visited) {
    flag = flag & i;
  }
  return flag;
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
  if (isConnected(g)) {

    cout << "Connected";
  } else {
    cout << "disconnected";
  }
}
