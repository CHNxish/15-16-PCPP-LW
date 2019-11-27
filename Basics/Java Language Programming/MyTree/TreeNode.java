public class TreeNode<E extends Comparable<E>>{
	TreeNode<E> left = null;
	TreeNode<E> right = null;
	E element;

	public TreeNode(){
	}

	public TreeNode(E e){
		element = e;
	}

	public E getElement(){
		return element;
	}

	public void setElement(E e){
		element = e;
	}

	public TreeNode<E> getLeftChild(){
		return left;
	}

	public void setLeftChild(TreeNode<E> l){
		left = l;
	}

	public TreeNode<E> getRightChild(){
		return right;
	}

	public void setRightChild(TreeNode<E> r){
		right = r;
	}
}