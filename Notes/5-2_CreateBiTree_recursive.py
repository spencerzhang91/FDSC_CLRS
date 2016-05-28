'''
A module that construct binary tree recursively using nested tuple
as argument.
Frequently used helper function when learning binary tree data
structure.
'''

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def __repr__(self):
        return str(self.val)

tree = ('a', ('b', ('c', 'e', ('f',None,('h','i',None))), ('d',None,'g')), None)

def CreateBiTree(infoset):
    '''
    Take a tuple contains binary tree structure information as
    argument, construct tree recursively and return the root.
    '''
    # print('infoset:', infoset)
    if infoset:
        try:
            root, leftsub, rightsub = infoset
        except ValueError:
            root = infoset[0]
            leftsub = None
            rightsub = None
    else:
        return None
    root = TreeNode(root)
    if not root:
        return None
    else:
        root.left = CreateBiTree(leftsub)
        root.right = CreateBiTree(rightsub)
    return root

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.val, end=' ')

def inorder(root):
    if root:
        inorder(root.left)
        print(root.val, end=' ')
        inorder(root.right)

def preorder(root):
    if root:
        print(root.val, end=' ')
        preorder(root.left)
        preorder(root.right)

        
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

      
if __name__ == '__main__':
    
    test = CreateBiTree(tree)

    preorder(test); print()
    inorder(test); print()
    postorder(test);print()
    levelOrderTraversal(test)

