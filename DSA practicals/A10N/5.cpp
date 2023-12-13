#include <iostream>
using namespace std;

// void MinHeap(int arr[],int n) {
// 	for(int i =0;i<=n;i++) {
// 		int parent = i/2;
		
// 		while(arr[parent] >arr[i] && parent>0) {
// 			int temp= arr[parent];
// 			arr[parent] = arr[i];
// 			arr[i] = temp;
// 			i = parent;
// 			parent/=2;
// 		}
// 	}
// }

// void MaxHeap(int arr[],int n) {
// 	for(int i =0;i<=n;i++) {
// 		int parent = i/2;
		
// 		while(arr[parent] <arr[i] && parent>0) {
// 			int temp= arr[parent];
// 			arr[parent] = arr[i];
// 			arr[i] = temp;
// 			i = parent;
// 			parent/=2;
// 		}
// 	}
// }

void heapify(int arr[], int i, int n) {
	int left = 2*i;
	int right = 2*i+1;
	int largest = i;
	if(left<=n && arr[largest] < arr[left]) {
		largest = left;
	}
	if(right<=n && arr[largest] < arr[right]) {
		largest = right;
	}
	if(largest!=i) {
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] =temp;
		heapify(arr,largest,n);
	}
			
}

void heapsort(int arr[],int n) {
	while(n!=1) {
		for(int i = n/2;i>0;i--) {
			heapify(arr,i,n);
		}
		int temp = arr[1];
		arr[1] = arr[n];
		arr[n] = temp;
		n--;
	}
}

int main() {
	int n;
	cout<<"No. of students: ";
	cin>>n;
	int a[n+1], sortedheap[n+1];
	cout<<"Enter marks: ";
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sortedheap[i] = a[i];
	}

	heapsort(sortedheap,n);

	cout<<"The sorted marks array is:\n";
	for(int i=1; i<=n; i++) {
		cout<<sortedheap[i]<<" ";
	}

	cout<<"The max mark is "<<arr[n]<<endl;
	cout<<"The min mark is "<<arr[1];
	return 0;
}