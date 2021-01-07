/*
 *
 classic tic tak toe
 you can either play against another player or you can chose to play against a bot with 3 difficulties

 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i,j,k,q,x,y,var,w1,w2;
char a[10][10];
void bot1()
{
    srand(time(NULL));
    w1 = rand() % 3 + 1; //gets a random number from 0 to 2 and we add +1 so we get a random number from 1 to 3 ( for the matrix's positions )
    w2 = rand() % 3 + 1;
    w1*=2;
    w2*=2;
    if ( a[w1][w2] == ' ' ) //if the [w1][w2] position is empty we can replace it with '0'
    {
        printf("\n");
        printf("[%d][%d]=0\n", w1, w2);
        a[w1][w2] = '0';
        return;
    }
    else bot1(); //else we repeat the function until an empty position will be replaced with '0'
}

void bot2()
{
    /*find the first possible win for the player X on the row and blocks it. For exemple:
    *************
    * X * X * 0 *
    *************
    *   *   *   *
    *************
    *   *   *   *
    *************

         OR

    *************
    *   *   *   *
    *************
    * X * 0 * X *
    *************
    *   *   *   *
    *************

        */

    for ( i = 2; i <= 6; i+=2)
    { var = 0;
    for ( j = 2; j <= 6; j+=2)
        if( a[i][j] == 'X')
            var++;
        else q = i * 10 + j;
    if ( var == 2 && a[q/10][q%10] == ' ')
        {
            printf("\n");
            printf("[%d][%d]=0\n", q / 10, q % 10);
            a[q/10][q%10] = '0';
            return;
        }
    }
/*find the first possible win for the player X on the column and blocks it. For exemple:
    *************
    *   *   * 0 *
    *************
    *   *   * X *
    *************
    *   *   * X *
    *************

         OR

    *************
    *   * X *   *
    *************
    *   * 0 *   *
    *************
    *   * X *   *
    *************

        */
    for ( j = 2; j <= 6; j+=2)
    { var = 0;
        for ( i = 2; i <= 6; i+=2)
            if (a[i][j] == 'X')
                var++;
            else q = i * 10 + j;
        if (var == 2 && a[q / 10][q % 10] == ' ')
            {
                printf("\n");
                printf("[%d][%d]=0\n", q / 10, q % 10);
                a[q / 10][q % 10] = '0';
                return;
            }
    }

    /*find the first possible win for the player X on the diagonal and blocks it. For exemple:
    *************
    * X *   *   *
    *************
    *   * X *   *
    *************
    *   *   * 0 *
    *************

         OR

    *************
    *   *   * X *
    *************
    *   * 0 *   *
    *************
    * X *   *   *
    *************

    */

    var = 0;
    for ( i = 2; i <= 6; i+=2 )
        if (a[i][i] == 'X')
            var++;
        else q = i;
    if (var == 2 && a[q][q] == ' ')
        {
            printf("\n");
            printf("[%d][%d]=0\n", q, q);
            a[q][q] = '0';
            return;
        }

    var = 0;
    for ( i = 2; i <= 6; i+=2 )
        if (a[8 - i][i] == 'X')
            var++;
        else q = i;
    if (var == 2 && a[q][q] == ' ')
        {
            a[q][q] = '0';
            printf("\n");
            printf("[%d][%d]=0\n", q, q);
            return;
        }
    return bot1();
}

void bot3()
{   /*find the first possible win for the player 0 on the row and takes the win. For exemple:
    *************
    * 0 * 0 * 0 *
    *************
    * X *   * X *
    *************
    *   * X *   *
    *************

         OR

    *************
    *   * X * X *
    *************
    * 0 * 0 * 0 *
    *************
    *   * X *   *
    *************

        */

    for ( i = 2; i <= 6; i+=2)
    { var = 0;
        for ( j = 2; j <= 6; j+=2)
            if( a[i][j] == '0')
                var++;
            else q = i * 10 + j;
        if ( var == 2 && a[q/10][q%10] == ' ')
        {
            a[q/10][q%10] = '0';
            printf("\n");
            printf("[%d][%d]=0\n", q / 10, q % 10);
            return;
        }
    }
/*find the first possible win for the player 0 on the column and takes the win. For exemple:
    *************
    * X *   * 0 *
    *************
    *   * X * 0 *
    *************
    *   * X * 0 *
    *************

         OR

    *************
    * X * 0 * X *
    *************
    *   * 0 *   *
    *************
    *   * 0 * X *
    *************

        */
    for ( j = 2; j <= 6; j+=2)
    { var = 0;
        for ( i = 2; i <= 6; i+=2)
            if( a[i][j] == '0')
                var++;
            else q = i * 10 + j;
        if ( var == 2 && a[q/10][q%10] == ' ')
        {
            a[q/10][q%10] = '0';
            printf("\n");
            printf("[%d][%d]=0\n", q / 10, q % 10);
            return;
        }
    }

    /*find the first possible win for the player 0 on the diagonal and takes the win. For exemple:
    *************
    * 0 * X *   *
    *************
    * X * 0 *   *
    *************
    *   * X * 0 *
    *************

         OR

    *************
    * X * X * 0 *
    *************
    * X * 0 *   *
    *************
    * 0 *   *   *
    *************

    */

    var = 0;
    for (i = 2; i <= 6; i+=2)
        if (a[i][i] == '0')
            var++;
        else q = i;
    if(var == 2 && a[q][q] == ' ')
        {
            a[q][q] = '0';
            printf("\n");
            printf("[%d][%d]=0\n", q, q);
            return;
        }
    var = 0;
    for ( i = 2; i <= 6; i+=2 )
        if( a[8-i][i] == 'X' )
            var++;
        else q = i;
    if ( var == 2 && a[q][q] == ' ')
        {
            a[q][q] = '0';
            printf("\n");
            printf("[%d][%d]=0\n", q, q);
            return;
        }


    return bot2();
}

