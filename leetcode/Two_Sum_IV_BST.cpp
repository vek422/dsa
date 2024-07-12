#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int data) {
    left = nullptr;
    right = nullptr;
    val = data;
  }
};

TreeNode *insert(TreeNode *root, int val) {
  if (root == nullptr) {
    root = new TreeNode(val);
    return root;
  }
  if (val < root->val) {
    root->left = insert(root->left, val);
    return root;
  }
  root->right = insert(root->right, val);
  return root;
}

void display(TreeNode *root) {
  if (root == nullptr)
    return;
  display(root->left);
  cout << root->val << " ";
  display(root->right);
}
bool findTarget(TreeNode *root, int k) {
  if (root == nullptr) {
    cout << endl << "false at null" << " " << k;
    return false;
  }

  TreeNode *second;
  int diff = abs(root->val - k);
  if (diff == root->val) {
    cout << endl << "false at " << root->val << " " << k;
    return false;
  }
  if (diff < root->val) {
    second = root->left;
  } else {
    second = root->right;
  }
  while (second != nullptr) {
    if (diff == second->val) {
      return true;
    }
    if (diff < second->val) {
      second = second->left;

    } else {
      second = second->right;
    }
  }
  return findTarget(root->left, k) || findTarget(root->right, k);
}

int main() {
  TreeNode *root = nullptr;
  int n;
  int val;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val;
    root = insert(root, val);
  }
  cout << "k :";
  int k;
  cin >> k;
  cout << (findTarget(root, k) ? "Tree" : "False") << endl;
}
