''' Create binary tree through a string which using parenthesis to represent
father-child relationship. '''

class BTreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def __repr__(self):
        return 'value:'+str(self.val)

# A typical string is like: a(b(ef)c(0g))
# or may be better like this: a(b(e,f),c(0,g)) ?

def CreateBTree1(structStr):
    ''' Analyze the struct info string using a stack to help create a binary
    tree, each node's val is a single char. This function returns the root of
    the tree. '''
    stack = []
    if len(structStr) <= 0:
        return None
    root = BTreeNode(structStr[0])
    for char in sttructStr:
    	   
    

info = 'a(b(ef)c(0g))'
l = CreateBTree(info)


def CreateBTree2(structSet):
    pass



