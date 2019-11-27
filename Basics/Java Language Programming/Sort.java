public class Sort{
	// 冒泡排序
	public static void bubbleSort(int[] list){
		boolean needNextPass = true;

		for(int k = 1; k < list.length && needNextPass; k++){
			needNextPass = false;
			for(int i = 0; i < list.length - k; i++){
				if(list[i] > list[i + 1]){
					int temp = list[i];
					list[i] = list[i + 1];
					list[i + 1] = temp;
					needNextPass = true;
				}
			}
		}
	}

	// 归并排序
	public static void mergeSort(int[] list){
		if(list.length > 1){
			int[] firstHalf = new int[list.length / 2];
			System.arraycopy(list, 0, firstHalf, 0, list.length / 2);
			mergeSort(firstHalf);

			int secondHalfLength = list.length - list.length / 2;
			int[] secondHalf = new int[secondHalfLength];
			System.arraycopy(list, list.length / 2, secondHalf, 0, secondHalfLength);
			mergeSort(secondHalf);

			int[]temp = merge(firstHalf, secondHalf);
			System.arraycopy(temp, 0, list, 0, temp.length);
		}
	}

	private static int[] merge(int[] list1, int[] list2){
		int[] temp = new int[list1.length + list2.length];

		int current1 = 0;
		int current2 = 0;
		int current3 = 0;

		while(current1 < list1.length && current2 < list2.length){
			if(list1[current1] < list2[current2])
				temp[current3++] = list1[current1++];
			else
				temp[current3++] = list2[current2++];
		}

		while(current1 < list1.length)
			temp[current3++] = list1[current1++];

		while(current2 < list2.length)
			temp[current3++] = list2[current1++];

		return temp;
	}

	// 快速排序
	public static void quickSort(int[] list){
		quickSort(list, 0, list.length);
	}

	private static void quickSort(int[] list, int first, int last){
		if(last > first){
			int pivotIndex = partition(list, first, last);
			quickSort(list, first, pivotIndex - 1);
			quickSort(list, pivotIndex + 1, last);
		}
	}

	private static void partition(int[] list, int first, int last){
		int pivot = list[first];
		int low = first + 1;
		int high = last;

		while(high > low){
			while(low <= high && list[low] <= pivot)
				low++;

			while(low <= high && list[high] > pivot)
				high--;

			if(high > low){
				int temp = list[high];
				list[high] = list[low];
				list[low] = temp;
			}
		}

		while(high > first && list[high] >= pivot)
			high--;

		if(pivot > list[high]){
			list[first] = list[high];
			list[high] = pivot;
			return high;
		}
		else{
			return first;
		}
	}

	/**
	 * 堆排序
	 * Heap<E>
	 * -list: java.util.ArrayList<E>
	 * +Heap()
	 * +heap(objects: E[])
	 * +add(newObject: E): void
	 * +remove(): E
	 * getSize(): int
	 */
	public class Heap<E extends Comparable>{
		private java.util.ArrayList<E> list = new java.util.ArrayList<E>();

		public Heap(){
		}

		public Heap(E[] objects){
			for(int i = 0; i < objects.length; i++){
				add(object[i]);
			}
		}

		public void add(E newObject){
			list.add(newObject);
			int currentIndex = list.size() - 1;

			while(currentIndex > 0){
				int parentIndex = (currentIndex - 1) / 2;
				if(list.get(currentIndex).compareTo(list.get(parentIndex)) > 0){
					E temp = list.get(currentIndex);
					list.set(currentIndex, list.get(parentIndex));
					list.set(parentIndex, temp);
				}
				else
					break;

				currentIndex = parentIndex;
			}
		}

		public E remove(){
			if(list.size() == 0) return null;

			E removeObject = list.get(0);
			list.set(0, list.get(lsit.size() - 1));
			list.remove(list.size() - 1);

			int currentIndex = 0;
			while(currentIndex < list.size()){
				int leftChildIndex = 2 * currentIndex + 1;
				int rightChildIndex = 2 * currentIndex + 2;

				if(leftChildIndex >= list.size()) break;
				int maxIndex = listChildIndex;
				if(rightChildIndex < list.size()){
					if(list.get(maxIndex).compareTo(list.get(rightChildIndex)) < 0){
						maxIndex = rightChildIndex;
					}
				}

				if(list.get(currentIndex).compareTo(list.get(maxIndex)) < 0){
					E temp = list.get(maxIndex);
					list.set(maxIndex, list.get(currentIndex));
					list.set(currentIndex, temp);
					currentIndex = maxIndex;
				}
				else
					break;
			}
			return removeObject;
		}

		public int getSize(){
			return list.size();
		}
	}

	public static <E extends Comparble> void heapSort(E[] list){
		Heap<E> hep = new Heap<E>();

		for(int i = 0; i < list.length; i++)
			heap.add(list[i]);

		for(int i = list.length - 1; i >= 0; i--)
			list[i] = heap.remove();
	}

	
}