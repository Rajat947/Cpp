#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter the size of the array"<<endl;
	cin>>size;
	int a[size],max=0,s=0,c=0,b=0,lower=0,upper=0;
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
	for(int i=0;i<size;i++){
		s=a[i];
		if(a[i]+1==a[i+1] || a[i]==a[i+1]+1){
			c=i;
			b=i+1;
			while(a[b]+1==a[b+1] || a[b]==a[b+1]+1){
				if(a[b]+1==a[b+1] || a[b]==a[b+1]+1){
					b+=1;

				}
			}
		}
			if(max<(b-c)){
				max=(b-c);
				lower=c;
				upper=b;		
			}
	}
	cout<<upper<<endl;
	cout<<lower<<endl;
	cout<<"Largest consecutive elements are  "<<max+1<<endl;
	for(int i=lower;i<=upper;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}