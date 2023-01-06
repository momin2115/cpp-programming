#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int arr[] = {5,1,6,2,4,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j]>arr[j+1]) swap(arr[j+1],arr[j]);
		}
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
