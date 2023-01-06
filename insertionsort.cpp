#include <bits/stdc++.h>
using namespace std;

//int main(void){
//	int temp = 0;
//	int j=0;
//	int arr[] = {5,1,6,2,4,3};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	for(int i=1;i<n;i++)
//	{
//		j = i-1;
//		temp = arr[i];
//		while(j>=0 && arr[j]>temp){
//			arr[j+1] = arr[j];   // to make space for temp
//			j--;
//		}
//		arr[j+1] = temp;
//	}
//	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
//}

int main(void){
	int temp=0;
	int j=0;
	int arr[] = {5,1,6,2,4,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=1;i<n;i++)
	{
		j=i-1;
		temp = arr[i];
		while(j>=0 and arr[j]>temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
