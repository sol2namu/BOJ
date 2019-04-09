#include<iostream>
using namespace std;
int arr[200];

int partition(int first, int last){
	int l = first;
	int p = first;
	int r = last;
	while (l < r){
		while (arr[p] >= arr[l] && l < last) l++;
		while (arr[p] < arr[r] && r > first) r--;
		if (l < r){
			int tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
		}
	}
	int tmp = arr[r];
	arr[r] = arr[p];
	arr[p] = tmp;
	return r;
}
void quickSort(int first, int last){
	if (first < last){
		int p = partition(first, last);
		quickSort(first, p - 1);
		quickSort(p + 1, last);
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
}
