package class_25;

import java.util.ArrayList;

public class MinPriorityQueue {
	ArrayList<Integer> heap;
	
	public MinPriorityQueue() {
		heap = new ArrayList<>();
	}
	
	boolean isEmpty() {
		return heap.size() == 0;
	}
	
	int size() {
		return heap.size();
	}
	
	int getMin() {
		if(isEmpty()) {
			//throw exception
			return Integer.MAX_VALUE;
		}
		return heap.get(0);
	}
	
	void insert(int el) {
		heap.add(el);
		
		int childIndex = heap.size() - 1;
		int parentIndex = (childIndex - 1) / 2;
		
		while(childIndex > 0 && heap.get(childIndex) < heap.get(parentIndex)) {
			int temp = heap.get(childIndex);
			heap.set(childIndex, heap.get(parentIndex));
			heap.set(parentIndex, temp);
			childIndex = parentIndex;
			parentIndex = (childIndex - 1) / 2;
		}
	}
	
	int remove() {
		if(isEmpty()) {
			//throw exception
			return Integer.MAX_VALUE;
		}
		int temp = heap.get(0);
		heap.set(0, heap.get(heap.size() - 1));
		heap.remove(heap.size() - 1);
		
		int index = 0;
		int leftChildIndex = 2 * index + 1;
		int rightChildIndex = 2 * index + 2;
		
		int minIndex = index;
		
		while(leftChildIndex < size()) {
			if(heap.get(leftChildIndex) < heap.get(minIndex)) {
				minIndex = leftChildIndex;
			}
			
			if(rightChildIndex < size() && heap.get(rightChildIndex) < heap.get(minIndex)) {
				minIndex = rightChildIndex;
			}
			
			if (minIndex != index) {
				int temp2 = heap.get(minIndex);
				heap.set(minIndex, heap.get(index));
				heap.set(index, temp2);
				index = minIndex;
				leftChildIndex = 2 * index + 1;
				rightChildIndex = 2 * index + 2;
			} else {
				break;
			}
		}
		return temp;
	}
}
