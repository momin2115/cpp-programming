#include <stdio.h>
#include <stdlib.h>

int main(){
int i,n;
printf("Enter the number of integers: ");
scanf("%d",&n);
float *ptr = (float*)malloc(n*sizeof(float));

if(ptr == NULL){
printf("Memory not available");
exit(1);
}

for(i=0;i<n;i++){
printf("Enter an Float: ");
scanf("%f", ptr + i);
}

for(i=0;i<n;i++)
printf("%d \n", (ptr+i));

for(i=0;i<n;i++)
printf("%f \n", *(ptr+i));

return 0;

}