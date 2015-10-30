# Excercise 4.2.8.py
'''
class Node:
	def __init__(self, val):
		self.val = val
		self.next = None
'''


def CreateList(array):
	head = Node(0)
	curr = head
	for item in array:
		node = Node(item)
		curr.next = node
		curr = curr.next
	return head

def DisplayList(head):
	while head:
		print(str(head.val) + "->", end=' ');
		head = head.next

def moveRight(left, curr, n):
	pass

def moveLeft(left, curr, n):
	pass


