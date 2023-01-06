#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool checkforbalanced(char c[],int n){
	stack<char> S;
	for(int i=0;i<n;i++){
		if(c[i]=='['||c[i]=='{'||c[i]=='(') S.push(c[i]);
		else if(c[i]==']'||c[i]=='}'||c[i]==')'){
			char temp;
			if(c[i]==']') temp = '[';
			else if(c[i]=='}') temp = '{';
			else temp = '(';
			if(S.empty()||S.top()!=temp){
				return false;	
			} 
			else S.pop();
		}
	}
	if(S.empty()) return true;
	else return false;
}

int main(void){
	char c[51];
	while(1){
		cout<<"Enter the expression: "<<endl;
		cin>>c;
		if(c=="exit") exit(1);
		int n = strlen(c);
		if(checkforbalanced(c,n)) cout<<"Balanced"<<endl;
		else cout<<"Not Balanced"<<endl;
	}
	
}
