#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#define PASSWORD 0
#define NUMBER 1
#define LETTER 2
#define ALLINPUT 3
#define _pwd "PWD.BIN"
#define _room "ROOM.BIN"
#define _doct "DOCTOR.BIN"
#define _pati "PATIENT.BIN"
#define _type "TYPE.BIN"
#define EMPTY 'n'
#define STAY 'y'
FILE *f_ro;
FILE *f_doc;
FILE *f_pat;
FILE *f_ty;
FILE *f_pwd;

struct Login{
 char pwd[15];
 char usr[15];
};
struct Types{
 int co;
 char na[10];
 float pri;
};

struct Room{
 int no;
 struct Types type;
 char sta;
};
time_t current;
struct tm *gt;

struct DateTime {
 int day;
 int mon;
 int year;
 int hour;
 int min;
 int sec;
};

struct Doctor{
 char id[10];
 char fname[15];
 char lname[15];
 char sex;
 char blo[5];
 struct date birth;
 char nat[20];
 char spec[20];
 struct DateTime join;
 char tel[20];
 char email[35];
 char addr[40];
};
struct Patient{
 char id[10];
 char fname[15];
 char lname[15];
 char sex;
 char blo[5];
 struct date birth;
 char prob[35];
 char nat[20];
 char tel[20];
 char addr[40];
 struct DateTime regi;
 int ro;
};
/*Function Declaration*/
void help();
int login(int);
int resetpwd(int);
int changepwd();
void box(int,int,int,int,int);
void updatedoc(int);
void sortroom(Room *ro,int n);
int blockey();
void sortpat(Patient *pat,int n);
void sortpatname(Patient *pat,int n);
void sortdoc(Doctor *doc,int n);
void sorttype(Types *type,int n);
int getFileElement(const char *name, int size);
int checkf_pwd();
void drawbox(int left, int top, int right, int bottom);
void notice(char text[30],int x1,int y1,int x2,int y2);
void notice(char text[2][30],int x1,int y1,int x2,int y2);
void drawwindow(char head[30],int x1, int y1, int x2, int y2, int c);
int confirm(char str[15]);
void updatepat(int);
void welc();
void inputdat(int &day,int &mon,int &year,int c);
void createfile();
void addtype();
void checkoutinput(int opt);
int checkout(int id);
int selecttype();
char selectsex();
int selectblood();
int findroom(int no);
int finddocid(char id[10]);
int findpatid(char id[10]);
void addroom();
int addpatient(int);
void setroomEMPTY(int);
void setroomSTAY(int);
void patidetail(char id[10]);
void docdetail(char id[10]);
void adddoc();
void deletetype(int);
void deletetypeinput();
void deleteroom();
void deletepat(char id[10]);
int deletedoc(char id[10]);
void deletedocinput(int opt);
int viewpat(char head[30],Patient *source,int n,int opt);
int viewdoc(char head[30],Doctor *source,int n,int opt);
void findpat(int opt);
void finddoc(int opt);
void updateroom();
int viewroom(char head[30],Room *source,int n);
void allroom();
void allpat();
void alldoc();
void findviewroom();
void availroom();
void alltype();
int menu(int);
int doctor();
int patient();
int dropmenu(char menu[7][20],int x1,int y1,int x2,int y2,int opt);
void box(int x1,int y1,int x2,int y2,int c);
void clrwin();
int program();
int about();
int room();
char *input(int,int,int);
float inputf(int,int);
/*end Function Declaration*/
void main(){
 createfile();
 _setcursortype(0);
 int opt=0;
 if(login(3)==1)
   goto start;
 exit(0);
start:
 welc();
 textbackground(14);
 clrscr();
 gotoxy(22,1);textcolor(9);cprintf("==== Hospital Management System ====");
 do{
  switch(menu(opt)){
   case 0:opt=program();break;
   case 1:opt=doctor();break;
   case 2:opt=patient();break;
   case 3:opt=room();break;
   case 4:opt=about();break;
  }

 }while(1);
}

int resetpwd(int opt){
 struct Login log;
 int s,sh=0,h=0;
 char usr[20],pwd[20],ch;
 char code[8];
 char head[2][30]={"SET USER","RESET USER"};
 int t=0;
 do{
  h=checkf_pwd();
  if(opt==1){
   clrwin();
  }else{
   textbackground(9);
   window(1,1,80,25);
   clrscr();
   gotoxy(22,4);textcolor(9);cprintf("==== Hospital Management System ====");
   box(2,2,79,24,15);

  }
  drawwindow(head[h],20,7,60,19,12);
  textcolor(15);
  gotoxy(1,4); cprintf("Enter Code of program:");
  gotoxy(1,6); cprintf("Enter New Username:");
  gotoxy(1,8); cprintf("Enter New Password:");
