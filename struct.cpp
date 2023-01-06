#include <stdio.h>

struct student {
char name[50];
int age;
int roll_no;
float marks;
};

void print(char name[],int age,int roll, float marks){
printf("%s %d %d %.3f", name, age, roll, marks);
}

int main(){
struct student s1 = {"Ali",21,40,90.83};
print(s1.name,s1.age,s1.roll_no,s1.marks);
}