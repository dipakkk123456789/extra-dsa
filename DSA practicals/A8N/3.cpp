#include <iostream>
using namespace std;

int main() {
	int n,e;
	cout<<"No. of cities: ";
	cin>>n;
	string nodes[n];
	int adj_mat[n][n] = {};
	cout<<"Enter cities: ";
	for(int i=0;i<n;i++) {
		cin>>nodes[i];
	}
	
	cout<<"No. of edges: ";
	cin>>e;
	cout<<"Enter the edges with cost: ";
	for(int k=0;k<e;k++) {
	    int i = 0, j = 0, cost;
	    string city;
	    cin>>city;
	    while(nodes[i]!=city)
	        i++;
	    cin>>city;
	    while(nodes[j]!=city)
	        j++;
	    cin>>cost;
	    adj_mat[i][j] = cost;
	    adj_mat[j][i] = cost;
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
			if(adj_mat[i][j]>=1) {
				cout<<" --> "<<nodes[j];
			}
		}
		cout<<endl;
	}
}