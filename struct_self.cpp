#include<stdio.h>
#include<stdlib.h>

struct var {
int i;
int j;
struct var *ptr;
};

int main(){
struct var var1,var2;
var1 = {1,2,NULL};
var2 = {4,7,NULL};
var1.ptr = &var2;
printf("%d %d",var1.ptr->i,var1.ptr->j);
return 0;
}