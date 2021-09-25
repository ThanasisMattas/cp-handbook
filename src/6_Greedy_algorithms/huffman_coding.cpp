#include <bits/stdc++.h>

using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  out << '[';
  if (!v.empty()) {
    copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
    cout << "\b\b";
  }
  out << ']';
  return out;
}


class Node
{
  Node* right;
  Node* left;
  int weight;
  char name;

  public:
  Node();
  Node(Node* right=nullptr, Node* left=nullptr, int weight=0, char name=' ')
  : right(right), left(left), weight(weight), name(name) {}

  bool operator==(Node* node)
  {
    if (this-> left == node-> left && this-> right == node-> right
        && this-> weight == node-> weight && this-> name == node-> name)
      return true;
    return false;
  }

  void setRight(Node* right) {this-> right = right;}
  void setLeft(Node* left) {this-> left = left;}
  void setWeight(int weight) {this-> weight = weight;}
  void setName(char name) {this-> name = name;}

  Node* getRight() {return this-> right;}
  Node* getLeft() {return this-> left;}
  int getWeight() {return this-> weight;}
  char getName() {return this-> name;}
};


class BTree
{
  public:
  Node* insert(Node* head, Node* new_node)
  {
    if (new_node == head) return head;
    Node* new_head = new Node(head,
                              new_node,
                              head-> getWeight() + new_node-> getWeight(),
                              ' ');
    return new_head;
  }
};


void solve(int y = 0)
{
  multimap<int, Node*> freq;
  freq.insert(make_pair(5, new Node(nullptr, nullptr, 5, 'A')));
  freq.insert(make_pair(1, new Node(nullptr, nullptr, 1, 'B')));
  freq.insert(make_pair(2, new Node(nullptr, nullptr, 2, 'C')));
  freq.insert(make_pair(1, new Node(nullptr, nullptr, 1, 'D')));

  BTree hoffman;
  Node* head = (*freq.begin()).second;
  for (multimap<int, Node*>::iterator it = freq.begin();
       it != freq.end();
       ++it) {
    head = hoffman.insert(head, (*it).second);
  }

  string codeword;
  while (head-> getRight()) {
    cout << head-> getLeft()-> getName() << ' ' << codeword + '0' << '\n';
    head = head-> getRight();
    codeword += '1';
  }
  cout << head-> getName() << ' ' << codeword << '\n';
}


int main()
{
  solve();
}