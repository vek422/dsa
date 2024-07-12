#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Edge {
public:
  char dest;
  int weight;
  Edge(char dest, int weight) : dest(dest), weight(weight) {}
};

class Graph {
public:
  unordered_map<char, vector<Edge>> graph;
  void add_edge(char src, char dest, int weight) {
    graph[src].push_back(Edge(dest, weight));
    graph[dest].push_back(Edge(src, weight));
  }
  void print_graph() {
    for (auto i : graph) {
      cout << i.first;
      for (auto node : graph[i.first]) {
        cout << " -> (" << node.dest << "," << node.weight << ")";
      }
      cout << endl;
    }
  }
};

int main() {
  Graph g;
  g.add_edge('a', 'b', 10);
  g.add_edge('b', 'c', 2);
  g.print_graph();
  ;
}
