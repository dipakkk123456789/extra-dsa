#include <iostream>
using namespace std;

void minheap(int arr[],int n) {
	for(int i =0;i<=n;i++) {
		int parent = i/2;
		
		while(arr[parent] >arr[i] && parent>0) {
			int temp= arr[parent];
			arr[parent] = arr[i];
			arr[i] = temp;
			i = parent;
			parent/=2;
		}
	}
}

void maxheap(int arr[],int n) {
	for(int i =0;i<=n;i++) {
		int parent = i/2;
		
		while(arr[parent] <arr[i] && parent>0) {
			int temp= arr[parent];
			arr[parent] = arr[i];
			arr[i] = temp;
			i = parent;
			parent/=2;
		}
	}
}

int main() {
	int n;
	cout<<"No. of students: ";
	cin>>n;
	int arr[n+1];
	cout<<"Enter marks: ";
	for(int i=1; i<=n; i++) {
		cin>>arr[i];
	}
	
	minheap(arr,n);
	cout<<"The Min mark is "<<arr[1]<<endl;
	maxheap(arr,n);
	cout<<"The Max mark is "<<arr[1]<<endl;
	return 0;
}