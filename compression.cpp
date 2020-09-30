#include<iostream>
using namespace std;
int main(){
	int n,m;
	cout<<"Enter the no. of rows and columns in the matrix "<<endl;
	cin>>m>>n;
	int a[m][n],r[m*n],c[m*n],v[m*n],k=0;
	cout<<"Enter the elements of the sparse matrix "<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	cout<<"Our given sparse matrix is "<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=0){
				r[k]=i;
				c[k]=j;
				v[k]=a[i][j];
				k++;
			}
		}
	}
	cout<<"Row of the triplet is "<<" ";
	for(int i=0;i<k;i++){
		cout<<r[i]<<" ";
	}
	cout<<endl;
	cout<<"Column of the triplet is "<<" ";
	for(int i=0;i<k;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	cout<<"Value of the triplet is "<<" ";
	for(int i=0;i<k;i++){
		cout<<v[i]<<" ";
	}
	
	return 0;
}