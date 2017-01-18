#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define R(a) (int)(a+0.5)


void colorboard(int x,int y);
void createboard(int x,int y);
void circle1(int xc,int yc,int r);
void line1(int,int,int,int);
void addnumbers();
void startup();
void draw();
void ladder1();
void instructions();
void snake1();
void ladder2();
void snake2();
void removecoin1(int,int);
void removecoin2(int,int);
void placecoin1(int,int);
void placecoin2(int,int);
void decidepos1(int,int,int);
void decidepos2(int,int,int);
void draw()
{

   setbkcolor(0);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,0);

   //DICE Button
   line1(490,50,550,50);
   line1(550,50,550,80);
   line1(550,80,490,80);
   line1(490,80,490,50);
   setfillstyle(SOLID_FILL,15);
   floodfill(500,70,8);
   setcolor(BLUE);
   outtextxy(515,64,"DICE");


   //DICE Value Box
   line1(490,90,550,120);
   line1(550,90,550,120);
   line1(550,120,490,120);
   line1(490,120,490,90);

   //Exit Button
   line1(490,420,550,420);
   line1(550,420,550,450);
   line1(550,450,490,450);
   line1(490,450,490,420);
   setfillstyle(SOLID_FILL,CYAN);
   floodfill(500,430,8);
   setcolor(BLUE);
   outtextxy(515,434,"EXIT");

   setcolor(WHITE);
   circle(540,272,5);
   circle(540,252,5);

}
void instructions()
{
int k;
setcolor(RED);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);

outtextxy(200,20,"RULES");
setcolor(WHITE);
//gotoxy(30,100);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(10,100,"1.ONLY TWO PLAYERS CAN PLAY THIS GAME");
outtextxy(10,120,"2.The positions and effects of snakes and ladders will be consistent.");
outtextxy(10,140,"3.The starting and ending point of snake and ladder are mentioned on the right");
outtextxy(10,160,"4.Each player starts off the board at space 0.");
outtextxy(10,180,"5.The winner is the first player to end a turn on space 100.");
outtextxy(10,200,"6.Green dot will tell you about the turn of the player");

}
void display()
{
int k;
setbkcolor(BLACK);
for(k=0;k<=10;k++)
{
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,k);
setcolor(RED);
outtextxy(100,100,"SNAKE");
setcolor(WHITE);
outtextxy(300,150,"&");
setcolor(GREEN);
outtextxy(150,200,"LADDER");
delay(300);
cleardevice();
}

delay(10000);
cleardevice();
}
void startup()
{
int x,y,k;
setfillstyle(SOLID_FILL,7);
floodfill(10,10,7);
setbkcolor(CYAN);
setcolor(RED);
settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
outtextxy(200,200,"...Loading...");
setcolor(BLACK);
line1(110,223,512,223);
line1(512,223,512,240);
line1(512,240,110,240);
line1(110,240,110,223);
gotoxy(15,15);
for(k=0;k<50;k++)
{
   setcolor(CYAN);
   printf(" ");
   delay(100);
}
delay(2000);
cleardevice();
setbkcolor(BLACK);
display();
instructions();
setbkcolor(BLACK);
setcolor(8);
delay(10000);
cleardevice();
}

