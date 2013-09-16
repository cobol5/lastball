

/* 
(c) copyright mayank bhola 2013 . all rights reserved

*/



#include<alloc.h>
#include<math.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
void init();
void shoot();
void *block1,*block2,*block3,*block4,*block5;
int level();
int rcount=0,lev=1;
void block()
{
//block1
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
bar(60,30,80,50);
block1=malloc(imagesize(60,30,80,50));
getimage(60,30,80,50,block1);
cleardevice();
//block2
setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
bar(60,30,80,50);
block2=malloc(imagesize(60,30,80,50));
getimage(60,30,80,50,block2);
cleardevice();
//block3
setcolor(LIGHTGREEN);
setfillstyle(SOLID_FILL,LIGHTGREEN);
bar(60,30,80,50);
block3=malloc(imagesize(60,30,80,50));
getimage(60,30,80,50,block3);
cleardevice();
//block4
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
bar(60,30,80,50);
block4=malloc(imagesize(60,30,80,50));
getimage(60,30,80,50,block4);
cleardevice();
//block5
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
bar(60,30,80,50);
block5=malloc(imagesize(60,30,80,50));
getimage(60,30,80,50,block5);
cleardevice();
}

float rad(int);
void *ball1,*ball2;

void image()
{
//ball1
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
fillellipse(10,10,10,10);
ball1=malloc(imagesize(0,0,20,20));
getimage(0,0,20,20,ball1);
//ball2
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
fillellipse(320,240,10,10);
ball2=malloc(imagesize(310,230,330,250));
getimage(310,230,330,250,ball2);

cleardevice();


}

//int checkbound();
//void refl();
int chkhole();
void end(void);
void intro(void);
//void holdis(int *,int *);
//chkstop();
//void friction(int *,int *);
//void getinidirec(int * ,int *,int *,int *);
//int collision(int *,int *,int *,int *);
void momentum();
void rballdirec();
int xcor1=1,ycor1=1,xcor2=1,ycor2=1,xstep1=1,ystep1=1,ystep2=1,xstep2=1,spdx1,spdx2;

int cap=0;
int dflag1=0,dflag2=0; //for deciding which ball goes in hole
int rflag1=0,rflag2=0;  //for deciding which ball reflects
int sflag1=0,sflag2=0;  //for deciding which ball stops




      int ar[10];
   int left, top, right, bottom;
     char ch;
 int x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;

   int stick[10];
  int  ang=270;
  int xb,yb;
int flag=0;

   int inang1=0;
   int inang2=360;
int l1,t1,l2,t2;
int fr;
int j1,k1;

   int gh=0;
   int kh=40;
 int fl2=0;
int spx,spy;
int ky,th;


int main(void)
{
  int f;
  int hole;
      int  l1=(right-left)/2+250;
  int  t1= top+50;
  int l2=l1-150;
  int t2=bottom-38;
   int stx,sty;

   int j1,k1;
    int xkey=1,gky,s1,s2;

    int lk=0,ty;

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1); /* terminate with an error code */
   }

	left = getmaxx() / 2 - 300;
   top = getmaxy() / 2 - 105;
   right = getmaxx() / 2 + 300;
   bottom = getmaxy() / 2 + 195;


   intro();
   x1=x4=left+10,x2=x5=(right-left)/2;x3=x6=right-10;
   y1=y2=y3=top+10,y4=y5=y6=(bottom+15)-10;



   ar[0]=left;
   ar[1]=top;
   ar[2]=right;
   ar[3]=top;
   ar[4]=right;
   ar[5]=bottom+15;
   ar[6]=left;
   ar[7]=bottom+15;
   ar[8]=left;
   ar[9]=top;

  xb=(l2+l2+20)/2;
  yb=(t2+t2+20)/2;




    block();
    image();



  stick[0]=(xb-3)+40*(cos(rad(ang)));
