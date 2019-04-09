#include<iostream>
using namespace std;
int arr[100];
int n;

void SelectSort(){
	for (int i = 0; i < n - 1; i++){
		int idx = i;
		for (int j = i + 1; j < n; j++){
			if (arr[j] < arr[idx]){
				idx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	SelectSort();
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
}
