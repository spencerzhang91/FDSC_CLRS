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
    if not (preseq or inseq):
        return None
    else:
        curr = preseq[0]
        in_left_part, in_right_part = inseq.split(curr)
        pre_left_part = preseq[1: len(in_left_part)+1]
        pre_right_part = preseq[len(in_left_part)+1: ]
        root = treeNode(curr)
        root.left = CreateBiTree(pre_left_part, in_left_part)
        root.right = CreateBiTree(pre_right_part, pre_right_part)
        return root

def preorder(tree):
    if tree != None:
        print(tree, end=' ')
        preorder(tree.left)
        preorder(tree.right)


if __name__ == "__main__":
    preorder = "ABCDEFGHI"
    inorder = "BCAEDGHFI"
    tree = CreateBiTree(preorder, inorder)
    

    

    