stick[1]=(yb)-40*(sin(rad(ang)));
stick[2]=stick[0]+6*(cos(rad(inang2)));
stick[3]=stick[1]-6*(sin(rad(inang2)));
stick[6]=(xb-3)+245*(cos(rad(ang)));
stick[7]=(yb)-245*(sin(rad(ang)));
stick[4]=stick[6]+6*(cos(rad(inang2)));
stick[5]=stick[7]-6*(sin(rad(inang2)));
stick[8]=stick[0];
stick[9]=stick[1];


 stx=stick[0]+stick[2];
 sty=stick[1]+stick[3];
 ch=1;


 while(xkey!=27)
 {                  int  l1=(right-left)/2+250+random(50);
  int  t1= top+50+random(5);
  int l2=l1-150+random(100);
  int t2=bottom-38;
   xb=(l2+l2+20)/2;
  yb=(t2+t2+20)/2;


  stick[0]=(xb-3)+40*(cos(rad(ang)));
stick[1]=(yb)-40*(sin(rad(ang)));
stick[2]=stick[0]+6*(cos(rad(inang2)));
stick[3]=stick[1]-6*(sin(rad(inang2)));
stick[6]=(xb-3)+245*(cos(rad(ang)));
stick[7]=(yb)-245*(sin(rad(ang)));
stick[4]=stick[6]+6*(cos(rad(inang2)));
stick[5]=stick[7]-6*(sin(rad(inang2)));
stick[8]=stick[0];
stick[9]=stick[1];

		putimage(l1,t1,ball1,XOR_PUT);
  // if(!sflag2)
   putimage(l2,t2,ball2,XOR_PUT);
   delay(5);
 //  putimage(l1,t1,ball1,XOR_PUT);
  // if(!sflag2)
 //  putimage(l2,t2,ball2,XOR_PUT);

 ch=1;
while(ch!=13)
{
init();



	putimage(l1,t1,ball1,XOR_PUT);
putimage(l2,t2,ball2,XOR_PUT);
setcolor(WHITE);
 setfillstyle(1,BROWN);
fillpoly(4,stick);
setcolor(8);
settextstyle(4,0,3);
outtextxy(120,40,"use side arrow keys to align the stick");
//while(ch!=27)
//{
//setfillstyle(1,BROWN);
//fillpoly(4,stick);
  ch=getch();
  if(ch==13)
  {
  flag=1;
  break;
  }
 else if(ch==75)
  {
   ang=ang-5;
inang2-=5;
inang1 =ang+270;

stick[0]=(xb-3)+40*(cos(rad(ang)));
stick[1]=(yb)-40*(sin(rad(ang)));
stick[2]=stick[0]+6*(cos(rad(inang2)));
stick[3]=stick[1]-6*(sin(rad(inang2)));
stick[6]=(xb-3)+245*(cos(rad(ang)));
stick[7]=(yb)-245*(sin(rad(ang)));
stick[4]=stick[6]+6*(cos(rad(inang2)));
stick[5]=stick[7]-6*(sin(rad(inang2)));
stick[8]=stick[0];
stick[9]=stick[1];
//if(inang2==0)
//inang2=360;

}
else if(ch==77)
{
ang+=5;
inang1+=5;
inang2=ang-90;
stick[0]=(xb-3)+40*(cos(rad(ang)));
stick[1]=(yb)-40*(sin(rad(ang)));
stick[2]=stick[0]+6*(cos(rad(inang1)));
stick[3]=stick[1]-6*(sin(rad(inang1)));
stick[6]=(xb-3)+245*(cos(rad(ang)));
stick[7]=(yb)-245*(sin(rad(ang)));
stick[4]=stick[6]+6*(cos(rad(inang1)));
stick[5]=stick[7]-6*(sin(rad(inang1)));
stick[8]=stick[0];
stick[9]=stick[1];
//if(inang1==360)
//inang1=0;
}


//else
//{
//setcolor(BROWN);
// setfillstyle(1,BROWN);
//fillpoly(4,stick);
//}

 setfillstyle(0,BROWN);
fillpoly(4,stick);

 delay(0);
 cleardevice();

}
   /* clean up */

if(flag==1)
{setcolor(BLACK);
settextstyle(4,0,3);
outtextxy(120,40,"use side arrow keys to align the stick");

 setcolor(11);
 settextstyle(3,0,3);
outtextxy(120,50," Use arrow  keys for power selection ");


   while(1)
   {
   for( j1=0;j1<25;j1+=5)
   {
   if(kbhit())
   {
   fl2=1;
   break;
   }
   setcolor(GREEN);
   setfillstyle(1,GREEN);
   fillpoly(4,stick);

stick[0]=(xb-3)+(kh+j1)*(cos(rad(ang)));
stick[1]=(yb)-(kh+j1)*(sin(rad(ang)));
stick[2]=stick[0]+6*(cos(rad(inang1)));
stick[3]=stick[1]-6*(sin(rad(inang1)));
stick[6]=(xb-3)+245*(cos(rad(ang)));
stick[7]=(yb)-245*(sin(rad(ang)));
stick[4]=stick[6]+6*(cos(rad(inang1)));
stick[5]=stick[7]-6*(sin(rad(inang1)));
stick[8]=stick[0];
stick[9]=stick[1];
   setcolor(WHITE);
   setfillstyle(1,BROWN);
   fillpoly(4,stick);
	 delay(100);
 }
 gh=40+j1-1;
 if(!fl2)
 {
    for(k1=j1+10-1;k1>=0;k1-=5)
    {

	 setcolor(GREEN);
   setfillstyle(1,GREEN);
   fillpoly(4,stick);

stick[0]=(xb-3)+(gh-k1)*(cos(rad(ang)));
stick[1]=(yb)-(gh-k1)*(sin(rad(ang)));
stick[2]=stick[0]+6*(cos(rad(inang1)));
stick[3]=stick[1]-6*(sin(rad(inang1)));
stick[6]=(xb-3)+245*(cos(rad(ang)));
stick[7]=(yb)-245*(sin(rad(ang)));
stick[4]=stick[6]+6*(cos(rad(inang1)));
stick[5]=stick[7]-6*(sin(rad(inang1)));
stick[8]=stick[0];
stick[9]=stick[1];
   setcolor(WHITE);
   setfillstyle(1,BROWN);
   fillpoly(4,stick);
  delay(100);
  }
  kh=gh-k1+1;
 }
 if(fl2)
 break;
 }
}
cleardevice();

   getch();
   setfillstyle(1,GREEN);

   fillpoly(4,ar);
   setfillstyle(1,BLACK);
   fillellipse(x1,y1,15,15);
   fillellipse(x2,y2,15,15);
   fillellipse(x3,y3,15,15);
   fillellipse(x4,y4,15,15);
   fillellipse(x5,y5,15,15);
   fillellipse(x6,y6,15,15);


stick[0]=(xb-3)+(40*(cos(rad(ang))));
stick[1]=(yb)-(40*(sin(rad(ang))));
stick[2]=stick[0]+6*(cos(rad(inang1)));
stick[3]=stick[1]-6*(sin(rad(inang1)));
stick[6]=(xb-3)+245*(cos(rad(ang)));
stick[7]=(yb)-245*(sin(rad(ang)));
stick[4]=stick[6]+6*(cos(rad(inang1)));
stick[5]=stick[7]-6*(sin(rad(inang1)));
stick[8]=stick[0];
stick[9]=stick[1];



	putimage(l1,t1,ball1,XOR_PUT);
putimage(l2,t2,ball2,XOR_PUT);
setcolor(WHITE);
 setfillstyle(1,BROWN);
fillpoly(4,stick);

spx=level()*10;
spy=spx;
delay(100);
switch(f)
{
case 2:
{putimage(40,40,block1,XOR_PUT);
break; }
case 4:
{
putimage(40,40,block1,XOR_PUT);
putimage(60,40,block2,XOR_PUT);
break;
}
case 6:
{
putimage(40,40,block1,XOR_PUT);
putimage(60,40,block2,XOR_PUT);
putimage(80,40,block3,XOR_PUT);
break;
}
case 8:
{
putimage(40,40,block1,XOR_PUT);
putimage(60,40,block2,XOR_PUT);
putimage(80,40,block3,XOR_PUT);
putimage(100,40,block4,XOR_PUT);
break;
}
case 10:
{
putimage(40,40,block1,XOR_PUT);
putimage(60,40,block2,XOR_PUT);
putimage(80,40,block3,XOR_PUT);
putimage(100,40,block4,XOR_PUT);
putimage(120,40,block5,XOR_PUT);
break;
}


}
shoot();
fr=1;
cleardevice();

//init();
l1+=30;
gky=1;

s1=s2=0;
//getinidirec(&xb,&yb,&stx,&sty);
ty=400;
  putimage(l1,t1,ball1,XOR_PUT);
    putimage(l2,t2,ball2,XOR_PUT);
init();
while(gky!=27)
{
while(!kbhit())//gky!=27)
{
//  init();
   putimage(l1,t1,ball1,XOR_PUT);
  // if(!sflag2)
   putimage(l2,t2,ball2,XOR_PUT);
   delay(5);
   putimage(l1,t1,ball1,XOR_PUT);
  // if(!sflag2)
   putimage(l2,t2,ball2,XOR_PUT);

//collision
  momentum();

if(l1>=right||l1<=left){xcor1*=-1;sound(1000);s1=0;xstep1=xcor1*(int)((spx--)/100.0)*(random(4)+1);ystep1=ycor1
*(int)((spy--)/100.0)*(random(3)+1);if(l1<=left)l1=left;else l1=right;}

if(l2>=right||l2<=left){xcor2*=-1;sound(1000);s2=0;xstep2=xcor2*(int)((spx--)/100.0)*(random(4)+1);ystep2=ycor2
*(int)((spy--)/100.0)*random((3)+1);if(l2<=left)l2=left;else l2=right;}


if(t1>=bottom||t1<=top){ycor1*=-1;sound(1000);s1=0;ystep1=ycor1*(int)((spy--)/100.0)*(random(4)+1);xstep1=xcor1
*(int)((spx--)/100.0)*(random(3)+1);if(t1<=top)t1=top;else t1=bottom;}

if(t2>=bottom||t2<=top){ycor2*=-1;sound(1000);s2=0;ystep2=ycor2*(int)((spy--)/100.0)*(random(4)+1);xstep2=xcor2
*(int)((spx--)/100.0)*(random(3)+1);if(t2<=top)t2=top;else t2=bottom;}


if(spx<0) spx=0;
if(spy<0) spy=0;

hole=chkhole();
if( hole)
      {

       break;

      }

l1+=xcor1+xstep1;
t1+=ycor1+ystep1;
s1++;

l2+=xcor2+xstep2;
t2+=ycor2+ystep2;
s2++;
//spx--;
//spy--;
 if((spx==0)&&(spy==0))
 {
 fr=0;
 break;
 }

if((s1==5)||(s2==5))
{nosound();}
}

   if(!fr)
{
putimage(l1,t1,ball1,XOR_PUT);
putimage(l2,t2,ball2,XOR_PUT);
}


 if(dflag1)
 {
      outtext(" congratulation");
       break;
       }

       if(dflag2)
	{
       outtext("FOWL");
	 break;
	 }

	   if(!fr) break;
       gky=getch();


/*	 if(dflag1)
      outtext("congratulation");
       if(dflag2)
       outtext("FOWL");
  */
      }
setcolor(RED);
settextstyle(3,0,2);
outtextxy(30,40,"Press enter to continue and escape to exit");
xkey=getch();
setcolor(BLACK);
settextstyle(3,0,2);
outtextxy(30,40,"Press enter to continue and escape to exit");
nosound();

if(xkey==13)
continue;
	 nosound();	 

}
	nosound();
