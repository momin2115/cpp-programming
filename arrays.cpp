#include <iostream>
using namespace std;


void change_val(int** ptr1){
	int val = 45;
	cout<<ptr1<<" address of pointer ptr"<<endl;
	cout<<*ptr1<<" value of pointer ptr"<<endl;
	*ptr1 = &val;
	cout<<*ptr1<<"address of new value assigned to pointer ptr"<<endl;
}


int main(void){
	int val = 35;
	int* ptr = &val;
	cout<<ptr<<endl<<*ptr<<endl;
	change_val(&ptr);
	cout<<ptr<<endl<<*ptr<<endl;
}

