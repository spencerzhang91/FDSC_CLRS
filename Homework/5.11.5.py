'''
Excercise 5.11.5.py
An algorithm to generate an unique binary tree with its preorder
and inorder sequence.
Frequently used helper function when learning binary tree data
structure. And is simpler than file 5-2_CreateBiTree_recursive.py
'''
# definition of tree node
class treeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def __repr__(self):
        return str(self.val)


def CreateBiTree(preseq, inseq):
    '''
    Input is two string or list of tree traversal sequences, inorder and
    preorder. This function constructs the unique tree that should generate
    the inputed sequences.
    '''
    root = preseq[0]
    tree = treeNode(root)



