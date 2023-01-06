#include <iostream>
using namespace std;

int main(void){
	int arr[5];
	cout<<"Enter elements for the array: "<<endl;
	for(int i=0;i<5;i++){
		cin>>arr[i];
	}
	int hash[5] = {0,0,0,0,0};
	for(int i=0;i<5;i++){
		hash[arr[i]]=hash[arr[i]]+1;
		if(hash[arr[i]]>1){
			cout<<"Duplicate number is "<<endl;
			cout<<arr[i]<<endl;
		}
	}
}
