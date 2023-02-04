#pragma GCC optimize ("03")
#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
  if (!v.empty()) copy(v.begin(), v.end(), ostream_iterator<T>(out, " "));
  return out;
}


struct Node
{
  char name;
  Node* r;
  Node* l;
  Node(char n='-', Node* r=nullptr, Node* l=nullptr): name(n), r(r), l(l) {}
};


struct BTree
{
  Node* insert(Node* head, Node* node)
  {
    if (head == nullptr) return node;
    return new Node('-', head, node);
  }

  void print_code(Node* head)
  {
    string code;
    while (head-> r) {
      cout << head-> l-> name << ' ' << code + '0' << '\n';
      head = head-> r;
      code += '1';
    }
    cout << head-> name << ' ' << code << '\n';
  }
} huffman;


string s = "AABACDACA";


void solve()
{
  unordered_map<char, int> freq;
  for (auto c : s) ++freq[c];
  vector<pair<char, int> > v(freq.begin(), freq.end());
  sort(v.begin(), v.end(), [](auto& l, auto& r) {return l.second < r.second;});
  Node* head = nullptr;
  for (auto p : v) head = huffman.insert(head, new Node(p.first));
  huffman.print_code(head);
}


int main() {solve();}