union REGS in,out;
int one=-1,ONE=-1;
int i=0,j=0;
int arr2[101][2]={{-1,-1},{70,430},{110,430},{150,430},{190,430},{230,430},
{270,430},{310,430},{350,430},{390,430},{430,430}
,{430,390},{390,390},{350,390},{310,390},{270,390},
{230,390},{190,390},{150,390},{110,390},{70,390},
{70,350},{110,350},{150,350},{190,350},{230,350},
{270,350},{310,350},{350,350},{390,350},{430,350},
{430,310},{390,310},{350,310},(310,310),(270,310),
{230,310},{190,310},{150,310},{110,310},{70,310},
{70,270},{110,270},{150,270},{190,270},{230,270},
{270,270},{310,270},{350,270},{390,270},{430,270},
{430,230},{390,230},{350,230},{310,230},{270,230},
{230,230},{190,230},{150,230},{110,230},{70,230},
{70,190},{110,190},{150,190},{190,190},{230,190},
{270,190},{310,190},{350,190},{390,190},{430,190},
{430,150},{390,150},{350,150},{310,150},{270,150},
{230,150},{190,150},{150,150},{110,150},{70,150},
{70,110},{110,110},{150,110},{190,110},{230,110},
{270,110},{310,110},{350,110},{390,110},{430,110},
{430,70},{390,70},{350,70},{310,70},{270,70},
{230,70},{190,70},{150,70},{110,70},{70,70}
};
int arr1[101][2]={{-1,-1},{70,430},{110,430},{150,430},{190,430},{230,430},
{270,430},{310,430},{350,430},{390,430},{430,430}
,{430,390},{390,390},{350,390},{310,390},{270,390},
{230,390},{190,390},{150,390},{110,390},{70,390},
{70,350},{110,350},{150,350},{190,350},{230,350},
{270,350},{310,350},{350,350},{390,350},{430,350},
{430,310},{390,310},{350,310},(310,310),(270,310),
{230,310},{190,310},{150,310},{110,310},{70,310},
{70,270},{110,270},{150,270},{190,270},{230,270},
{270,270},{310,270},{350,270},{390,270},{430,270}
,{430,230},{390,230},{350,230},{310,230},{270,230},
{230,230},{190,230},{150,230},{110,230},{70,230},
{70,190},{110,190},{150,190},{190,190},{230,190},
{270,190},{310,190},{350,190},{390,190},{430,190},
{430,150},{390,150},{350,150},{310,150},{270,150},
{230,150},{190,150},{150,150},{110,150},{70,150},
{70,110},{110,110},{150,110},{190,110},{230,110},
{270,110},{310,110},{350,110},{390,110},{430,110},
{430,70},{390,70},{350,70},{310,70},{270,70},
{230,70},{190,70},{150,70},{110,70},{70,70}};
void showmouseptr()
{
   in.x.ax = 1;
   int86(0X33,&in,&out);
}

void getmousepos(int *button, int *x, int *y)
{
   in.x.ax = 3;
   int86(0X33,&in,&out);

   *button = out.x.bx;
   *x = out.x.cx;
   *y = out.x.dx;
}

