#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numofsubs(vector<int> arr, int m)
{
	unordered_map<int,int>freq;
	int xr = 0;
	int count = 0;
	for(i=0;i<arr.size();i++)
	{
		xr = xr^arr[i];
		if(xr==m) count++;
		if(freq.count(xr^m)) count += freq[xr^m];
		
		freq[xr] += 1;
	}
	return count;
}

int main(void)
{
	vector<int> arr{4,2,2,6,4};
	int count = 0;
	count = numofsubs(arr,6);
	cout<<count<<endl;
}
