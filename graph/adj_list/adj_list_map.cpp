#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
public:
  unordered_map<char, vector<char>> nodes;

  void add_edge(char src, char dest) {
    /*if(!nodes.count(src) || !nodes.count(dest)){*/
    /*  cerr<<"\nInvalid Nodes\n";*/
    /*  return;*/
    /*}*/
    nodes[src].push_back(dest);
    nodes[dest].push_back(src);
  }

  void print_graph() {
    for (auto node : nodes) {
      cout << node.first;
      for (auto adj : nodes[node.first]) {
        cout << " -> " << adj;
      }
      cout << endl;
    }
  }
};

int main() {
  Graph g;

  g.add_edge('a', 'b');
  g.add_edge('a', 'c');
  g.print_graph();
}
