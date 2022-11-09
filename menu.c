#include<stdio.h>
#include<bios.h>
#include<conio.h>
#include<ctype.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
enum TYPE {
    PASSWORD,
    INT,
    FLOAT,
    TEXT,
    ALL,
};
union REGS i,o;

int buttonm,xm,ym,gd=9,gm=1,close=1,set=1,midx,midy;

//declearation function
void getmousepos(int *buttonm,int *xm, int *ym);
void restrictmouse(int x1,int y1,int x2,int y2);
void showmouse();
int initmouse();
void setmousepos(int &xpos,int &ypos);
void hidemouse();
int menu(int);
int doctor();
void adddoc();
void deletedoc();
void searchdoc();
int patient();
void updatepat();
void searchpat();
void welgr();
void userl();
void notice();
void setusrl();
void changeusrl();
void removeusrl();
int dropmenu(char menu[7][20],int x1,int y1,int x2,int y2,int opt);
void button(char name[15],int x1,int y1,int x2,int y2,int c);
void clrwin(int opt);
void drawwindow(char head[30],int x1, int y1, int x2, int y2, int c);
int program();
void managetype();
int about();
int rooms();
void manageroom();
void input(int x,int y,char result[50],int limit ,int tc,int bkc,int type);
void inputbox(int x,int y,int limit,int bkc);
//end declearation
void main(){
 _setcursortype(0);
 initgraph(&gd,&gm,"..\\BGI");
 int menu1=-1;
 midx=getmaxx()/2;
 midy=getmaxy()/2;
 clrscr();
 welgr();
 setfillstyle(1,BLUE);
 bar(0,0,getmaxx(),getmaxy());
 setcolor(3);
 settextstyle(2,0,5);
 settextjustify(CENTER_TEXT, TOP_TEXT);
 outtextxy(midx,0,"==== Hospital Management System ====");
 settextjustify(LEFT_TEXT, TOP_TEXT);
 settextstyle(0,0,0);
 clrwin(2);
 restrictmouse(10,18,getmaxx()-10,getmaxy()-10);
 setmousepos(midx,midy);
 showmouse();
 getmousepos(&buttonm,&xm,&ym);
 menu(menu1);
 while(1){
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1){
   if(xm>=10&&xm<=34&&ym>=18&&ym<=32){
    menu1=0;
   }else if(xm>=35&&xm<=94&&ym>=18&&ym<=32){
     menu1=1;
   }else if(xm>=95&&xm<=169&&ym>=18&&ym<=32){
     menu1=2;
   }else if(xm>=170&&xm<=219&&ym>=18&&ym<=32){
     menu1=3;
   }else if(xm>=220&&xm<=269&&ym>=18&&ym<=32){
     menu1=4;
   }else menu1=-1;
   clrwin(1);
   menu(menu1);
   switch(menu1){
    case 0:program();break;
    case 1:doctor();break;
    case 2:patient();break;
    case 3:rooms();break;
    case 4:about();break;
   }
  }
 }
}
//mouse function
int initmouse(){
 i.x.ax=0;//for  initialising mouse.
 int86(0x33,&i,&o);
 return (o.x.ax);
}

void showmouse(){
 i.x.ax=1; // for displaying mouse pointer.
 int86(0x33,&i,&o);
}
void hidemouse(){
 i.x.ax=2;
 int86(0x33,&i,&o);
}

void setmousepos(int &xpos,int &ypos){
 i.x.ax=4;
 i.x.cx=xpos;
 i.x.dx=ypos;
 int86(0x33,&i,&o);
}

void restrictmouse(int x1,int y1,int x2,int y2){
 i.x.ax=7;     //to define the upper left boundry of mouse.
 i.x.cx=x1;
 i.x.dx=x2;
 int86(0x33,&i,&o);
 i.x.ax=8;   //to define the bottom right boundry of mouse.
 i.x.cx=y1;
 i.x.dx=y2;
 int86(0x33,&i,&o);
}
void getmousepos(int *buttonm,int *x, int *y){
 i.x.ax=3; //to move mouse.
 int86(0x33,&i,&o);
 *buttonm=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}
//end mouse function

int program(){
 int opt=-1,j;
 char menu[2][20]={"User Login >","Quit"};
 close=1;
 dropmenu(menu,10,33,131,76,opt);
 do{
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=10+10&&xm<=131-10&&ym>=33+8&&ym<=76-8&&buttonm==1){
   for(j=0;j<(76-33-8)/14;j++)
    if((ym-33-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,10,33,131,76,opt);
   switch(opt){
    case 0: userl();break;
    case 1: delay(100);cleardevice();closegraph();exit(0);
   }
  }else if(xm>=10&&xm<=34&&ym>=18&&ym<=32&&buttonm==1){
   dropmenu(menu,10,33,131,76,opt);
   continue;
  }else if(buttonm==1){
   break;
  }
 }while(close);
 return 0;
}
void userl(){
 int opt=-1,j;
 char menu[3][20]={"Set/Reset","Change","Remove"};
 dropmenu(menu,132,41,229,98,opt);
 do{
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=132+10&&xm<=229-10&&ym>=41+8&&ym<=98-8&&buttonm==1){
   for(j=0;j<(98-41-8)/14;j++)
    if((ym-41-8)/14==j){
     opt=j;
     break;