void main()
{
   int p1,p2,count=0,k;
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode,status, button;
   int prev,x,y,x1,y1;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   startup();

   setcolor(WHITE);
   setbkcolor(BLACK);
   rectangle(470,125,570,240);

   setfillstyle(CLOSE_DOT_FILL,BLACK);
   floodfill(500,150,getmaxcolor());

   setcolor(GREEN);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(510,140,"LADDERS");
   setcolor(WHITE);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(510,160,"7-26");
   outtextxy(510,170,"20-58");
   outtextxy(510,180,"40-59");
   outtextxy(510,190,"63-81");
   outtextxy(510,200,"71-91");

   rectangle(470,285,570,400);
   setfillstyle(SOLID_FILL,BLACK);
   floodfill(500,350,getmaxcolor());


   setcolor(RED);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(500,300,"SNAKES");
   setcolor(WHITE);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(500,320,"17-6");
   outtextxy(500,330,"54-34");
   outtextxy(500,340,"62-19");
   outtextxy(500,350,"87-24");
   outtextxy(500,360,"99-78");


   showmouseptr();
   getmousepos(&button,&x,&y);
   while(!kbhit())

   {

	draw();
	setcolor(8);

	/*to create board*/
	createboard(50,50);

	/*to show the numbers on the board*/
	addnumbers();

	getmousepos(&button,&x,&y);
	setcolor(BLUE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	outtextxy(500,250,"PLAYER 1 ");
	outtextxy(500,270,"PLAYER 2 ");

	if((button==1) && (x>490 && x<550) && (y>50 && y<80))
	 {
	 if((count%2)==0)
		   {
		    /*to light up the circle whwn it's player1 turns*/
		    setfillstyle(SOLID_FILL,BLACK);
		    floodfill(540,252,getmaxcolor());
		    setfillstyle(SOLID_FILL,GREEN);
		    floodfill(540,272,getmaxcolor());

		   }
	 else
	 {
		    /*to light up the circle whwn it's player2 turns*/
		    setfillstyle(SOLID_FILL,BLACK);
		    floodfill(540,272,getmaxcolor());
		    setfillstyle(SOLID_FILL,GREEN);
		    floodfill(540,252,getmaxcolor());

	  }
	 if((count%2)==0)
		{
		setcolor(RED);
		gotoxy(66,7);
		p1=random(6)+1;
		if(count==2)
		p1=6;
		printf("\b%d",p1);
		decidepos1(p1,arr1[i][0],arr1[i][1]);

		count++;
		}
		else
		{
		setcolor(RED);
		p2=random(6)+1;

		printf("\b%d",p2);
		decidepos2(p2,arr2[j][0],arr2[j][1]);

		count++;
		}
		placecoin1(arr1[i][0],arr1[i][1]);
		placecoin2(arr2[j][0],arr2[j][1]);

		button = 1;
		delay(500);

	 }
	 else if((button==1) && (x>490 && x<550) && (y>420 && y<450))
	 {
		button = 1;
		setfillstyle(SOLID_FILL,7);
		floodfill(10,10,7);
		setbkcolor(CYAN);
		setcolor(RED);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
		outtextxy(200,200,"...Exiting...Please Wait...");
		setcolor(BLACK);
		line1(110,223,512,223);
		line1(512,223,512,240);
		line1(512,240,110,240);
		line1(110,240,110,223);
		gotoxy(15,15);
		for(k=0;k<50;k++)
		{
			setcolor(CYAN);
			printf(" ");
			delay(40);
		}
		closegraph();
		exit(0);
	 }


   }

   /* clean up */
   getch();
   closegraph();
}
void line1(int xa,int ya,int xb,int yb)
{
	int dx,dy,x,y,i,steps,xi,yi;
	dx=xb-xa;
	dy=yb-ya;
	x=xa;
	y=ya;
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
	}
	xi=dx/(float)steps;
	yi=dy/(float)steps;
	putpixel (R(x),R(y),8);
	for(i=0;i<steps;i++)
	{
		x=x+xi;
		y=y+yi;
		putpixel (R(x),R(y),8);
	}
}
void circle1(int xc,int yc,int r)
{
	int x,y,dx,dy,d;
	putpixel(xc,yc+r,8);
	putpixel(xc,yc-r,8);
	putpixel(xc+r,yc,8);
	putpixel(xc-r,yc,8);
	x=0;
	y=r;
	d=3-2*r;
	while(x<y)
	{
		x++;
		if(d<0)
		{
			d=d+4*x+6;
		}
		else if(d>0)
		{
			y--;
			d=d+4*x-4*y+10;
		}
		putpixel(xc+x,yc+y,8);
		putpixel(xc+y,yc+x,8);
		putpixel(xc+y,yc-x,8);
		putpixel(xc+x,yc-y,8);
		putpixel(xc-x,yc-y,8);
		putpixel(xc-y,yc-x,8);
		putpixel(xc-y,yc+x,8);
		putpixel(xc-x,yc+y,8);
	}
}

void createboard(int x,int y)
{
	int i;
	for(i=0;i<=10;i++)
	{
		line1(x,50,x,450);
		line1(50,y,450,y);
		x=x+40;
		y=y+40;
	}
}
void colorboard(int x1,int y1)
{
	int x,y,i,j;
	y=y1;
	for(i=1;i<=10;i++)
	{
	x=x1;
	for(j=1;j<=10;j++)
	{
		setfillstyle(SOLID_FILL,rand());
		floodfill(x,y,getmaxcolor());
		x=x+40;
	}
	y=y+40;
   }

}


