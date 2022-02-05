#include <bits/stdc++.h>
using namespace std;


class Node
{
  public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;

  Node(int d): data(d) {};

  void insert(int value)
  {
    if (value <= data) {
      if (left) left-> insert(value);
      else left = new Node(value);
    } else {
      if (right) right-> insert(value);
      else right = new Node(value);
    }
  }

  bool contains(int value)
  {
    if (value == data) return true;
    if (value < data) {
      if (left) return left-> contains(value);
      else return false;
    } else {
      if (right) return right-> contains(value);
      else return false;
    }
  }

  void print_in_order()
  {
    if (left) left-> print_in_order();
    cout << data << ' ';
    if (right) right-> print_in_order();
  }

  void print_pre_order()
  {
    cout << data << ' ';
    if (left) left-> print_pre_order();
    if (right) right-> print_pre_order();
  }

  void print_post_order()
  {
    if (left) left-> print_post_order();
    if (right) right-> print_post_order();
    cout << data << ' ';
  }
};


Node* insert(Node* root, int data)
{
  if (!root) return new Node(data);
  if (data > root-> data) root-> right = insert(root-> right, data);
  else root-> left = insert(root-> left, data);
  return root;
}


const int n = 7;
int arr[n] = {5, 3, 4, 6, 2, 7, 1};
/*
 *          5
 *         / \
 *        3   6
 *       / \   \
 *      2   4   7
 *     /
 *    1
 */


int main()
{
  Node* root = new Node(arr[0]);
  for (int u = 1; u < n; ++u) root-> insert(arr[u]);
  // for (int u = 1; u < n; ++u) root = insert(root, arr[u]);

  cout << "In-order: ";
  root-> print_in_order();
  cout << '\n';
  cout << "Pre-order: ";
  root-> print_pre_order();
  cout << '\n';
  cout << "Post-order: ";
  root-> print_post_order();
  cout << '\n';
}
