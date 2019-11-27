public interface MyTree<E extends Comparable<E>>{
	/** Return true if the element is in the tree */
	public abstract boolean search(E e);

	/** Insert element e into the binary search tree 
	 *  Return true if the element is inserted successfully */
	public abstract boolean insert(E e);

	/** Delete the specified element from the tree 
	 *  Return true if the element is delete successfully */
	public abstract boolean delete(E e);

	/** Inorder traversal from the root */
	public abstract void inorder();

	/** Postorder traversal from the root */
	public abstract void postorder();

	/** Preorder traversal from the root */
	public abstract void preorder();

	/** Get the number of nodes in the tree */
	public abstract int getSize();

	/** Return true if the tree is empty */
	public abstract boolean isEmpty();

	/** Return an iterator to traverse elements in the tree */
	public abstract java.util.Iterator iterator();
}