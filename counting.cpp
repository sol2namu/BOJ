#include<iostream>
using namespace std;
int arr[100];
void countingSort(){
	const int k = 1000;
	int count[k + 1];
	for (int i = 0; i < k + 1; i++){
		count[i] = 0;
	}

	for (int i = 0; i < n; i++){
		count[arr[i]]++;
	}

	for (int i = 1; i < k + 1; i++){
		count[i] += count[i - 1];
	}

	int sort[k + 1], index = 0;

	for (int i = n - 1; i >= 0; i--){
		sort[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0; i < n; i++) arr[i] = sort[i];
}



int main(){
	cin >> n;
  
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	countingSort();
}
