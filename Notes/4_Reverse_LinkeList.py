# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        return "[%s --> %s]" % (self.val, self.next)

    def __str__(self):
        return str(self.val)

# approach iterative
class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        new_head = None
        while head != None:
            temp = head
            head = head.next
            temp.next = new_head
            new_head = temp
        return new_head


# approach recursive
class Solution:
    def reverseList(self, head):
        if not head:
            return None
        if not head.next:
            return head
        temp = head.next
        new_head = self.reveseList(temp)
        head.next = None
        temp.next = head
        return new_head

# iterative way to create a list with certain length
def CreateList(len):
    if len <= 0:
        return None
    else:
        front = ListNode(len)
        temp = front
        len -= 1
        for i in range(len):
            curr = ListNode(len-i)
            temp.next = curr
            temp = temp.next
    return front

def display(head):
    while head:
        print(head, end=' ')
        head = head.next
        

if __name__ == '__main__':

    linked_list = CreateList(10)
    display(linked_list)