end();
getch();


   closegraph();

}

float rad(int deg)
{
float r;
r=(3.14/180)*deg;
return r;
}


int level()
{
setcolor(YELLOW);
settextstyle(1,0,5);
outtextxy(300,50,"select ur power");
 ky=1 ;th=0;
ky=getch();

while(ky!=13)
{
if(ky==77&&rcount<5)
{
rcount++;
}
else if(ky==75&&rcount>1)
{
rcount--;
}



switch(rcount)
{

case 1:
{
putimage(40,40,block1,XOR_PUT);
lev=2;
break;
}
case 2:
{
putimage(40,40,block1,XOR_PUT);
putimage(60,40,block2,XOR_PUT);
lev=4;
break;
}
case 3:
{
putimage(40,40,block1,XOR_PUT);
putimage(60,40,block2,XOR_PUT);
putimage(80,40,block3,XOR_PUT);
lev=6;
break;
}
case 4:
{
putimage(40,40,block1,XOR_PUT);
putimage(60,40,block2,XOR_PUT);
putimage(80,40,block3,XOR_PUT);
putimage(100,40,block4,XOR_PUT);
lev=8;
break;
}
case 5:
{
putimage(40,40,block1,XOR_PUT);
putimage(60,40,block2,XOR_PUT);
putimage(80,40,block3,XOR_PUT);
putimage(100,40,block4,XOR_PUT);
putimage(120,40,block5,XOR_PUT);
lev=10;
break;
}
default:
th=1;
}
if(th==1)
{
continue;
}
ky=getch();
}

return lev;
}
void shoot(void)
{
   int gh=0;
   int kh=40;

   for( j1=0;j1<25;j1+=5)
   {
   setcolor(GREEN);
   setfillstyle(1,GREEN);
   fillpoly(4,stick);

stick[0]=(xb-3)+(kh+j1)*(cos(rad(ang)));
stick[1]=(yb)-(kh+j1)*(sin(rad(ang)));
stick[2]=stick[0]+6*(cos(rad(inang1)));
stick[3]=stick[1]-6*(sin(rad(inang1)));
stick[6]=(xb-3)+245*(cos(rad(ang)));
stick[7]=(yb)-245*(sin(rad(ang)));
stick[4]=stick[6]+6*(cos(rad(inang1)));
stick[5]=stick[7]-6*(sin(rad(inang1)));
stick[8]=stick[0];
stick[9]=stick[1];
   setcolor(WHITE);
   setfillstyle(1,BROWN);
   fillpoly(4,stick);
	 delay(200);
 }
 gh=40+j1-1;

    for( k1=j1+22-1;k1>=0;k1-=5)
    {

	 setcolor(GREEN);
   setfillstyle(1,GREEN);
   fillpoly(4,stick);

stick[0]=(xb-3)+(gh-k1)*(cos(rad(ang)));
stick[1]=(yb)-(gh-k1)*(sin(rad(ang)));
stick[2]=stick[0]+6*(cos(rad(inang1)));
stick[3]=stick[1]-6*(sin(rad(inang1)));
stick[6]=(xb-3)+245*(cos(rad(ang)));
stick[7]=(yb)-245*(sin(rad(ang)));
stick[4]=stick[6]+6*(cos(rad(inang1)));
stick[5]=stick[7]-6*(sin(rad(inang1)));
stick[8]=stick[0];
stick[9]=stick[1];
   setcolor(WHITE);
   setfillstyle(1,BROWN);
   fillpoly(4,stick);
  delay(50);
  }
  }
