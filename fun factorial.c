#include<stdio.h>
#include<conio.h>
void sum(int no);
 main(){
int num;
printf("enter a number ");
scanf("%d",&num);
sum(num);
}

void sum(int no){
int i;
int fact=1;
for(i=1;i<=no;i++){
    fact = fact*i;
}
printf("your factorial values %d",fact);
}
