#include<iostream>
using namespace std;
int main(){
	int m1,n1,m2,n2;
	cout<<"Enter the size of the first sparse matrix "<<endl;
	cin>>m1>>n1;
	cout<<"Enter the size of the second sparse matrix ";
	cin>>m2>>n2;
	 if(m1==m2 && n1==n2) {
	int k1,k2;
	cout<<"Enter the size of given sparse matrices "<<endl;
	cin>>k1>>k2;
	int r1[k1],c1[k1],v1[k1],r2[k2],c2[k2],v2[k2],k=0,r3[k1+k2],c3[k1+k2],v3[k1+k2],a[m1][n1];
	cout<<"Enter the elements of the row matrix 1 "<<endl;
	for(int i=0;i<k1;i++){
		cin>>r1[i];
	}
	cout<<"Enter the elements of the column matrix 1 "<<endl;
	for(int i=0;i<k1;i++){
		cin>>c1[i];
	}
	
	cout<<"Enter the elements of the value of matrix 1 "<<endl;
	for(int i=0;i<k1;i++){
		cin>>v1[i];
	}
	
	cout<<"Enter the elements of the row matrix 2 "<<endl;
	for(int i=0;i<k2;i++){
		cin>>r2[i];
	}
	cout<<"Enter the elements of the column matrix 2 "<<endl;
	for(int i=0;i<k2;i++){
		cin>>c2[i];
	}
	
	cout<<"Enter the elements of the value matrix 2 "<<endl;
	for(int i=0;i<k2;i++){
		cin>>v2[i];
	}
	for(int i=0;i<k1;i++){
		for(int j=0;j<k2;j++){
		if(r1[i]==r2[j] && c1[i]==c2[j]){
			v3[k]=v1[i]+v2[j];
			r3[k]=r1[i];
			c3[k]=c1[i];
			k++;
			v1[i]=0;
			v2[j]=0;
		}
	}
}
for(int i=0;i<k1;i++){
	if(v1[i]!=0){
		v3[k]=v1[i];
		r3[k]=r1[i];
		c3[k]=c1[i];
		k++;
	}
}
for(int i=0;i<k2;i++){
	if(v2[i]!=0){
		v3[k]=v2[i];
		r3[k]=r2[i];
		c3[k]=c2[i];
		k++;
	}
}
cout<<"Resultant of Addition of the given matrices is "<<endl;
for(int i=0;i<k;i++){
	cout<<r3[i]<<" ";
}
cout<<endl;
	
for(int i=0;i<k;i++){
	cout<<c3[i]<<" ";
}
	cout<<endl;
for(int i=0;i<k;i++){
	cout<<v3[i]<<" ";
}
cout<<endl;	
for(int i=0;i<m1;i++){
		for(int j=0;j<n1;j++){
			a[i][j]=0;
		}
	}
	for(int i=0;i<k;i++){
		a[r3[i]][c3[i]]=v3[i];
	}
	cout<<"sparse matrix from triplet is "<<endl;
	for(int i=0;i<m1;i++){
		for(int j=0;j<n1;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
else {
	cout<<"Addition not possible";
}
return 0;
}