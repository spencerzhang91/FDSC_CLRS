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

tree = ('100', ('1','3',('4','7',None)), ('2','5','6'))

def CreateBiTree(infoset):
    '''
    Take a tuple contains binary tree structure information as
    argument, construct tree recursively and return the root.
    Input form: (root, leftsubtree, rightsubtree), recursively.
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
        root.left = CreateBTree(leftsub)
        root.right = CreateBTree(rightsub)
    return root

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.val, end=' ')

def iter_postorder1(root):
    stack = []
    lastvisited = None
    while root or stack:
        if root:
            stack.append(root)
            root = root.left
        else:
            peek = stack[-1]
            if peek.right and lastvisited != peek.right:
                root = peek.right
            else:
                print(peek, end=' ')
                lastvisited = stack.pop()

def iter_postorder2(root):
    stack = [root]
    prev = curr = None
    while stack:
        curr = stack[-1]
        if not prev or prev.left == curr or prev.right == curr:
            if curr.left:
                stack.append(curr.left)
            elif curr.right:
                stack.append(curr.right)
            else:
                print(curr, end=' ')
                stack.pop()
        elif curr.left == prev:
            if curr.right:
                stack.append(curr.right)
            else:
                print(curr, end=' ')
                stack.pop()
        elif curr.right == prev:
            print(curr, end=' ')
            stack.pop()
        prev = curr

def iter_refinedp2(root):
    stack = [root]
    prev = curr = None
    while stack:
        curr = stack[-1]
        if not prev or prev.left == curr or prev.right == curr:
            if curr.left:
                stack.append(curr.left)
            elif curr.right:
                stack.append(curr.right)
        elif curr.left == prev:
            if curr.right:
                stack.append(curr.right)
        else:
            print(curr, end=' ')
            stack.pop()
        prev = curr


if __name__ == '__main__':
    
    test = CreateBiTree(tree)

    iter_refinedp2(test)



