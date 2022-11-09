#include<stdio.h>
#include<conio.h>
void main(){

int price,gst=0,tot=0;
char s[30];
clrscr();

printf("\n               --WELCOME TO CAFE WORLD--         \n");
printf("\n=================================================== \n");
printf("\n Enter The Item Name :- ");
//scanf("\n %s",&s);
gets(s);
printf("\n Enter The amount for item :- ");
scanf("\n %d",&price);
gst=((price/100)*18);
tot=price+gst;
printf("\n                   CAFE WORLD         \n");
printf("\n Item             Amount           GST            total Amount");
printf("\n %s"   "           %d  " "          %d  " "            %d ",s,price,gst,tot);
printf("\n\n\n\n  !! Thank you for visit  Do You Agin Welcome Sir");

getch();


}