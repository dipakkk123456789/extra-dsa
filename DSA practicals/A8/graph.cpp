#include <iostream>
using namespace std;

int main() {
	int n,w; char ch;
	cout<<"No. of nodes: ";
	cin>>n;
	string nodes[n];
	int adj_mat[n][n];
	cout<<"Enter nodes: ";
	for(int i=0;i<n;i++) {
		cin>>nodes[i];
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<"whether there is edge between "<<nodes[i]<<" and "<<nodes[j]<<" ?\n(y/n): ";
			cin>>ch;
			if(ch=='y') {
				cout<<"Enter weight: ";
				cin>>w;
				adj_mat[i][j]=w;
			} else {
				adj_mat[i][j]=0;
			}
		}
	}
	
	cout<<"\n\nThe adjacent matrix is\n\t";
	
	for(int i=0;i<n;i++) cout<<nodes[i]<<"\t";
	
	cout<<endl;
	for(int i=0;i<n;i++) {
		cout<<nodes[i]<<"\t";
		for(int j=0;j<n;j++) {
			cout<<adj_mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"\n\nThe adjacency list is\n";
	for(int i=0;i<n;i++) {
		cout<<nodes[i];
		for(int j=0;j<n;j++) {
			if(adj_mat[i][j]!=0) {
				cout<<" --> "<<nodes[j];
			}
		}
		cout<<endl;
	}
}