void init()
{
  setfillstyle(1,GREEN);

   fillpoly(4,ar);
   setfillstyle(1,BLACK);
   fillellipse(x1,y1,15,15);
   fillellipse(x2,y2,15,15);
   fillellipse(x3,y3,15,15);
   fillellipse(x4,y4,15,15);
   fillellipse(x5,y5,15,15);
   fillellipse(x6,y6,15,15);
     }


void getinidirec(int *xb,int *yb,int *stx,int *sty)
{
   if((*stx)<(*xb))
   xcor2=1;
   else
   xcor2=-1;
   if((*sty)>(*yb))
   ycor2=-1;
   else
   ycor2=1;
  ystep2=((((*sty)-(*yb))/((*stx)-(*xb))) * (l2-(*xb)))+(*yb);
 }


int chkhole()
{
int ret=0;
int i,j,k,l;
for(i=x1-8;i<x1+8;i++)
{
for(j=y1-15;j<y1+15;j++)
{

if(((l1==i)||(l1+20==i))&&(((t1)==j)||(t1+20==j)))
{
ret=1;
dflag1=1;
putimage(l1,t1,ball1,XOR_PUT);
}
}}


for(i=x2-15;i<x2+15;i++)
{
for(j=y2-15;j<y2+15;j++)
{
if(((l1==i)||(l1+20==i))&&(((t1)==j)||(t1+20==j)))
{
ret=1;
dflag1=1;
putimage(l1,t1,ball1,XOR_PUT);
}
}}


for(i=x3-15;i<x3+15;i++)
{
for(j=y3-15;j<y3+15;j++)
{
if(((l1==i)||(l1+20==i))&&(((t1)==j)||(t1+20==j)))
{
ret=1;
dflag1=1;
putimage(l1,t1,ball1,XOR_PUT);
}
}}



for(i=x4-15;i<x4+15;i++)
{
for(j=y4-15;j<y4+15;j++)
{
if(((l1==i)||(l1+20==i))&&(((t1)==j)||(t1+20==j)))
{
ret=1;
dflag1=1;
putimage(l1,t1,ball1,XOR_PUT);
}
}}



for(i=x5-15;i<x5+15;i++)
{
for(j=y5-15;j<y5+15;j++)
{
if(((l1==i)||(l1+20==i))&&(((t1)==j)||(t1+20==j)))
{
ret=1;
dflag1=1;
putimage(l1,t1,ball1,XOR_PUT);
}
}}


for(i=x6-15;i<x6+15;i++)
{
for(j=y6-15;j<y6+15;j++)
{
if(((l1==i)||(l1+20==i))&&(((t1)==j)||(t1+20==j)))
{
ret=1;
dflag1=1;
putimage(l1,t1,ball1,XOR_PUT);
}
}}



for(i=x1-15;i<x1+15;i++)
{
for(j=y1-15;j<y1+15;j++)
{
if(((l2==i)||(l2+20==i))&&(((t2)==j)||(t2+20==j)))
{
ret=1;
dflag2=1;
putimage(l2,t2,ball2,XOR_PUT);
}
}}


for(i=x2-15;i<x2+15;i++)
{
for(j=y2-15;j<y2+15;j++)
{
if(((l2==i)||(l2+20==i))&&(((t2)==j)||(t2+20==j)))
{
ret=1;
dflag2=1;
putimage(l2,t2,ball2,XOR_PUT);
}
}}



for(i=x3-15;i<x3+15;i++)
{
for(j=y3-15;j<y3+15;j++)
{
if(((l2==i)||(l2+20==i))&&(((t2)==j)||(t2+20==j)))
{
ret=1;
dflag2=1;
putimage(l2,t2,ball2,XOR_PUT);
}
}}



for(i=x4-15;i<x4+15;i++)
{
for(j=y4-15;j<y4+15;j++)
{
if(((l2==i)||(l2+20==i))&&(((t2)==j)||(t2+20==j)))
{
ret=1;
dflag2=1;
putimage(l2,t2,ball2,XOR_PUT);
}
}}


for(i=x5-15;i<x5+15;i++)
{
for(j=y5-15;j<y5+15;j++)
{
if(((l2==i)||(l2+20==i))&&(((t2)==j)||(t2+20==j)))
{
ret=1;
dflag2=1;
putimage(l2,t2,ball2,XOR_PUT);
}
}}


for(i=x6-15;i<x6+15;i++)
{
for(j=y6-15;j<y6+15;j++)
{
if(((l2==i)||(l2+20==i))&&(((t2)==j)||(t2+20==j)))
{
ret=1;
dflag2=1;
putimage(l2,t2,ball2,XOR_PUT);
}
}}

return ret;
}
int collision(int *l1,int *t1,int *l2,int *t2)
{
int ret=0;
if(((*l1)==(*l2)+3)||((*l2)==(*l1)+3))
{  if(((*t1)==(*t2)+3)||((*t2)==(*t1)+3))
     {
     cap=1;
     ret=1;
     }
 }

 if(((*t1)==(*t2)+3)||((*t2)==(*t1)+3))
{  if(((*l1)==(*l2)+3)||((*l2)==(*l1)+3))
     {
     cap=1;
     ret=1;
     }
 }

 return ret;
 }
 void momentum()
 {   int temp;


 if(((l1==l2+5)||(l2==l1+5))&&(t1==t2))
{
	if(y1==y2)
	{
			if(l1>l2)
			{
			xstep1=(xcor1)*(int)((spx--)/100.0)*(random(4)+1);ystep1=ycor1*(int)((spy--)/100.0)*(random(3)+1);
			xstep2=xcor2*(int)((spx--)/100.0)*(random(4)+1);ystep2=ycor2*(int)((spy--)/100.0)*(random(3)+1) ;
			}

		 else
		{
		xstep1=(xcor1)*(int)((spx--)/100.0)*(random(4)+1);ystep1=ycor1*(int)((spy--)/100.0)*(random(3)+1);
		xstep2=(xcor2)*(int)((spx--)/100.0)*(random(4)+1);ystep2=ycor2*(int)((spy--)/100.0)*(random(3)+1);
		}
		 }
	else
	{
	xcor1*=-1;
	xcor2*=-1;
	xstep1=xcor1*(int)((spx--)/100.0)*(random(4)+1);ystep1=ycor1*(int)((spy--)/100.0)*(random(3)+1);
	xstep2=xcor2*(int)((spx--)/100.0)*(random(4)+1);ystep2=ycor2*(int)((spy--)/100.0)*(random(3)+1) ;
	 }
 }
if(((t1==t2+5)||(t2==t1+5))&&(l1==l2))
{
	if(xcor1==xcor2)
	{                                                                               //krsna conciousness
			 if(t1>t2)
			{
			ystep1=(ycor1)*(int)((spy--)/100.0)*(random(2)+2);xstep1=xcor1*(int)((spx--)/100.0)*(random(2)+2);
			ystep2=ycor2*(int)((spy--)/100.0)*(random(3)+1);xstep2=xcor2*(int)((spx--)/100.0)*(random(3)+1) ;
			 }
			else
			{
			ystep1=ycor1*(int)((spy--)/100.0)*(random(4)+1);xstep1=xcor1*(int)((spx--)/100.0)*(random(3)+1);
			ystep2=(ycor2)*(int)((spy--)/100.0)*(random(4)+1);xstep2=xcor2*(int)((spx--)/100.0)*(random(3)+1) ;
			 }
	 }
	  else
	  {
	     ycor1*=-1;
	     ycor2*=-1;
	     ystep1=ycor1*(int)((spy--)/100.0)*(random(4)+1);xstep1=xcor1*(int)((spx--)/100.0)*(random(3)+1);
	     ystep2=ycor2*(int)((spy--)/100.0)*(random(4)+1);xstep2=xcor2*(int)((spx--)/100.0)*(random(3)+1) ;
	  }

 }
	  if(((l1==l2+2)||(l2==l1+2))&&((t1==t2+2)||(l2==l1+2)))
{
     if(ycor1==ycor2)
{
			if(l1>l2)
			{
			xstep1=(xcor1)*(int)((spx--)/100.0)*(random(4)+1);ystep1=ycor1*(int)((spy--)/100.0)*(random(3)+1);
			xstep2=xcor2*(int)((spx--)/100.0)*(random(4)+1);ystep2=ycor2*(int)((spy--)/100.0)*(random(3)+1) ;
			}

		 else
		{
		xstep1=(xcor1)*(int)((spx--)/100.0)*(random(4)+1);ystep1=ycor1*(int)((spy--)/100.0)*(random(3)+1);
		xstep2=(xcor2)*(int)((spx--)/100.0)*(random(4)+1);ystep2=ycor2*(int)((spy--)/100.0)*(random(3)+1);
		}
		 }
  if((ycor1!=ycor2)&&(xcor1!=xcor2))
	{
	xcor1*=-1;
	xcor2*=-1;
	ycor2*=-1;
	ycor1*=-1;
	xstep1=xcor1*(int)((spx--)/100.0)*(random(2)+2);ystep1=ycor1*(int)((spy--)/100.0)*(random(4)+1);
	xstep2=xcor2*(int)((spx--)/100.0)*(random(4)+0);ystep2=ycor2*(int)((spy--)/100.0)*(random(2)+2) ;
	 }



	if(xcor1==xcor2)
	{
			 if(t1>t2)
			{
			ystep1=(ycor1)*(int)((spy--)/100.0)*(random(4)+2);xstep1=xcor1*(int)((spx--)/100.0)*(random(3)+3);
			ystep2=ycor2*(int)((spy--)/100.0)*(random(4)+1);xstep2=xcor2*(int)((spx--)/100.0)*(random(3)+1) ;
			 }
			else
			{
			ystep1=ycor1*(int)((spy--)/100.0)*(random(4)+3);xstep1=xcor1*(int)((spx--)/100.0)*(random(3)+2);
			ystep2=(ycor2)*(int)((spy--)/100.0)*(random(4)+1);xstep2=xcor2*(int)((spx--)/100.0)*(random(3)+1) ;
			 }
	 }
	  else
	  {
	     ycor1*=-1;
	     ycor2*=-1;
	     ystep1=ycor1*(int)((spy--)/100.0)*(random(4)+2);xstep1=xcor1*(int)((spx--)/100.0)*(random(3)+3);
	     ystep2=ycor2*(int)((spy--)/100.0)*(random(4)+1);xstep2=xcor2*(int)((spx--)/100.0)*(random(3)+1) ;
	  }




      }

}
void rballdirec()
{
ystep1=ystep2;
}
int checkbound()
{
int ret=0;
if(l1>=right||l1<=left)
{rflag1=1;
ret=1;
}
else if(l2>=right||l2<=left)
{
rflag2=1;
ret=1;
}


else if(t1>=bottom||t1<=top)
{
rflag1=1;
ret=1;
}

else if(t2>=bottom||t2<=top)
{
rflag2=1;
ret=1;
}

return ret;
}
/*void refl()
{


if(l1>=right||l1<=left){xcor1*=-1;sound(1000);s1=0;xstep1=xcor1*(int)((spx--)/100.0)*(random(4)+1);ystep1=ycor1
*(int)((spy--)/100.0)*(random(3)+1);if(l1<=left)l1=left;else l1=right;}

if(l2>=right||l2<=left){xcor2*=-1;sound(1000);s2=0;xstep2=xcor2*(int)((spx--)/100.0)*(random(4)+1);ystep2=ycor2
*(int)((spy--)/100.0)*random((3)+1);if(l2<=left)l2=left;else l2=right;}


if(t1>=bottom||t1<=top){ycor1*=-1;sound(1000);s1=0;ystep1=ycor1*(int)((spy--)/100.0)*(random(4)+1);xstep1=xcor1
*(int)((spx--)/100.0)*(random(3)+1);if(t1<=top)t1=top;else t1=bottom;}

if(t2>=bottom||t2<=top){ycor2*=-1;sound(1000);s2=0;ystep2=ycor2*(int)((spy--)/100.0)*(random(4)+1);xstep2=xcor2
*(int)((spx--)/100.0)*(random(3)+1);if(t2<=top)t2=top;else t2=bottom;}

}
*/
void friction(int *spdx1,int *spdx2)
{
(*spdx1)--;
(*spdx2)--;
}
void chkstop(int *spdx1,int *spdx2)
{
if((*spdx1)<1)
sflag1=1;
else if((*spdx2)<1)
sflag2=1;
}

