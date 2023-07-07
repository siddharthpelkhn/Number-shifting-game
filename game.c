#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
void gamerule()
{
    system("cls");
    char str[20] = "RULE OF THIS GAME";
    printf("\n                             %s",str);
    printf("\n1.You can only move one step at a time by arrow key");
    printf("\nMove up : by up arrow key");
    printf("\nMove down : by up down key");
    printf("\nMove left : by up left key");
    printf("\nMove right : by up right key");
    printf("\n2.You can move number at empty position only\n");
    printf("\n3.For each valid move : your total number of move will decreased by 1");
    printf("\n4.Winning situation : number in a 4*4 matrix should be in order from 1 to 15\n");
    printf("\n                Winning situation:\n");
    printf("---------------------");
    printf("\n| 1  | 2  | 3  | 4  |");
    printf("\n| 5  | 6  | 7  | 8  |");
    printf("\n| 9  | 10 | 11 | 12 |");
    printf("\n| 13 | 14 | 15 |    |");
    printf("\n---------------------");
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e'");
    printf("\nso Try to win in minimum no of move\n");
    printf("\n            Happy gaming , Good Luck");
    printf("\nEnter any key to start......   ");

    int x =readkey();
}
int winner(int arr[][4])
{
    int i,j,k=1;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; i < 4; j++,k++)
        {
            if(arr[i][j]!=k && k!=16)
            break;
        }
        if(j<4)
        break;
    }
    if(j<4)
    return 0;
    return 1;
}
int shiftup(int arr[][4])
{
    int i,j;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
            break;
        }
        if(j<4)
        break;
    }
    if(i==3)
    return 0;
    swap(&arr[i][j],&arr[i+1][j]);
    return 1;
}
int shiftdown(int arr[][4])
{
    int i,j;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
            break;
        }
        if(j<4)
        break;
    }
    if(i==0)
    return 0;
    swap(&arr[i][j],&arr[i-1][j]);
    return 1;
}
int shiftright(int arr[][4])
{
    int i,j;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
            break;
        }
        if(j<4)
        break;
    }
    if(j==0)
    return 0;
    swap(&arr[i][j],&arr[i][j-1]);
    return 1;
}
int shiftleft(int arr[][4])
{
    int i,j;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if(arr[i][j]==0)
            break;
        }
        if(j<4)
        break;
    }
    if(j==3)
    return 0;
    swap(&arr[i][j],&arr[i][j+1]);
    return 1;
}
int readkey()
{
    char c;
    c = _getch();
    return c;
}
void swap(int *x,int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
void create_matrix(int arr[][4])
{
    int i,j,n=15;
    int num[n];
    for ( i = 0; i < n; i++)
    {
        num[i]=i+1;
    }
    int last_index = n-1;
    srand(time(NULL));
    int index;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if(last_index>=0)
            {
              index = rand()%(last_index+1);
              arr[i][j] = num[index];
              num[index] = num[last_index];
              last_index--;
            }
        }
    }
    arr[i-1][j-1] = 0;
}
void show_matrix(int arr[][4])
{
    int i,j;
    printf("\n--------------------\n");
    for ( i = 0; i < 4; i++)
    {
        printf("|");
        for ( j = 0; j < 4; j++)
        {
            if(arr[i][j]!=0)
            printf("%2d | ",arr[i][j]);
            else
            printf("   | ");
        }
        printf("\n");
    }
    printf("--------------------\n");
}
int main()
{
    int matrix[4][4];
    char str[20];
    int maxtry = 500;
    printf("Enter your name: ");
    gets(str);
    system("cls");
    while (1)
    {
        create_matrix(matrix);
        gamerule();
        system("cls");
        while (!winner(matrix))
        {
            system("cls");
            if(!maxtry)
            break;

            printf("hello %s ,%d moves remaining",str,maxtry);
            show_matrix(matrix);
            int key = readkey();

            switch (key)
            {
            case 101:

            case 69:
               printf("\nthanks for playing!\n");
               printf("press 'enter' to exit the game...");
               key = readkey();
               return 0;
            case 72:
               if(shiftup(matrix))
                maxtry--;
            break;
            case 75:
               if(shiftleft(matrix))
                maxtry--;
            break;
            case 77:
               if(shiftright(matrix))
                maxtry--;
            break;
            case 80:
               if(shiftdown(matrix))
                maxtry--;
            break;
            default:
                printf("\n\n    \a\anot allowed\a\a");
            }
        }
        if(!maxtry)
        printf("                 \nyou lose the game!\n       ");
        else
        printf("        \ncongurlations %s for winning this game\n     ",str);
        fflush(stdin);
        char ch;
        printf( "\nWant to play again ? \n");
        printf("enter 'y' to play again:  ");
        scanf("%c", &ch);
        if ((ch != 'y') && (ch != 'Y'))
            break;

        maxtry = 100;
    }
    return 0;
}
