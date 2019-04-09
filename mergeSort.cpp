#include<iostream>
using namespace std;
int arr[10];
int tmp[10];

int n;

void merge(int f, int m, int l){
	int i = f;
	int j = m + 1;
	int k = f;

	while (i <= m && j <= l){
		if (arr[i] <= arr[j]){
			tmp[k] = arr[i];
			i++;
		}
		else{
			tmp[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i <= m){
		for (int b = i; b <= m; b++){
			tmp[k] = arr[b];
			k++;
		}
	}
	else{
		for (int b = j; b <= l; b++){
			tmp[k] = arr[b];
			k++;
		}
	}
	for (int b = f; b <= l; b++){
		cout << tmp[b] << " ";
		arr[b] = tmp[b];
	}
	cout << endl;
}
void mergeSort(int f, int l){
	if (f < l){
		int m = (f + l) / 2;
		mergeSort(f, m);
		mergeSort(m + 1, l);
		merge(f, m, l);
	}
}


int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	mergeSort(0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
