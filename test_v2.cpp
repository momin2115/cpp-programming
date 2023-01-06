#include <stdio.h>
#include <stdlib.h>

int main(){
int i,n;

int *ptr = (int*)malloc(2*sizeof(int));
if(ptr == NULL){
printf("Memory not available");
exit(1);
}

for(i=0;i<2;i++){
printf("Enter an Integer: ");
scanf("%d", ptr + i);
}

*(ptr+2) = 25;

for(i=0;i<4;i++)
printf("%d \n", (ptr+i));

for(i=0;i<3;i++)
printf("%d \n", *(ptr+i));

ptr = (int*)realloc(ptr,4*sizeof(int));
if(ptr == NULL){
printf("Memory allocation failed");
exit(1);
}

for(i=2;i<4;i++){
printf("Enter an Integer: ");
scanf("%d", ptr + i);
}

for(i=0;i<4;i++)
printf("%d \n", (ptr+i));

for(i=0;i<4;i++)
printf("%d \n", *(ptr+i));

return 0;

}