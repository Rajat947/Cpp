#include<iostream>
using namespace std;
int main(){
	int k,m,n;
	cout<<"Enter the size of the triplet "<<endl;
	cin>>k;
	cout<<"Enter the size of the sparse matrix "<<endl;
	cin>>m>>n;
	int r[k],c[k],v[k],a[m][n];
	cout<<"Enter the row value "<<endl;
	for(int i=0;i<k;i++){
		cin>>r[i];
	}
	cout<<"Enter the column value "<<endl;
	for(int i=0;i<k;i++){
		cin>>c[i];
	}
	cout<<"Enter the value "<<endl;
	for(int i=0;i<k;i++){
		cin>>v[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	for(int i=0;i<k;i++){
		a[r[i]][c[i]]=v[i];
	}
	cout<<"sparse matrix from triplet is "<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}