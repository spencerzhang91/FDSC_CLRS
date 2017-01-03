class treeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None
        self.height = -1


def height(node:treeNode):
    if node.left == None and node.right == None:
        node.height = -1
    else:
        node.height = max(height(node.left), height(node.right)) + 1


n1 = treeNode(10)
n2 = treeNode(20)
n3 = treeNode(4)
n4 = treeNode(18)

n1.left = n3
n1.right = n2
n2.left = n4

height(n1)
print(n1.height)
