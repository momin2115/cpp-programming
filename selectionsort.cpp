#include <bits/stdc++.h>
using namespace std;

int main(void){
	int min = 0;
	int minPos;
	int j=0;
	int arr[] = { 23, 78, 45, 8, 32, 56};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++)
	{
		minPos = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[minPos])
			{
				minPos = j;
			}
		}
		swap(arr[i],arr[minPos]);
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
