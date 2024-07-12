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
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
  int root1Val = root1 == nullptr ? 0 : root1->val;
  int root2Val = root2 == nullptr ? 0 : root2->val;
  TreeNode *result = new TreeNode(root1Val + root2Val);
  TreeNode *root1Left = root1 == nullptr ? nullptr : root1->left;
  TreeNode *root1Right = root2 == nullptr ? nullptr : root1->right;
  TreeNode *root2Left = root2 == nullptr ? nullptr : root2->left;
  TreeNode *root2Right = root2 == nullptr ? nullptr : root2->right;
  result->left = mergeTrees(root1Left, root2Left);
  result->right = mergeTrees(root1Right, root2Right);
  return result;
}
int main() {
  TreeNode *root1 = nullptr;
  TreeNode *root2 = nullptr;
  int n;
  cout << "Enter First Tree";
  cin >> n;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    root1 = insert(root1, tmp);
  }
  cout << "Second Tree : ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    root2 = insert(root2, tmp);
  }

  auto result = mergeTrees(root1, root2);
  cout << "result" << endl;
  display(result);
}