int main()
{ int difficulty;
printf("Pick a number from 0 to 3: \n 0: two players mode\n 1: bot mode - easy difficulty \n 2: bot mode - medium difficulty \n 3: bot mode - hard difficulty\n");
scanf("%d", &difficulty);
    printf("\n");
    printf("\nYou should pick two numbers without space in between representing \nthe position in the matrix. (example: 11,23,31) \n\n");

    if (difficulty == 0)
    {
        printf("You choose the two players mode\n");
    }else if(difficulty == 1)
    {
        printf("You choose the bot mode - easy difficulty\n");
    }else if(difficulty == 2)
    {
        printf("You choose the bot mode - normal difficulty\n");
    }else
        printf("You choose the bot mode - hard difficulty\n");
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++)
        {
            a[i][j]='*';
            if((i%2==0 && j%2==0)||(i==8 || j==8))
                a[i][j]=' ';
        }
    a[2][8]='1';
    a[4][8]='2';
    a[6][8]='3';
    a[8][2]='1';
    a[8][4]='2';
    a[8][6]='3';
    for(i=1;i<=8;i++)
    { for(j=1;j<=8;j++)

            printf("%c ",a[i][j]);
        printf("\n");
    }
    printf("\n");

    k=0;
    for(k=0;k<9;k++) //the program will stop when k = 9 ( which means that all the spaces are filled with X and 0 ) or when a player will win.
    { /* you can chose from 9 positions ( 11,12,13,21,22,23,31,32,33 ) from a 3x3 matrix */
        if (k % 2 == 0) { //if k is an even number it is player's X turn
            printf("player X:");
            scanf("%d", &q);
            printf("\n");
            printf("[%d][%d]=X \n",q/10,q%10);
            if(a[(q / 10) * 2][(q % 10) * 2]==' ' && (q/10*2<=8 || q%10*2<=8)) //if there is an empty space you can chose it, if you chose a space that is not empty you can chose again
                a[((q / 10) % 10) * 2][(q % 10) * 2]='X';
            else {
                printf("Pick an empty space \n");
                k--;
                 }
            }else { //if k is an odd number it is player's 0 turn
            printf("player 0:");
            if (difficulty == 0) {
                scanf("%d", &q);
                printf("\n");
                printf("[%d][%d]=0\n", q / 10, q % 10);
                if (a[((q / 10) % 10) * 2][(q % 10) * 2] == ' ')
                    a[((q / 10) % 10) * 2][(q % 10) * 2] = '0';
                else {
                    printf("Pick an empty space \n");
                    k--;
                }
            }
            else if ( difficulty == 1 )
            {
                bot1();
            printf("\n");
            }else if ( difficulty == 2 )

            {
                    bot2();
                printf("\n");
            }else
            {
                        bot3();
                printf("\n");
            }
        }

        for(x=1;x<=8;x++)
        { for(y=1;y<=8;y++)

                printf("%c ",a[x][y]);
            printf("\n");
        }

        if ((a[2][2] == a[4][4] && a[2][2] == a[6][6] && a[2][2] !=' ') || (a[2][6] == a[4][4] && a[2][6] == a[6][2] && a[2][6] !=' ') ||
            (a[2][2] == a[2][4] && a[2][2] == a[2][6] && a[2][2] !=' ') || (a[4][2] == a[4][4] && a[4][2] == a[4][6] && a[4][2] !=' ') ||
            (a[6][2] == a[6][4] && a[6][2] == a[6][6] && a[6][2] !=' ') || (a[2][2] == a[4][2] && a[2][2] == a[6][2] && a[2][2] !=' ') ||
            (a[2][4] == a[4][4] && a[6][4] == a[2][4] && a[2][4] !=' ') || (a[2][6] == a[4][6] && a[4][6] == a[6][6] && a[2][6] !=' ') )
            break;

    }
    if(k<9)
    {
        if(k%2==0)
            printf("player X won the game");
        else printf("player 0 won the game");
    }else  printf("DRAW");

    return 0;
}
