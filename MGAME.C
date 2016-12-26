/*
	@author : varun

	github : /varunzxzx
*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"string.h"
#define BOUNDARY set_boundary();\
		 sub_boundary();\
		 sub1_boundary();
#define L1AGAIN increase_speed();\
		BOUNDARY;\
		l1.delay_time-=100;\
		for(i=0;i<char_length;i++)\
		{\
			gotoxy(l1.xaxis[i],10);\
			printf("%c",l1.alpha[i]);\
		}\
		delay(700);\
		gotoxy(28,18);\
		printf("Press any key to start..."); \
		getch();\
		gotoxy(28,18);\
		printf("                         ");
#define L2AGAIN increase_speed();\
		BOUNDARY;\
		l2.delay_time-=100;\
		for(i=0;i<char_length;i++)\
		{\
			gotoxy(l2.xaxis[i],10);\
			printf("%c",l2.alpha[i]);\
		}\
		delay(700);\
		gotoxy(28,18);\
		printf("Press any key to start..."); \
		getch();\
		gotoxy(28,18);\
		printf("                         ");
#define L3AGAIN increase_speed();\
		BOUNDARY;\
		l3.delay_time-=100;\
		for(i=0;i<char_length;i++)\
		{\
			gotoxy(l3.xaxis[i],10);\
			printf("%c",l3.alpha[i]);\
		}\
		delay(700);\
		gotoxy(28,18);\
		printf("Press any key to start..."); \
		getch();\
		gotoxy(28,18);\
		printf("                         ");
int tmp[10],lives_left=5,level_count=1;
struct level1{
		char alpha[10];
		int xaxis[10];
		int yaxis[10];
		int delay_time;
		}l1={
			{"ABCDE"},
			{28,34,40,46,52,58,64,70,76,82},
			{10,10,10,10,10,10,10,10,10,10},
			{450}
		     };
struct level2{
		char alpha[10];
		int xaxis[10];
		int yaxis[10];
		int delay_time;
		}l2={
			{"ABCDEF"},
			{25,31,37,43,49,55,61,67,73,79},
			{10,10,10,10,10,10,10,10,10,10},
			{440}
		     };
struct level3{
		char alpha[10];
		int xaxis[10];
		int yaxis[10];
		int delay_time;
		}l3={
			{"ABCDEFG"},
			{22,28,34,40,46,52,58,64,70,76},
			{10,10,10,10,10,10,10,10,10,10},
			{430}
		     };
int level1();
int level2();
int level3();
int promoted(int);
int move(struct level1 *,int);
int get(struct level1 *,int);
int check(int);
char getkey();
void increase_speed();
void set_boundary()
{
	int i;
	clrscr();
	for(i=0;i<79;i++)
	{
		gotoxy(i,1);
		printf("*");
	}
	for(i=0;i<26;i++)
	{
		gotoxy(1,i);
		printf("*");
	}
	for(i=0;i<79;i++)
	{
		gotoxy(i,25);
		printf("*");
	}
	for(i=0;i<26;i++)
	{
		gotoxy(79,i);
		printf("*");
	}
}
void sub_boundary()
{
	int i;
	for(i=3;i<78;i++)
	{
		gotoxy(i,5);
		printf("_");
	}
	for(i=6;i<14;i++)
	{
		gotoxy(3,i);
		printf("!");
	}
	for(i=6;i<14;i++)
	{
		gotoxy(77,i);
		printf("!");
	}
	for(i=3;i<78;i++)
	{
		gotoxy(i,13);
		printf("_");
	}
	gotoxy(3,14);
	printf("/");
	gotoxy(77,14);
	printf("\\");
}
void sub1_boundary()
{
	int i;
	for(i=5;i<76;i++)
	{
		gotoxy(i,17);
		printf("-");
	}
	for(i=5;i<76;i++)
	{
		gotoxy(i,19);
		printf("-");
	}
	gotoxy(5,18);
	printf("|");
	gotoxy(75,18);
	printf("|");
}
int main()
{
	_setcursortype(_NOCURSOR);
	BOUNDARY;
	if(level1()!=0)
		return 1;
	promoted(1);
	if(level2()!=0)
		return 1;
	promoted(2);
	if(level3()!=0)
		return 1;
	promoted(3);
	return 0;
}
int level1()
{
	int i,char_length;
	char_length=strlen(l1.alpha);
	for(i=0;i<char_length;i++)
	{
		gotoxy(l1.xaxis[i],10);
		printf("%c",l1.alpha[i]);
	}
	gotoxy(28,18);
	printf("Press any key to start...");
	getch();
	if(move(&l1,char_length)!=0)
		return 1;
	L1AGAIN;
	if(move(&l1,char_length)!=0)
		return 1;
	L1AGAIN;
	if(move(&l1,char_length)!=0)
		return 1;
	else
	{
		level_count++;
		return 0;
	}
}
int level2()
{
	int i,char_length;
	clrscr();
	BOUNDARY;
	char_length=strlen(l2.alpha);
	for(i=0;i<char_length;i++)
	{
		gotoxy(l2.xaxis[i],10);
		printf("%c",l2.alpha[i]);
	}
	gotoxy(28,18);
	printf("Press any key to start...");
	getch();
	if(move(&l2,char_length)!=0)
		return 1;
	L2AGAIN;
	if(move(&l2,char_length)!=0)
		return 1;
	L2AGAIN;
	if(move(&l2,char_length)!=0)
		return 1;
	else
	{
		level_count++;
		return 0;
	}
}
int level3()
{
	int i,char_length;
	clrscr();
	BOUNDARY;
	char_length=strlen(l3.alpha);
	for(i=0;i<char_length;i++)
	{
		gotoxy(l3.xaxis[i],10);
		printf("%c",l3.alpha[i]);
	}
	gotoxy(28,18);
	printf("Press any key to start...");
	getch();
	if(move(&l3,char_length)!=0)
		return 1;
	L3AGAIN;
	if(move(&l3,char_length)!=0)
		return 1;
	L3AGAIN;
	if(move(&l3,char_length)!=0)
		return 1;
	else
	{
		level_count++;
		return 0;
	}
}
int move(struct level1 *l0,int char_length)
{
	int i,j;
	gotoxy(36,4);
	printf("LEVEL : %d",level_count);
	randomize();
	for(i=0;i<10;i++)
		tmp[i]=56;
	for(j=0;j<char_length;)
	{
		i=rand()%(char_length);
		if(check(i)==0)
		{
			tmp[j]=i;
			j++;
		}
	}
	for(j=0;j<char_length;j++)
	{
		gotoxy(l0->xaxis[tmp[j]],l0->yaxis[tmp[j]]);
		printf(" ");
		gotoxy(l0->xaxis[tmp[j]],l0->yaxis[tmp[j]]-2);
		printf("%c",l0->alpha[tmp[j]]);
		delay(l0->delay_time);
		gotoxy(l0->xaxis[tmp[j]],l0->yaxis[tmp[j]]-2);
		printf(" ");
		gotoxy(l0->xaxis[tmp[j]],l0->yaxis[tmp[j]]);
		printf("%c",l0->alpha[tmp[j]]);
	}
	if(get(l0,char_length)==0)
	{
		return 0;
	}
	else
		return 1;
}
int get(struct level1 *l0,int char_length)
{
	char ch;int j;
	gotoxy(30,22);
	printf("Now,its your turn...");
	gotoxy(22,23);
	printf("NOTE: Ensure that Caps Lock is ON.");
	for(j=0;j<char_length;)
	{
		gotoxy(27,18);
		printf("                                        ");
		gotoxy(33,18);
		printf("Lives Left: %d",lives_left);
		if(lives_left==0)
			break;
		ch=getkey();
		if((ch==l0->alpha[tmp[j]]))
		{
			gotoxy(l0->xaxis[tmp[j]],l0->yaxis[tmp[j]]);
			printf(" ");
			gotoxy(l0->xaxis[tmp[j]],l0->yaxis[tmp[j]]-2);
			printf("%c",l0->alpha[tmp[j]]);
			delay(l0->delay_time);
			gotoxy(l0->xaxis[tmp[j]],l0->yaxis[tmp[j]]-2);
			printf(" ");
			gotoxy(l0->xaxis[tmp[j]],l0->yaxis[tmp[j]]);
			printf("%c",l0->alpha[tmp[j]]);
			j++;
		}
		else
			lives_left--;
	}
	if(lives_left==0)
	{
		gotoxy(20,10);
		printf("                                                      ");
		gotoxy(35,9);
		printf("BAD LUCK :(");
		delay(1000);
		return 1;
	}
	else
	{
		return 0;
	}
}
void increase_speed()
{
		clrscr();
		BOUNDARY;
		gotoxy(32,9);
		printf("LETS DO IT FASTER");
		delay(1300);
		clrscr();
}
int promoted(int level)
{
	clrscr();
	BOUNDARY;
	gotoxy(32,9);
	printf("LEVEL %d COMPLETED",level);
	delay(1350);
	return 0;
}
char getkey()
{
	char ch;
	ch=getch();
	if(ch==NULL)
	{
		ch=getch();
		return ch;
	}
	return ch;
}
int check(int r)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(tmp[i]==r)
			return 1;
	}
	return 0;
}