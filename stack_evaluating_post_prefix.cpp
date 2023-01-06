#include <iostream>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

stack<int> S;

int evaluate(char oprtr,int op1,int op2){
	if(oprtr=='+') return (op1+op2);
	else if(oprtr=='-') return (op1-op2);
	else if(oprtr=='*') return (op1*op2);
	else return (op1/op2);
}

void evaluatePost(char c[],int n){
}

void evaluatePre(char c[],int n){
	for(int i=0;i<n;i++){
		if((c[i]=='+')||(c[i]=='-')||(c[i]=='*')||(c[i]=='\\')){
			int op2 = (S.top())-48; S.pop();
			int op1 = (S.top())-48;	S.pop();			
			int result = evaluate(c[i],op1,op2);
			S.push(result);
		}
		else{
			S.push(c[i]);
		}
	}
	cout<<"Result is: "<<S.top()<<endl;
}

int main(void){
	char c[51];
	cout<<"Enter the Expression: "<<endl;
	cin>>c;
	int n = strlen(c);
	evaluatePost(c,n);
	evaluatePre(c,n);
}
