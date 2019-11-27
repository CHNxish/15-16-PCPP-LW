/** <Class> MyLinkedList<E> */
public class MyLinkedList<E> extends MyAbstractList<E>{
	private Node<E> head = null;
	private Node<E> tail = null;

	public MyLinkedList(){
	}

	public MyLinkedList(E[] objects){
		for(int i = 0; i < objects.length; i++){
			addLast(objects[i]);
		}
	}

	public void add(int index, E e){
		if(index < 0){
			throw new IllegalArgumentException("LinkedList index error!");
		}
		else if(index > size){
			index = size;
		}

		if(head == null){
			head = new Node<E>(e);
			tail = head;
		}
		else{
			Node<E> pos = head;
			for(int i = 0; i < index - 1; i++){
				pos = pos.getNext();
			}

			Node<E> temp = new Node<E>(e);
			temp.setNext(pos.getNext());
			pos.setNext(temp);

			while(tail.getNext() != null){
				tail = tail.getNext();
			}
		}

		size++;
	}

	public void clear(){
		head = tail = null;
		size = 0;
	}

	public boolean contains(E e){
		Node<E> pos = head;

		while(pos != null){
			if(pos.getElement().equals(e)){
				return true;
			}
			pos = pos.getNext();
		}

		return false;
	}

	public E get(int index){
		if(index >= 0 && index < size){
			Node<E> pos = head;
			for(int i = 0; i < index; i++){
				pos = head.getNext();
			}

			return pos.getElement();
		}
		else
			return null;
	}

	public int indexOf(E e){
		int index = 0;
		Node<E> pos = head;
		while(pos != null){
			if(pos.getElement().equals(e)){
				return index;
			}

			pos = pos.getNext();
			index++;
		}

		return -1;
	}

	public int lastIndexOf(E e){
		int result = -1, index = 0;
		Node<E> pos = head;
		while(pos != null){
			if(pos.getElement().equals(e)){
				result = index;
			}

			pos = pos.getNext();
			index++;
		}

		return result;
	}

	public E remove(int index){
		if(index < 0 || index >= size) return null;

		E e;
		Node<E> pos = head;
		if(index == 0){
			e = pos.getElement();
			head = head.getNext();
		}
		else{
			for(int i = 0; i < index - 1; i++){
				pos = pos.getNext();
			}

			Node<E> temp = pos.getNext();
			e = temp.getElement();
			pos.setNext(temp.getNext());
		}

		if(head == null){
			tail = null;
		}
		else{
			tail = head;
			while(tail.getNext() != null){
				tail = tail.getNext();
			}
		}

		size--;
		return e;
	}

	public Object set(int index, E e){
		if(index < 0 || index >= size) return null;

		Node<E> pos = head;
		for(int i = 0; i < index; i++){
			pos = pos.getNext();
		}

		E old = pos.getElement();
		pos.setElement(e);
		return old;
	}

	public void addFirst(E e){
		add(0, e);
	}

	public void addLast(E e){
		add(size, e);
	}

	public E getFirst(){
		return get(0);
	}

	public E getLast(){
		return get(size - 1);
	}

	public E removeFirst(){
		return remove(0);
	}

	public E removeLast(){
		return remove(size - 1);
	}

	public String toString(){
		StringBuilder result = new StringBuilder("[");

		int index = 0;
		Node<E> pos = head;
		while(pos != null){
			result.append(pos.getElement() + "");
			if(index++ < size - 1) result.append(", ");
			pos = pos.getNext();
		}
		result.append("]");

		return result.toString();
	}
}
