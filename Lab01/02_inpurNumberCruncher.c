// Let's make a BETTER number cruncher app è_é

//include of core library
#include <stdio.h>

//generic main function
int main(void)
{
    //variables declaration
    int one, two;

    //boilerplate text
    printf("Simple Calculator:\n------------------\n");
    printf("Please input 1st operand, then press ENTER:\n");
    scanf("%d", &one);
    printf("Please input 2st operand, then press ENTER:\n");
    scanf("%d", &two);

    //calculations
    printf("%d + %d = %d\n", one, two, one + two);
    printf("%d - %d = %d\n", one, two, one - two);
    printf("%d * %d = %d\n", one, two, one * two);
    printf("%d / %d = %d\n", one, two, one / two);
    printf("%d %% %d = %d\n", one, two, one % two);

    // extra for IDE use
    //getchar();
}