#include<iostream>
using namespace std;
int arr[100];
int n;

void insertSort(){
	for (int i = 1; i < n; i++){
		int j = 0;
		int k = arr[i];
		for (j = i - 1; j >= 0; j--){
			if (arr[j] <= k){
				break;
			}
			else{
				arr[j + 1] = arr[j];
			}
		}
		arr[j + 1] = k;

	}
}

int main(){
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
  
	insertSort();
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
}
