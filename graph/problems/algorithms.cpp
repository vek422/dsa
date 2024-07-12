#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph {
public:
  unordered_map<char, vector<char>> nodes;
  void add_edge(char src, char dst) {
    nodes[src].push_back(dst);
    nodes[dst].push_back(src);
  }
  void print_graph() {
    for (auto i : nodes) {
      cout << i.first;
      for (auto adj : i.second) {
        cout << "-> " << adj;
      }
      cout << endl;
    }
    cout << endl;
  }

  /*bool has_path(char src, char dst) {*/
  /*  if (!nodes.count(src))*/
  /*    return false;*/
  /*  if (src == dst) {*/
  /*    return true;*/
  /*  }*/
  /*  for (char neighbour : nodes[src]) {*/
  /*    if (has_path(neighbour, dst)) {*/
  /*      return true;*/
  /*    }*/
  /*  }*/
  /*  return false;*/
  /*}*/
  /*LOGIC AVOIDING CYCLES*/
  bool has_path(char src, char dst) {
    set<char> visited;
    stack<char> tmp;
    tmp.push(src);
    while (!tmp.empty()) {
      char top = tmp.top();
      tmp.pop();
      visited.insert(top);
      if (top == dst)
        return true;
      for (char adj : nodes[top]) {
        if (!visited.count(adj)) {
          tmp.push(adj);
        }
      }
    }
    return false;
  }

  // islands are the componets of graph(the graphs disconnected sections of the
  // graph )
  int number_of_island() {
    set<char> visited;
    int count = 0;
    for (auto i : nodes) {
      if (visited.count(i.first))
        continue;
      visited.insert(i.first);
      // traverse the graph from node i.first
      {
        stack<char> tmp;
        tmp.push(i.first);
        while (!tmp.empty()) {
          char top = tmp.top();
          tmp.pop();
          visited.insert(top);
          for (auto adj : nodes[top]) {
            if (!visited.count(adj)) {
              tmp.push(adj);
            }
          }
        }
        count++;
      }
    }
    return count;
  }
  int largest_island() {
    set<char> visited;
    int largest = 0;
    for (auto i : nodes) {
      if (visited.count(i.first))
        continue;
      /*visited.insert(i.first);*/

      // traverse the component from i.first
      {
        int count = 0;
        /*cout << endl << count << endl;*/
        queue<char> tmp;
        tmp.push(i.first);
        while (!tmp.empty()) {
          char curr = tmp.front();
          tmp.pop();
          if (visited.count(curr))
            continue;
          visited.insert(curr);
          count++;
          for (auto adj : nodes[curr]) {
            if (visited.count(adj))
              continue;
            tmp.push(adj);
          }
        }
        cout << "\n" << count << endl;
        largest = max(count, largest);
      }
    }
    return largest;
  }
};

int main() {
  Graph g;
  int size;
  cout << "size ";
  cin >> size;
  char src, dest;
  cout << "edges\n";
  for (int i = 0; i < size; i++) {
    cin >> src >> dest;
    g.add_edge(src, dest);
  }
  g.print_graph();
  while (false) {
    cout << "check path \n";
    cin >> src >> dest;
    if (g.has_path(src, dest)) {
      cout << "True";
    } else {
      cout << "false";
    }
  }
  /*cout << "\ntotal islands " << g.number_of_island() << endl;*/
  cout << "\nLargest Island " << g.largest_island() << endl;
}
