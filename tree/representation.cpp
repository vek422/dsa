#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Tree_node {
public:
  int value;
  vector<Tree_node *> childs;

  Tree_node() { value = 0; }
  Tree_node(int value) { this->value = value; }
};

class Tree {
public:
  Tree_node *root;
  int number_of_nodes;
  Tree() {
    root = nullptr;
    number_of_nodes = 0;
  }

  void insert(int parent, int child) {
    number_of_nodes++;
    if (this->root == nullptr) {
      this->root = new Tree_node(child);
      return;
    }
    if (root->value == parent) {
      root->childs.push_back(new Tree_node(child));
      return;
    }
    queue<Tree_node *> tmp;
    tmp.push(this->root);
    while (!tmp.empty()) {
      auto *top = tmp.front();
      tmp.pop();
      if (top->value == parent) {
        top->childs.push_back(new Tree_node(child));
        return;
      }
      for (auto child : top->childs) {
        tmp.push(child);
      }
    }
  }

  void bfs() {
    if (root == nullptr) {
      cout << "Tree is empty" << endl;
      return;
    }
    queue<Tree_node *> tmp;
    tmp.push(root);
    while (!tmp.empty()) {
      Tree_node *top = tmp.front();
      tmp.pop();
      cout << top->value << " ";
      for (auto child : top->childs) {
        tmp.push(child);
      }
    }
  }
  vector<Tree_node *> get_childs(int node) {
    if (root == nullptr)
      return {};
    queue<Tree_node *> tmp;
    tmp.push(root);
    while (!tmp.empty()) {
      auto top = tmp.front();
      tmp.pop();
      if (top->value == node) {
        return top->childs;
      }
      for (auto child : top->childs) {
        tmp.push(child);
      }
    }
    return {};
  }
  int diametre() {
    if (root == nullptr) {
      cout << "empty tree" << endl;
      return 0;
    }
    recursive_dfs_diametre(root->value, -1);
    int x = 0;
    for (auto &z : max_diametre) {
      x = max(x, z.second);
      cout << z.first << " " << z.second << endl;
    }
    return x;
  }

private:
  unordered_map<int, int> max_diametre;
  unordered_map<int, int> toLeaf;
  void recursive_dfs_diametre(int node, int parent) {
    vector<int> leafLength;
    for (auto child : this->get_childs(node)) {
      recursive_dfs_diametre(child->value, node);
      leafLength.push_back(toLeaf[child->value]);
    }

    if (leafLength.empty()) {
      toLeaf[node] = 0;
    } else {
      toLeaf[node] = 1 + *max_element(leafLength.rbegin(), leafLength.rend());
    }

    if (leafLength.size() > 1) {
      sort(leafLength.rbegin(), leafLength.rend());
      max_diametre[node] = 2 + leafLength[0] + leafLength[1];
    } else if (leafLength.size() == 1) {
      max_diametre[node] = 1 + leafLength[0];
    } else {
      max_diametre[node] = 0;
    }
  }
};

int main() {
  Tree *root = new Tree();
  cout << "Enter Number of nodes : ";
  int n;
  cin >> n;
  int c, p;
  cout << "Enter child and parent :";
  for (int i = 0; i < n; i++) {
    cin >> c >> p;
    root->insert(p, c);
  }
  cout << "BFS" << endl;
  root->bfs();

  cout << "Diametre : " << root->diametre() << endl;
}
