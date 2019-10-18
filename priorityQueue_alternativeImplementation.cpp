//CMPE250 - Fall 2019
//PS4

#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 100000;

class Heap{

public:
	int size;
	int data[MAX_N];

	void push(int element){
		
		data[size]=element;
		heap_up(size);
		size++;
	}

	int pop(){

		int return_value = data[0];
		data[0]=data[size-1];
		size--;
		heap_down(0);
		return return_value;
	}

	void swap(int index1, int index2){

		int tmp = data[index1];
		data[index1] = data[index2];
		data[index2]= tmp;
	}

	void heap_up(int index){
		
		if(index==0)
			return;
		
		int parent = (index+1)/2-1;
		
		if(data[index] > data[parent]){
			
			swap(index, parent);
			heap_up(parent);
		}
	}

	void heap_down(int index){
		int left = index*2+1;
		int right = index*2+2;
		if(left >= size) 
			return;
		if(left == size-1){
			if(data[left] > data[index])
				swap(left, index);

			return;
		}
		if(data[left] > data[right] && data[left] > data[index]){
			swap(left, index);
			heap_down(left);
		}
		else if(data[right] >= data[left] && data[right] > data[index]){
			swap(right, index);
			heap_down(right);
		}
	}
};

int main(){

	int element;
	string query;

	Heap *heap = new Heap();
	heap->size = 0;

	while( true ) {
		
		cin >> query;
		
		if(query=="push"){
			cin >> element;
			heap->push(element);
		}
		else if(query=="pop"){

			if(heap->size==0){
				cout << "can't pop. no element in heap." << endl;
				continue;
			}
			cout << heap->pop() << endl;
		}
	}

	return 0;
}