/* learning binary tree with thread from FDSC on page 133-137 */
/* code list 5-12 */
void insert_right(threaded_pointer parent, threaded_pointer child)
{
	/* insert child as the right child of parent in a threaded binary tree */
	threaded_pointer temp;
	child->right_child = parent->right_child;
	child->right_thread = parent->right_thread;
	child->left_child = parent;
	child->left_thread = true;
	parent->right_child = child;
	parent->right_thread = false;
	if (!child->right_thread)
	{
		temp = insucc(child);
		temp->left_child = child;
	}
}