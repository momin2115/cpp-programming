#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > findSubs(vector<int> arr){
	vector< vector<int> > result;
	int n = arr.size();
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		temp.push_back(arr[i]);
		result.push_back(temp);
		for(int j=i+1;j<n;j++){
			temp.push_back(arr[j]);
			result.push_back(temp);
		}
	}
	return result;
}

int main(void)
{
//	int n =0;
//	int data = 0;
//	vector<int> arr;
//	cout<<"Enter No. of elements "<<endl;
//	cin>>n;
//	cout<<"Enter the data: "<<endl;
//	for(int i=0;i<n;i++)
//	{
//		cin>>data;
//		arr[i]=data;
//	}
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	vector< vector<int> > result = findSubs(arr);
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			cout<<result[i][j]<< " ";
		}
		cout<<endl;
	}
}
