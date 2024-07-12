#include <bits/stdc++.h>
using namespace std;
#include "./adj_list.h"

Graph::Graph(int vertices) {
  this->vertices = vertices;
  adjList.resize(vertices);
}

void Graph::addEdge(int src, int dest) {
  if (src >= vertices || dest >= vertices) {
    cout << "\nout of bound vertices" << endl;
    return;
  }
  adjList[src].push_back(dest);
  adjList[dest].push_back(src);
}
void Graph::printGraph() {
  cout << "vertex  adjecent-vertices" << endl;
  for (int i = 0; i < vertices; i++) {
    cout << i;
    for (auto it : adjList[i]) {
      cout << " -> " << it;
    }
    cout << endl;
  }
}
