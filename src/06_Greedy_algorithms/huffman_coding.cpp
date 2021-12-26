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
  char m_name;
  Node* m_right;
  Node* m_left;

  public:
  Node(char name='-', Node* right=nullptr, Node* left=nullptr)
  : m_name(name), m_right(right), m_left(left) {}

  void setRight(Node* right) {m_right = right;}
  void setLeft(Node* left) {m_left = left;}
  void setName(char name) {m_name = name;}

  Node* getRight() {return m_right;}
  Node* getLeft() {return m_left;}
  char getName() {return m_name;}
};


class BTree
{
  public:
  Node* insert(Node* head, Node* new_node)
  {
    if (head == nullptr) return new_node;
    return new Node('-', head, new_node);
  }

  void print_code(Node* head)
  {
    string codeword;
    while (head-> getRight()) {
      cout << head-> getLeft()-> getName() << ' ' << codeword + '0' << '\n';
      head = head-> getRight();
      codeword += '1';
    }
    cout << head-> getName() << ' ' << codeword << '\n';
  }
};


string s = "AABACDACA";


void solve(int y = 0)
{
  // construct the frequency map and sort by value
  unordered_map<char, int> freq;
  for (auto c : s) {
    if (freq.find(c) == freq.end()) freq[c] = 1;
    else ++freq[c];
  }
  vector<pair<char, int> > freq_vect(freq.begin(), freq.end());
  sort(freq_vect.begin(), freq_vect.end(), [](auto &left, auto &right) {
    return left.second < right.second;
  });

  BTree huffman;
  Node* head = nullptr;

  // populate the binary tree
  for (auto p : freq_vect)
    head = huffman.insert(head, new Node(p.first));

  huffman.print_code(head);
}


int main() {solve();}