void intro(void)
{   int i,j;

int midx=getmaxx()/2;
int midy=getmaxy()/2;
		setcolor(6);
   settextstyle(4,0,5);
   outtextxy(200,150,"WELCOME ");
   setcolor(5);
   settextstyle(1,0,3);
   delay(50);
   outtextxy(150,300,"noble0ul corporations presents");
   delay(2000);
   setcolor(10);
  // outtextxy(200,400,"press enter to continue");

 cleardevice();
 setcolor(9);
 settextstyle(4,0,3);
 outtextxy(120,120,"Please wait while files are being loaded ...");
 setcolor(RED);
 delay(50);
     rectangle(midx-200,midy-20,midx+200,midy+30);
     for(i=0;i<400;i++)
     {
  //  gotoxy(150,180);
    //  printf("%2f",((i/398.0)*100));
     line(i+120,midy-20,i+120,midy+30);
     delay(25);
     }
     setcolor(11);
     settextstyle(1,0,3);
     outtextxy(300,400,"press enter to continue");
   getch();
   cleardevice();
   setcolor(13);
   settextstyle(3,0,5);
   outtextxy(150,80," The Last Ball");
   settextstyle(3,0,2);
   outtextxy(420,63,"TM");



   for(j=400;j>150;j--)
   {

   setcolor(RED);
   setfillstyle(1,RED);
   fillellipse(j,j,30,30);
   setcolor(BROWN);
   setfillstyle(1,BROWN);
   bar(j-200,j-50,j-30,j-40);
   delay(10);
   setfillstyle(1,BLACK);
   setcolor(BLACK);
   fillellipse(j,j,30,30);
   setcolor(BLACK);
   setfillstyle(1,BLACK);
   bar(j-200,j-50,j-80,j-30);
   }
   setcolor(RED);
    setfillstyle(1,RED);
   fillellipse(j,j,30,30);
   setcolor(BROWN);
   setfillstyle(1,BROWN);
   bar(j-200,j-50,j-30,j-40);


   setcolor(11);
   settextstyle(3,0,3);
   outtextxy(400,300,"A snooker game");
   getch();
   cleardevice();
   }
   void end(void)
   { cleardevice();
    setcolor(8);
	settextstyle(2,0,5);
	outtextxy(100,40,"important notice");
	outtextxy(50,60,"nobles0ul and The Last Ball are copyrightes to be  solely used by maykash  any illegal distribution will be severly prosecuted");
 setcolor(12);
 settextstyle(4,0,4);
 outtextxy(120,180,"Thank for trying our game");
 delay(20);
 settextstyle(5,0,4);
 outtextxy(140,330,"Made by ");
 setcolor(13);
 outtextxy(130,370,"Mayank ,Aakash and  Rohit");
 getch();
 cleardevice();



 }