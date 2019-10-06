#include<stdio.h>
#include<stdlib.h>

void board(char a[][3]);
int inp();

char a[3][3]={'#','#','#','#','#','#','#','#','#'};

int main()
{
	printf("*****TiC TaC ToE*****\n\n");
	board(a);
	inp();

return 0;
}

void board(char a1[][3])
{
	int i,j;
	
	for (i=0 ; i<=2 ; i++)
	{
		for (j=0 ; j<=2 ; j++)
		{
			printf("     %c ", a1[i][j]);
		}printf("\n");
	}
}
char check(char a[3][3])
{
	int i  ;
	for (i=0;i<3;i++)
	if (a[i][0]==a[i][1] &&a[i][1]==a[i][2])
	return a[i][0];
	for (i=0;i<3;i++)
	if (a[0][i]==a[1][i] && a[1][i]==a[2][i])
	return a[0][i];
	if (a[0][0]==a[1][1]&&a[1][1]==a[2][2])
	return a[0][0];
	if (a[0][2]==a[1][1] && a[1][1]==a[2][0])
	return a[0][2];
	return '#';
}

int inp()
{
	int i, j, user=1,k=0;
	char ch ;
	for (i=0 ; i<=8 ; i++)
	{
		int n;
		k=0 ;
		printf("Enter user %d choice: ", user);
		scanf("%d", &n);
		{
			if (n>0 && n<=9)
			{	
				switch (user)
				{
					case 1:
						if (n==1)
						{
							if(a[0][0]=='#')
							{
							a[0][0]='X';
							board(a);
							ch = check(a);
							if (ch=='X'){
								printf("PLAYER ONE WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						else if (n==2)
						{
							if(a[0][1]=='#'){
							a[0][1]='X';
							board(a);
							ch = check(a);
							if (ch=='X'){
								printf("PLAYER ONE WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						else if (n==3)
						{
							if(a[0][2]=='#'){
							a[0][2]='X';
							board(a);
							ch = check(a);
							if (ch=='X'){
								printf("PLAYER ONE WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
								
						}
						else if (n==4)
						{
							if(a[1][0]=='#'){
							a[1][0]='X';
							board(a);
							ch = check(a);
							if (ch=='X'){
								printf("PLAYER ONE WIN") ;
								k=2 ;
							}
							}	
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						else if (n==5)
						{
							if(a[1][1]=='#'){
							a[1][1]='X';
							board(a);
							ch = check(a);
							if (ch=='X'){
								printf("PLAYER ONE WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}	
						}
						else if (n==6)
						{
							if(a[1][2]=='#'){
							a[1][2]='X';
							board(a);
							ch = check(a);
							if (ch=='X'){
								printf("PLAYER ONE WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
							
						}
						else if (n==7)
						{
							if(a[2][0]=='#'){
							a[2][0]='X';
							board(a);
							ch = check(a);
							if (ch=='X'){
								printf("PLAYER ONE WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
							
						}
						else if (n==8)
						{
							if(a[2][1]=='#'){
							a[2][1]='X';
							board(a);
							ch = check(a);
							if (ch=='X'){
								printf("PLAYER ONE WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						else if (n==9)
						{
							if(a[2][2]=='#'){
							a[2][2]='X';
							board(a);
							ch = check(a);
							if (ch=='X'){
								printf("PLAYER ONE WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						if (k==0)
						user ++;
						break ;
						case 2:
						if (n==1)
						{
							if(a[0][0]=='#')
							{
							a[0][0]='O';
							board(a);
							ch = check(a);
							if (ch=='O'){
								printf("PLAYER TWO WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
							
						}
						else if (n==2)
						{
							if(a[0][1]=='#'){
							a[0][1]='O';
							board(a);
							ch = check(a);
							if (ch=='O'){
								printf("PLAYER TWO WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						else if (n==3)
						{
							if(a[0][2]=='#'){
							a[0][2]='O';
							board(a);
							ch = check(a);
							if (ch=='0'){
								printf("PLAYER TWO WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
							
						}
						else if (n==4)
						{
							if(a[1][0]=='#'){
							a[1][0]='O';
							board(a);
							ch = check(a);
							if (ch=='O'){
								printf("PLAYER TWO WIN") ;
								k=2 ;
							}
							}	
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}						
						}
						else if (n==5)
						{
							if(a[1][1]=='#'){
							a[1][1]='O';
							board(a);
							ch = check(a);
							if (ch=='O'){
								printf("PLAYER TWO WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						else if (n==6)
						{
							if(a[1][2]=='#'){
							a[1][2]='O';
							board(a);
							ch = check(a);
							if (ch=='O'){
								printf("PLAYER TWO WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						else if (n==7)
						{
							if(a[2][0]=='#'){
							a[2][0]='O';
							board(a);
							ch = check(a);
							if (ch=='O'){
								printf("PLAYER TWO WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						else if (n==8)
						{
							if(a[2][1]=='#'){
							a[2][1]='O';
							board(a);
							ch = check(a);
							if (ch=='O'){
								printf("PLAYER TWO WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						else if (n==9)
						{
							if(a[2][2]=='#'){
							a[2][2]='O';
							board(a);
							ch = check(a);
							if (ch=='O'){
								printf("PLAYER TWO WIN") ;
								k=2 ;
							}
							}
							else {
							printf("INVALID\n");
							k=1; 
							--i ;
							}
						}
						if(k==0)
						user --;
						break ;
				}
			}
			else{
			printf("INVALID\n");
			--i ;
			}
		}	
		if (k==2)
		break ;
	}
	if (k!=2)
	printf("TIE") ;
}
