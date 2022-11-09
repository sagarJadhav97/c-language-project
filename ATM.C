#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
long amount=1000,deposit,withdraw;
int choice,pin,k;
char transaction='y';

int main(){

while(pin != 1111)
 {
    printf("Enter Your Secret Pin Number :- ");
    scanf("%d",&pin);
    if(pin != 1111)
    printf("please Enter valid Password \n");
    system ("cls");
 }
   do {
  printf("                         *********** welcome To ATM Service ************                        \n");
  printf("1. check Balance \n");
  printf("2. withdraw Cash\n");
  printf("3. deposite Cash\n");
  printf("4.Quit \n");
  printf("***********************************************\n\n");
  printf("Enter your choice");
  scanf("%d",&choice);
  system ("cls");
  switch(choice)
  {
    case 1:
	   printf("\n Your Balance In Rs : %lu",amount);
    break;
    case 2:
	   printf("\n Enter The Amount to Withdraw : ");
	   scanf("%lu", &withdraw);
    if(withdraw > (amount - 5000))
    {
    printf("\n INSUFFICNET BALANCE");
    }
    else{
    amount = amount - withdraw;
    printf("\n \n Please Collect Cash");
    printf("\n Your Current Balance is %lu",amount);
    }
    break;

    case 3:
	   printf("\n Enter The Amount to Deposite");
	   scanf("%lu",&deposit);
    amount = amount + deposit;
    printf("Your Balance is %lu",amount);
    break;

    case 4:
	   printf("\n thank u using ATM");
    break;
    default:
      printf("\n invalid choice");
  }
   printf("\n \n \n Do u Wish to Have Another transaction?(y/n):\n");
   fflush(stdin);
   scanf("%c",&transaction);
   if(transaction == 'n' || transaction =='N')
   k=1;
   system ("cls");
   }
   while(!k);
   system ("cls");
   printf("\n\n Thanks for using out ATM Service");
getch();
}
