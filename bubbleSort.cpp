#include<iostream>
using namespace std;
int arr[100];
int n;

void bubbleSort(){
	for (int i = 0; i < n; i++){
		bool isChange = false;
		for (int j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1]){
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				isChange = true;
			}
		}
		if (!isChange) break;
	}
}
int main(){
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
  
	bubbleSort();
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
}
