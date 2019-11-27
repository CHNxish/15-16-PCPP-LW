/** <class> Node<E> */
public class Node<E>{
	E element;
	Node<E> next;

	public Node(E e){
		element = e;
		next = null;
	}

	public E getElement(){
		return element;
	}

	public void setElement(E e){
		element = e;
	}

	public Node<E> getNext(){
		return next;
	}

	public void setNext(Node<E> n){
		next = n;
	}
}