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
    head = LinkedListNode(nodes[0])
    head.next = None
    curr = head
    for i in range(1, len(nodes)):
        temp = LinkedListNode(nodes[i])
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

h0 = genLinkedList([0, 1, 2])
h1 = genLinkedList([1, 0, 3, 4])
h2 = genLinkedList([2, 0, 5, 6])
h3 = genLinkedList([3, 1, 7])
h4 = genLinkedList([4, 1, 7])
h5 = genLinkedList([5, 2, 7])
h6 = genLinkedList([6, 2, 7])
h7 = genLinkedList([7, 3, 4, 5, 6])

# global variables below:
graph = [h0, h1, h2, h3, h4, h5, h6, h7]
visited = [False] * 8


def dfs(v):
    """
    This function does depth first search for undirected unweighted graph.
    Parameter v: the entry node number of the graph.
    """
    print(v, end=" ")
    visited[v] = True
    stack = [v]
    curr = graph[v].next
    while stack:
        while curr:
            if not visited[curr.val]:
                print(curr.val, end=" ")
                visited[curr.val] = True
                stack.append(curr.val)
                curr = graph[curr.val] # this step switch curr to other adj list
            else:
                curr = curr.next
        curr = graph[stack.pop()]
    print()
    print(visited)


if __name__ == "__main__":
    print(visited)
    # disLinkedList(h0)
    # disLinkedList(h7)
    dfs(0)