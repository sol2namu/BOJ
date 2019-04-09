#include<iostream>
using namespace std;
int arr[100];

int heap_size = 0;
int heap[10000];

void push(int data) {
	int target = heap_size + 1;
	while (target != 1 && heap[target / 2] > data) {
		heap[target] = heap[target / 2];
		target /= 2;
	}
	heap[target] = data;
	++heap_size;
}
void pop() {
	int parent = 1, child = 2;
	int temp = heap[heap_size];
	while (child < heap_size) {

		if (child + 1 < heap_size && heap[child] > heap[child + 1]) {
			++child;
		}
		if (temp <= heap[child]) {
			break;
		}
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	--heap_size;
}

void heapSort(int n){

	for (int i = 0; i < n; i++){
		push(arr[i]);
	}

	for (int i = 0; i < n; i++){
		arr[i] = heap[1];
		pop();
	}
}

int main(){
	cin >> n;
	int map[100];
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
  
	heapSort(n);
	for (int i = 0; i < n; i++)cout << arr[i] << " ";

}
