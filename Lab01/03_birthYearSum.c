// Birth Year digit sum app, because we can >_>

//include of core C library
#include <stdio.h>

//generic main function
int main(void)
{
    //variables declaration
    int one, two, three, four;

    //instruction text
    printf("\nPlease enter your YEAR of birth, then press ENTER: ");

    /*
    gechar() takes the keystroke input and expresses it as the number ASSOCIATED WITH the input
    character so for example a=97 and 0=48 and 1=49 etc
    */
    one = getchar() - 48; //instead use -"0"
    two = getchar() - 48;
    three = getchar() - 48;
    four = getchar() - 48;

    // scanf() requires an ENTER after every number; not good :P

    printf("The sum of your B-Year digits is %d ... ain't that funny? :D\n\n", one + two + three + four);

    /*
    the following two getchar() are superfluous in a terminal, but if running the code in a window
    they prevent the program from immediately closing
    */

    //    getchar();
    //    getchar();
    return 0;
}