void decidepos1(int p,int x,int y)
{
removecoin1(x,y);
if(i==99)
{
   if(p==1)
    i=100;
   else
   i=99;
}
else if(i==98)
{
  if(p==1)
  i=98;
  else if(p==2)
  i=100;
  else
  i=98;
}
else if(i==97)
{
 if(p==1)
  i=98;
  else if(p==2)
  i=99;
  else if(p==3)
  i=100;
  else
  i=97;
}
else if(i==96)
{
 if(p==1)
  i=97;
  else if(p==2)
  i=98;
  else if(p==3)
  i=99;
  else if(p==4)
  i=100;
  else
  i=96;
}
else if(i==95)
{
 if(p==1)
  i=96;
  else if(p==2)
  i=97;
  else if(p==3)
  i=98;
  else if(p==4)
  i=99;
  else if(p==5)
  i=100;
  else
  i=95;
}
else if(one==-1&&p==6)
{
i=i+1;
one=0;
}
else if(one==0)
{
i=i+p;
}
ladder1();
snake1();
}
void decidepos2(int p,int x,int y)
{
removecoin2(x,y);
if(j==99)
{
   if(p==1)
    j=100;
   else
   j=99;
}
else if(j==98)
{
  if(p==1)
  j=98;
  else if(p==2)
  j=100;
  else
  j=98;
}
else if(j==97)
{
 if(p==1)
  j=98;
  else if(p==2)
  j=99;
  else if(p==3)
  j=100;
  else
  j=97;
}
else if(j==96)
{
 if(p==1)
  j=97;
  else if(p==2)
  j=98;
  else if(p==3)
  j=99;
  else if(p==4)
  j=100;
  else
  j=96;
}
else if(j==95)
{
 if(p==1)
  j=96;
  else if(p==2)
  j=97;
  else if(p==3)
  j=98;
  else if(p==4)
  j=99;
  else if(p==5)
  j=100;
  else
  j=95;
}
else if(ONE==-1&&p==6)
{
j=j+1;
ONE=0;
}
else if(ONE==0)
{
j=j+p;
}
ladder2();
snake2();
}

void removecoin1(int x,int y)
{
setfillstyle(SOLID_FILL,0);
floodfill(x,y,getmaxcolor());
setcolor(0);
circle(x,y,10);
}
void removecoin2(int x,int y)
{

setfillstyle(SOLID_FILL,0);
floodfill(x,y,getmaxcolor());
setcolor(0);
circle(x,y,10);


}

void placecoin1(int x,int y)
{
int k;
if(i==100)
{
   cleardevice();
   for(k=0;k<=10;k++)
   {
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,k);
   setcolor(RED);
   outtextxy(250,250,"PLAYER 1 WINS");
   delay(300);
   cleardevice();

   }
   for(k=0;k<=10;k++)
   {
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,k);
   setcolor(RED);
   outtextxy(250,250,"GAME OVER");
   delay(300);
   cleardevice();

   }
}
setcolor(WHITE);
circle(x,y,10);
setfillstyle(SOLID_FILL,RED);
floodfill(x,y,getmaxcolor());



}
void placecoin2(int x,int y)
{
setcolor(WHITE);
circle(x,y,10);
setfillstyle(SOLID_FILL,YELLOW);
floodfill(x,y,getmaxcolor());



}


