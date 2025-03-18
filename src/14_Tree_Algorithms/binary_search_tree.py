class _Node:

  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None

  def insert(self, data):
    if data <= self.data:
      if self.left:
        self.left.insert(data)
      else:
        self.left = _Node(data)
    else:
      if self.right:
        self.right.insert(data)
      else:
        self.right = _Node(data)

  def contains(self, data):
    if self.data == data:
      return True
    if data <= self.data:
      if self.left:
        return self.left.contains(data)
      else:
        return False
    else:
      if self.right:
        return self.right.contains(data)
      else:
        return False


class BinaryTree:

  def __init__(self):
    self.root = None

  def insert(self, data):
    if self.root:
      self.root.insert(data)
    else:
      self.root = _Node(data)

  def contains(self, data):
    if self.root:
      return self.root.contains(data)
    return False

  def traverse_pre_order(self):
    yield from self._traverse_pre_order(self.root)

  def traverse_in_order(self):
    yield from self._traverse_in_order(self.root)

  def traverse_post_order(self):
    yield from self._traverse_post_order(self.root)

  @staticmethod
  def _traverse_pre_order(node):
    if node:
      yield node.data
      yield from BinaryTree._traverse_pre_order(node.left)
      yield from BinaryTree._traverse_pre_order(node.right)

  @staticmethod
  def _traverse_in_order(node):
    if node:
      yield from BinaryTree._traverse_in_order(node.left)
      yield node.data
      yield from BinaryTree._traverse_in_order(node.right)

  @staticmethod
  def _traverse_post_order(node):
    if node:
      yield from BinaryTree._traverse_post_order(node.left)
      yield from BinaryTree._traverse_post_order(node.right)
      yield node.data


if __name__ == '__main__':
  arr = [5, 3, 4, 6, 2, 7, 1]
  tree = BinaryTree()
  for x in arr:
    tree.insert(x)

  print("Pre-order :", ' '.join(map(str, tree.traverse_pre_order())))
  print("In-order  :", ' '.join(map(str, tree.traverse_in_order())))
  print("Post-order:", ' '.join(map(str, tree.traverse_post_order())))

  print()
  for x in [3, 4, 8]:
    print(f"tree.contains({x}) {tree.contains(x)}")
