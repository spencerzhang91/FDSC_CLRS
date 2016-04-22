# Using python to implement a graph data structure

class LinkedListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None

    def __repr__(self):
        return str(self.val) + (" -> " if self.next else " ->end")

def genLinkedList(nodes):
    """
    To generate a linked list using values in list of nodes
    """
    if not nodes:
        return None
    head = nodes[0]
    head.next = None
    curr = head
    for i in range(1, len(nodes)):
        temp = nodes[i]
        curr.next = temp
        curr = temp
    return head

def disLinkedList(head):
    """
    Display linked list from head to the end with managed format.
    """
    if type(head) is LinkedListNode:
        curr = head
        while curr:
            print(curr, end='')
            curr = curr.next
    print()

"""
The graph structure: (adjacency matrix discription)

|    | v0 | v1 | v2 | v3 | v4 | v5 | v6 | v7 |
| v0 |    |  + |  + |    |    |    |    |    |
| v1 |  + |    |    |  + |  + |    |    |    |
| v2 |  + |    |    |    |    |  + |  + |    |
| v3 |    |  + |    |    |    |    |    |  + |
| v4 |    |  + |    |    |    |    |    |  + |
| v5 |    |    |  + |    |    |    |    |  + |
| v6 |    |    |  + |    |    |    |    |  + |
| v7 |    |    |    |  + |  + |  + |  + |    |

"""
# Temporarily set a graph below
v0 = v1 = v2 = v3 = v4 = v5 = v6 = v7 = LinkedListNode()

h0 = genLinkedList([v0, v1, v2])
h1 = genLinkedList([v1, v0, v3, v4])
h2 = genLinkedList([v2, v0, v5, v6])
h3 = genLinkedList([v3, v1, v7])
h4 = genLinkedList([v4, v1, v7])
h5 = genLinkedList([v5, v2, v7])
h6 = genLinkedList([v6, v2, v7])
h7 = genLinkedList([v7, v3, v4, v5, v6])

# global variables below:
graph = [h0, h1, h2, h3, h4, h5, h6, h7]
visited = [False] * 8


def dfs(v):
    """
    This function does depth first search for undirected unweighted graph.
    Parameter v: the entry node number of the graph.
    """
    visited[v] = True
    curr = graph[v]
    while curr:
        pass