void addnumbers()
{
settextjustify(CENTER_TEXT,CENTER_TEXT);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
outtextxy(70,70,"100");
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
outtextxy(110,70,"99");
outtextxy(150,70,"98");
outtextxy(190,70,"97");
outtextxy(230,70,"96");
outtextxy(270,70,"95");
outtextxy(310,70,"94");
outtextxy(350,70,"93");
outtextxy(390,70,"92");
outtextxy(430,70,"91");
outtextxy(70,110,"81");
outtextxy(110,110,"82");
outtextxy(150,110,"83");
outtextxy(190,110,"84");
outtextxy(230,110,"85");
outtextxy(270,110,"86");
outtextxy(310,110,"87");
outtextxy(350,110,"88");
outtextxy(390,110,"89");
outtextxy(430,110,"90");
outtextxy(70,150,"80");
outtextxy(110,150,"79");
outtextxy(150,150,"78");
outtextxy(190,150,"77");
outtextxy(230,150,"76");
outtextxy(270,150,"75");
outtextxy(310,150,"74");
outtextxy(350,150,"73");
outtextxy(390,150,"72");
outtextxy(430,150,"71");
outtextxy(70,190,"61");
outtextxy(110,190,"62");
outtextxy(150,190,"63");
outtextxy(190,190,"64");
outtextxy(230,190,"65");
outtextxy(270,190,"66");
outtextxy(310,190,"67");
outtextxy(350,190,"68");
outtextxy(390,190,"69");
outtextxy(430,190,"70");
outtextxy(70,230,"60");
outtextxy(110,230,"59");
outtextxy(150,230,"58");
outtextxy(190,230,"57");
outtextxy(230,230,"56");
outtextxy(270,230,"55");
outtextxy(310,230,"54");
outtextxy(350,230,"53");
outtextxy(390,230,"52");
outtextxy(430,230,"51");
outtextxy(70,270,"41");
outtextxy(110,270,"42");
outtextxy(150,270,"43");
outtextxy(190,270,"44");
outtextxy(230,270,"45");
outtextxy(270,270,"46");
outtextxy(310,270,"47");
outtextxy(350,270,"48");
outtextxy(390,270,"49");
outtextxy(430,270,"50");
outtextxy(70,310,"40");
outtextxy(110,310,"39");
outtextxy(150,310,"38");
outtextxy(190,310,"37");
outtextxy(230,310,"36");
outtextxy(270,310,"35");
outtextxy(310,310,"34");
outtextxy(350,310,"33");
outtextxy(390,310,"32");
outtextxy(430,310,"31");
outtextxy(70,350,"21");
outtextxy(110,350,"22");
outtextxy(150,350,"23");
outtextxy(190,350,"24");
outtextxy(230,350,"25");
outtextxy(270,350,"26");
outtextxy(310,350,"27");
outtextxy(350,350,"28");
outtextxy(390,350,"29");
outtextxy(430,350,"30");
outtextxy(70,390,"20");
outtextxy(110,390,"19");
outtextxy(150,390,"18");
outtextxy(190,390,"17");
outtextxy(230,390,"16");
outtextxy(270,390,"15");
outtextxy(310,390,"14");
outtextxy(350,390,"13");
outtextxy(390,390,"12");
outtextxy(430,390,"11");
outtextxy(70,430,"1");
outtextxy(110,430,"2");
outtextxy(150,430,"3");
outtextxy(190,430,"4");
outtextxy(230,430,"5");
outtextxy(270,430,"6");
outtextxy(310,430,"7");
outtextxy(350,430,"8");
outtextxy(390,430,"9");
outtextxy(430,430,"10");

}
void ladder1()
{
if(i==7)
i=26;
else if(i==71)
i=91;
else if(i==20)
{
i=58;
outtextxy(250,250,"LADDER ACHEIVED");
}
else if(i==40)
i=59;
else if(i==63)
i=81;
}
void snake1()
{
if(i==87)
i=24;
else if(i==54)
i=34;
else if(i==17)
i=6;
else if(i==99)
i=78;
else if(i==62)
i=19;
}
void ladder2()
{
if(j==7)
j=26;
else if(j==71)
j=91;
else if(j==20)
i=58;
else if(j==40)
j=59;
else if(j==63)
j=81;
}
void snake2()
{
if(j==87)
j=24;
else if(j==54)
j=34;
else if(j==17)
j=6;
else if(j==99)
j=78;
else if(j==62)
j=19;
}
