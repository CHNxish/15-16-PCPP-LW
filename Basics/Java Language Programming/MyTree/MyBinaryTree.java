public class MyBinaryTree<E extends Comparable<E>> extends MyAbstractTree<E>{
	protected TreeNode<E> root;
	protected int size = 0;

	public MyBinaryTree(){
	}

	public MyBinaryTree(E[] objects){
		for(int i = 0; i < objects.length; i++){
			insert(objects[i]);
		}
	}

	public boolean search(E e){
		TreeNode<E> current = root;

		while(current != null){
			if(e.compareTo(current.getElement()) < 0){
				current = current.getLeftChild();
			}
			else if(e.compareTo(current.getElement()) > 0){
				current = current.getRightChild();
			}
			else{
				return true;
			}
		}

		return false;
	}

	public boolean insert(E e){
		if(root == null){
			root = createNewNode(e);
		}
		else{
			TreeNode<E> parent = null;
			TreeNode<E> current = root;
			while(current != null){
				if(e.compareTo(current.getElement()) < 0){
					parent = current;
					current = current.getLeftChild();
				}
				else if(e.compareTo(current.getElement()) > 0){
					parent = current;
					current = current.getRightChild();
				}
				else{
					return false;
				}
			}

			if(e.compareTo(parent.getElement()) < 0){
				parent.setLeftChild(createNewNode(e));
			}
			else{
				parent.setRightChild(createNewNode(e));
			}
		}

		size++;
		return true;
	}

	protected TreeNode<E> createNewNode(E e){
		return new TreeNode<E>(e);
	}

	public void inorder(){
		inorder(root);
	}

	protected void inorder(TreeNode<E> root){
		if(root == null) return;
		inorder(root.getLeftChild());
		System.out.println(root.getElement() + " ");
		inorder(root.getRightChild());
	}

	public void postorder(){
		postorder(root);
	}

	protected void postorder(TreeNode<E> root){
		if(root == null) return;
		postorder(root.getLeftChild());
		postorder(root.getRightChild());
		System.out.println(root.getElement() + " ");
	}

	public void preorder(){
		preorder(root);
	}

	protected void preorder(TreeNode<E> root){
		if(root == null) return;
		System.out.println(root.getElement() + " ");
		preorder(root.getLeftChild());
		preorder(root.getRightChild());
	}

	public int getSize(){
		return size;
	}

	public TreeNode<E> getRoot(){
		return root;
	}

	public java.util.ArrayList<TreeNode<E>> path(E e){
		java.util.ArrayList<TreeNode<E>> list = new java.util.ArrayList<TreeNode<E>>();
		TreeNode<E> current = root;

		while(current != null){
			list.add(current);
			if(e.compareTo(current.getElement()) < 0){
				current = current.getLeftChild();
			}
			else if(e.compareTo(current.getElement()) > 0){
				current = current.getRightChild();
			}
			else{
				break;
			}
		}

		return list;
	}

	public boolean delete(E e){
		TreeNode<E> parent = null;
		TreeNode<E> current = null;

		while(current != null){
			if(e.compareTo(current.getElement()) < 0){
				parent = current;
				current = current.getLeftChild();
			}
			else if(e.compareTo(current.getElement()) > 0){
				parent = current;
				current = current.getRightChild();
			}
			else{
				break;
			}
		}

		if(current == null)
			return false;

		if(current.left == null){
			if(parent == null){
				root = current.getRightChild();
			}
			else{
				if(e.compareTo(parent.getElement()) < 0){
					parent.setLeftChild(current.getRightChild());
				}
				else{
					parent.setRightChild(current.getRightChild());
				}
			}
		}
		else{
			TreeNode<E> parentOfRightMost = current;
			TreeNode<E> rightMost = current.getLeftChild();

			while(rightMost.getRightChild() != null){
				parentOfRightMost = rightMost;
				rightMost = rightMost.getRightChild();
			}

			current.setElement(rightMost.getElement());

			if(parentOfRightMost.getRightChild() == rightMost){
				parentOfRightMost.setRightChild(rightMost.getLeftChild());
			}
			else{
				parentOfRightMost.setLeftChild(rightMost.getLeftChild());
			}
		}

		size--;
		return true;
	}

	public java.util.Iterator iterator(){
		return inorderIterator();
	}

	public java.util.Iterator inorderIterator(){
		return new InorderIterator();
	}

	class InorderIterator implements java.util.Iterator{
		private java.util.ArrayList<E> list = new java.util.ArrayList<E>();
		private int current = 0;

		public InorderIterator(){
			inorder();
		}

		private void inorder(){
			inorder(root);
		}

		private void inorder(TreeNode<E> root){
			if(root == null) return;
			inorder(root.getLeftChild());
			list.add(root.getElement());
			inorder(root.getRightChild());
		}

		public boolean hasNext(){
			if(current < list.size())
				return true;

			return false;
		}

		public Object next(){
			return list.get(current++);
		}

		public void remove(){
			list.clear();
			inorder();
		}
	}

	public void clear(){
		root = null;
		size = 0;
	}
}