# binary tree level order traversal
# python implementation

class treeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def __repr__(self):
        return str(self.val)


def levelOrderTraversal(root):
    '''
    A function that traverse a binary tree in level order.
    '''
    queue, seque = [root], []
    curr = root
    while queue:
        curr = queue[0]
        if curr.left:
            queue.append(curr.left)
        if curr.right:
            queue.append(curr.right)
        print(curr, end=' ')
        queue.pop(0)


        
