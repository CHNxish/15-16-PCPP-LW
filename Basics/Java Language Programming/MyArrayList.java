public class MyArrayList{
	private Object[] objectArray;
	private int capacity;
	private int size;
	public static int DEFAULT_CAPACITY = 2;

	public MyArrayList(){
		objectArray = new Object[DEFAULT_CAPACITY];
		capacity = DEFAULT_CAPACITY;
		size = 0;
	}

	public MyArrayList(int capacity){
		objectArray = new Object[capacity];
		this.capacity = capacity;
		size = 0;
	}

	public void clear(){
		size = 0;
	}

	public void add(Object o){
		add(size, o);
	}

	public void add(int index, Object o){
		if(size == capacity){
			Object[] temp = new Object[capacity * 2];
			for(int i = 0; i < size; i++){
				temp[i] = objectArray[i];
			}
			objectArray = temp;
			capacity *= 2;
		}

		if(index < 0){
			System.out.println("Add fuction index parameter error!");
			System.exit(0);
		}
		else if(index >= size){
			objectArray[size] = o;
		}
		else{
			for(int i = size; i > index; i++){
				objectArray[i] = objectArray[i - 1];
			}
			objectArray[index] = o;
		}

		size++;
	}

	public Object set(int index, Object o){
		if(index < 0 || index >= size){
			System.out.println("Set fuction index parameter error!");
			System.exit(0);
		}

		Object temp = objectArray[index];
		objectArray[index] = o;
		return temp;
	}

	public Object get(int index){
		if(index < 0 || index >= size){
			System.out.println("Get fuction index parameter error!");
			System.exit(0);
		}

		return objectArray[index];
	}

	public int remove(Object o){
		boolean b = false;
		int i;
		for(i = 0; i < size; i++){
			if(objectArray[i].equals(o)){
				b = remove(i);
				break;
			}
		}
		return b ? i : -(i + 1);
	}

	public boolean remove(int index){
		if(index < 0 || index >= size){
			System.out.println("Remove fuction index parameter error!");
			return false;
		}

		for(int i = index; i < size - 1; i++){
			objectArray[i] = objectArray[i + 1];
		}
		size--;

		return true;
	}

	public boolean isEmpty(){
		return size == 0;
	}

	public int size(){
		return size;
	}

	public boolean contains(Object o){
		for(int i = 0; i < size; i++){
			if(objectArray[i].equals(o)){
				return true;
			}
		}
		return false;
	}

	public int indexOf(Object o){
		int i;
		for(i = 0; i < size; i++){
			if(objectArray[i].equals(o)){
				break;
			}
		}
		
		if(i != size){
			return i;
		}
		else{
			return -(i + 1);
		}
	}

	public int lastIndexOf(Object o){
		int result = -1;
		for(int i = 0; i < size; i++){
			if(objectArray[i].equals(o)){
				result = i;
			}
		}

		return result;
	}

	public String toString(){
		String str = "";

		str += "[";
		for(int i = 0; i < size - 1; i++){
			str += objectArray[i] + ", ";
		}
		str += objectArray[size - 1] + "]";

		return str;
	}
}