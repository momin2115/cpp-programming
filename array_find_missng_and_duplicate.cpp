 #include <iostream>
 using namespace std;
 
 int main(void){
 	int n,data;
 	cout<<"Enter the number of elements to be in array: "<<endl;
 	cin>>n;
 	int arr[n];
 	cout<<"Enter the elements in the array: "<<endl;
 	for(int i=0;i<n;i++){
 		cin>>data; 	
		arr[i]=data;	
	}
	int hash[n+1] = {0};
	for(int i=0;i<n;i++){
		hash[arr[i]]=hash[arr[i]]+1;
		if(hash[arr[i]]>1){
			cout<<"Duplicate Element is: "<<arr[i]<<endl;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<hash[i]<<" ";
		if(hash[i]==0) cout<<"Missing number is: "<<i<<endl;
	}
 }
