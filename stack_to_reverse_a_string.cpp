#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void reverse(char c[],int n){
	stack<char> S;
	for(int i=0;i<n;i++){
		S.push(c[i]);
	}
	for(int i=0;i<n;i++){
		c[i]=S.top();
		S.pop();
	}
}

void reversedirect(char c[],int j){
	int i = 0;
	while(i!=j){
		char ch = 'k';
		c[i]=ch;
		c[j]=ch;
		i++;
		j--;
	}
}

int main(void){
	char c[51];
	cout<<"Enter the string to be reversed without spaces: "<<endl;
	cin>>c;
	int n = strlen(c);
	reversedirect(c,n);
	cout<<"The reversed string is: "<<c[1]<<endl;
//	for(int i=0;i<n;i++) cout<<c[i]<<endl;
}
