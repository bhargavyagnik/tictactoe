#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
void PlayWith(int pno,char & opt1, char & opt2)
{
	char ch;

	do
	{
		cout << "\nPlayer " << pno << ": Enter your choice 'X' or 'O' : ";
		cin >> ch;
		if(ch=='X' || ch=='O')
			break;
	}while(1);
	if (pno==1 && ch=='O')
		opt1=ch;
	else if(pno==1 && ch=='X')
		opt2='O';
	else if(pno==2 && ch=='O')
		opt2=ch;
	else
		opt1='O';
}
int CheckWin(char grid[][3])
{
	for(int i=0;i<3;i++)
	{
		if(grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2])
			return 1;
		if(grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i])
			return 1;
	}
	if (grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])
		return 1;
	if (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
		return 1;
	return 0;
}
/*
void Board(char grid [][3])
{
  // request auto detection
   int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom;

   // initialize graphics and local variables
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   // read result of initialization
   errorcode = graphresult();
   if (errorcode != grOk)  // an error occurred
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); // terminate with an error code
   }

   left = getmaxx() / 2 - 90;
   top = getmaxy() / 2 - 90;
   right = getmaxx() / 2 + 90;
   bottom = getmaxy() / 2 + 90;
   cout << left << right << top << bottom;
   // draw a rectangle
   rectangle(left,top,right,bottom);

   rectangle(left,top,right-120,bottom-120);
   rectangle(left+60,top,right-60,bottom-120);
   rectangle(left+120,top,right,bottom-120);
   rectangle(left,top+60,right-120,bottom-60);
   rectangle(left+60,top+60,right-60,bottom-60);
   rectangle(left+120,top+60,right,bottom-60);
   rectangle(left,top+60,right-120,bottom);
   rectangle(left+60,top+60,right-60,bottom);
   rectangle(left+120,top+60,right,bottom);

   for(int i=0,y=12;i<3;i++,y+=4)
   {
	for(int j=0,x=33;j<3;j++,x+=7)
	{
		gotoxy(x,y);
		cout << grid[i][j];
	}
   }
}*/

void Board(char grid [][3])
{

	//clrscr();
   textcolor(GREEN);
   cout<<"\n-------------";
   for(int i=0;i<3;i++)
   {
	cout << "\n|   |   |   |\n";
	for(int j=0;j<3;j++)
	{
		cout << "| " << grid[i][j]<< " ";
	}
	cout << "|\n|   |   |   |";
	cout <<"\n-------------";
   }
}

int main(void)
{
	clrscr();

   char opt1='X',opt2='X',p1[50],p2[50],mark,response;
   int toss,i=1,randnum,player=1,res=0;
   char grid[3][3]={'1','2','3','4','5','6','7','8','9'};
   cout << "Player1 Name: ";
   gets(p1);
   cout << "Player2 Name: ";
   gets(p2);

   cout << "Press any key to toss......";
   getch();
   randomize();
   randnum=random(10-0+1)+0;
   cout << randnum;
   if(randnum<=5)
   {
	cout << "\nPlayer1 wins the toss";
	player=1;

   }
   else
   {
	cout << "\nPlayer2 wins the toss";
	player=2;
   }
   PlayWith(player,opt1,opt2);
   cout << "\nPlayer 1 ("<<opt1<<"), Player 2 (" << opt2 << ")";
   do
   {
   clrscr();
   Board(grid);
   gotoxy(1,21);

   cout << "\nPress 1-9 for Square 1 to 9, Press Q to Quit";
   cout << "\nEnter your choice, Player " << player << " : ";
   cin >> response;
   mark=(player==1)?opt1:opt2;
   /*if (response=='Q')
   {

	getch();
	exit(0);
   }*/
   if(response=='1' && grid[0][0]=='1')
	grid[0][0]=mark;
   else if(response=='2' && grid[0][1]=='2')
	grid[0][1]=mark;
   else if(response=='3' && grid[0][2]=='3')
	grid[0][2]=mark;
   else if(response=='4' && grid[1][0]=='4')
	grid[1][0]=mark;
   else if(response=='5' && grid[1][1]=='5')
	grid[1][1]=mark;
   else if(response=='6' && grid[1][2]=='6')
	grid[1][2]=mark;
   else if(response=='7' && grid[2][0]=='7')
	grid[2][0]=mark;
   else if(response=='8' && grid[2][1]=='8')
	grid[2][1]=mark;
   else if(response=='9' && grid[2][2]=='9')
	grid[2][2]=mark;
   else
	continue;
   res=CheckWin(grid);
   i++;
   player=player%2? 2 : 1;
   }while(res!=1 && i<=9 && response!='Q');
   clrscr();
   Board(grid);
   if (i>9)
	cout << "\n\nGame is draw";
   else if (res==1)
	cout << "\n\nCongratulations!!! Player "<< (player%2?2:1) << ", You win....";
   else
	cout << "\n\nPlayer " << (player%2?2:1) << " You Quit!!! Thanks for playing the game.....";
  /* clean up */
   getch();
   closegraph();
   return 0;
}