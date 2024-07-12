#include <bits/stdc++.h>
using namespace std;

class Tree_node {
public:
  int data;
  Tree_node *left;
  Tree_node *right;
  Tree_node(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class Tree {
public:
  Tree_node *root;
  Tree() { root = nullptr; }
  void insert() {}
  void sample_tree() {
    root = new Tree_node(0);
    root->left = new Tree_node(1);
    root->right = new Tree_node(2);
    auto tmp = root->left;
    tmp->left = new Tree_node(4);
    tmp->right = new Tree_node(5);
    tmp = root->right;
    tmp->left = new Tree_node(6);
    tmp->right = new Tree_node(7);
  }
  void preorder(Tree_node *root) {
    if (root == nullptr) {
      return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
  void preorder_iterative() {
    if (root == nullptr)
      return;
    stack<Tree_node *> tmp;
    tmp.push(root);
    while (!tmp.empty()) {
      auto top = tmp.top();
      tmp.pop();
      if (top == nullptr)
        continue;
      cout << top->data << " ";
      tmp.push(top->right);
      tmp.push(top->left);
    }
  }
  void postorder_recursive() {}
  void postorder_iterative() {}
  void inorder_itertive() {
    stack<Tree_node *> tmp;
    auto *curr = root;
    while (curr != nullptr || !tmp.empty()) {
      while (curr != nullptr) {
        tmp.push(curr);
        curr = curr->left;
      }
      curr = tmp.top();
      tmp.pop();
      cout << curr->data << " ";
      curr = curr->right;
    }
  }
  void inorder_recursive(Tree_node *root) {
    if (root == nullptr)
      return;
    inorder_recursive(root->left);
    cout << root->data << " ";
    inorder_recursive(root->right);
  }
  void verticle_order_traversal(Tree_node *root) {
    unordered_map<int, vector<Tree_node *>> x;
    stack<pair<Tree_node *, int>> tmp;
    int min_lvl = 0;
    int max_lvl = 0;
    tmp.push({root, 0});
    while (!tmp.empty()) {
      auto top = tmp.top();
      tmp.pop();
      if (top.first == nullptr)
        continue;
      x[top.second].push_back(top.first);
      max_lvl = max(top.second + 1, max_lvl);
      tmp.push({top.first->right, top.second + 1});
      min_lvl = min(top.second - 1, min_lvl);
      tmp.push({top.first->left, top.second - 1});
    }
    cout << endl;
    for (int i = min_lvl; i <= max_lvl; i++) {
      for (auto y : x[i]) {
        cout << y->data << " ";
      }
    }
  }
  void boudry_traversal(Tree_node *root) {
    vector<int> result;

    // doing left most Traversal
    stack<Tree_node *> tmp;
    set<int> visited;
    auto curr = root;
    while (curr != nullptr) {
      tmp.push(curr);
      result.push_back(curr->data);
      visited.insert(curr->data);
      curr = curr->left;
    }

    // pop the stack and check for leaf nodes
    while (!tmp.empty()) {
      auto top = tmp.top();
      tmp.pop();
      if (top == nullptr)
        continue;
      if (top->left == nullptr && top->right == nullptr) {
        if (!visited.count(top->data)) {
          result.push_back(top->data);
          continue;
        }
      }
      tmp.push(top->right);
      tmp.push(top->left);
    }

    // go to extreme right and store result in stack
    stack<int> b_right;
    curr = root->right;
    while (curr != nullptr) {
      b_right.push(curr->data);
      curr = curr->right;
    }

    while (!b_right.empty()) {
      auto top = b_right.top();
      b_right.pop();
      result.push_back(top);
    }

    for (auto x : result) {
      cout << x << " ";
    }
  }
};

int main() {
  Tree t;
  t.sample_tree();
  cout << "preorder_iterative " << endl;
  t.preorder_iterative();
  cout << endl << "preorder recursive " << endl;
  t.preorder(t.root);
  cout << endl << "Inorder recursive" << endl;
  t.inorder_recursive(t.root);
  cout << endl << "Inorder Iterative" << endl;
  t.inorder_itertive();
  cout << endl << "Verticle Order Traversal" << endl;
  t.verticle_order_traversal(t.root);
  cout << endl << "boudry_traversal" << endl;
  t.boudry_traversal(t.root);
  return 0;
}
