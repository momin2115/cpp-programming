#include <iostream>
using namespace std;


int main(void){
	int arr[12];
	int low,mid = 0;
	int high = 11;
	cout<<"Enter th array of 0's 1's and 2's";
	for(int i=0;i<12;i++){
		cin>>arr[i];
	}
	while(mid!=high+1){
		if(arr[mid]==0){
			int temp = arr[low];
			arr[low] = arr[mid];
			arr[mid] = temp;
			low++;
			mid++;
		}
		else if(arr[mid]==1){
			mid++;
		}
		else{
			int temp = arr[high];
			arr[high] = arr[mid];
			arr[mid] = temp;
			high--;
		}
	}
	for(int i=0;i<12;i++){
		cout<<arr[i]<" ";
	}
}
