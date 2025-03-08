from collections import Counter
from operator import itemgetter


text = "AABACDACA"


class Node:
  def __init__(self, name=None, right=None, left=None):
    self.name = name
    self.right = right
    self.left = left


class BTree:
  @staticmethod
  def insert(head, node):
    if head is None:
      return node
    return Node(right=head, left=node)

  @staticmethod
  def print_code(head):
    code = ''
    while head.left:
      print(head.left.name, code + '0')
      code += '1'
      head = head.right
    print(head.name, code)


def solve():
  # [('B', 1), ('D', 1), ('C', 2), ('A', 5)]
  counter = sorted(Counter(text).items(), key=itemgetter(1))
  head = None

  for entry in counter:
    head = BTree.insert(head, Node(entry[0]))

  BTree.print_code(head)


if __name__ == '__main__':
  solve()
