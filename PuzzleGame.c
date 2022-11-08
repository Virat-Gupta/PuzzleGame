#include <stdio.h>
#include <windows.h>

#define NULL 0
int game[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,NULL,15}};
int winarr[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,NULL} };

void show();
void play();

int win();

void up();
void down();
void left();
void right();

void detectnull();


int currrow, currcolumn;
int main()
{
	printf("Instructions:\n");
	printf("1.<W> for Up\n");
	printf("2.<S> for Down\n ");
	printf("3.<A> for Left\n");
	printf("4.<D> for Right\n");
	printf("5.<Q> to Quit.\n");

	show();
	printf("Lets Start!!!\n");
	play();


	return 0;
}


//print the array
void show()
{
	for (int i=0;i<=3;i++)
	{
		for (int j=0;j<=3;j++)
		{
			printf("%d\t",game[i][j]);
		}
		printf("\n");
	}
}

//Game Controls
void play()
{
	if (win() == 1)
	{
		printf("You win!!!!");
		return;
	}
	else
	{
		char choice;
		printf("Enter here :");
		scanf("%c", &choice);
		if (choice == 'W' || choice == 'w') up();
		else if (choice == 'S' || choice == 's') down();
		else if (choice == 'A' || choice == 'a') left();
		else if (choice == 'D' || choice == 'd') right();
		else if (choice == 'Q' || choice == 'q') return;
		play();
	}
}

void detectnull ()
{
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (game[i][j] == NULL)
			{
				currrow = i;
				currcolumn = j;
			}
			else;
		}
	}
	return;
}

void up()
{
	detectnull();
	printf("\n%d\t%d\n", currrow, currcolumn);
	if (currrow == 3) printf("Not possible\n");
	else
	{
		game[currrow][currcolumn] = game[currrow + 1][currcolumn];
		game[currrow+1][currcolumn] = 0;
		show();
	}
	return;
}

void down()
{
	detectnull();
	printf("\n%d\t%d\n", currrow, currcolumn);
	if (currrow == 0) printf("Not possible\n");
	else
	{
		game[currrow][currcolumn] = game[currrow - 1][currcolumn];
		game[currrow-1][currcolumn] = 0;
		show();
	}
	return;
}

void left()
{
	detectnull();
	printf("\n%d\t%d\n", currrow, currcolumn);
	if (currcolumn == 3) printf("Not possible\n") ;
	else
	{
		game[currrow][currcolumn] = game[currrow][currcolumn+1];
		game[currrow][currcolumn+1] = 0;
		show();
	}
	return;
}

void right()
{
	detectnull();
	printf("\n%d\t%d\n", currrow, currcolumn);
	if (currrow == 0) printf("Not possible\n") ;
	else
	{
		game[currrow][currcolumn] = game[currrow][currcolumn-1];
		game[currrow][currcolumn-1] = 0;
		show();
	}
	return;
}

int win()
{
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (game[i][j] != winarr[i][j]) return 0;
		}
	}
	return 1;
}
