// Let's make an AWESOME number cruncher app :P

//include of core library
#include <stdio.h>

//generic main function
int main(void)
{
    //variables declaration
    int one = 7, two = 3;

    //boilerplate text
    printf("Simple Calculator:\n------------------\n1st operand:7\n2nd operand:3\n\n");

    //calculations
    printf("%d + %d = %d\n", one, two, one + two);
    printf("%d - %d = %d\n", one, two, one - two);
    printf("%d * %d = %d\n", one, two, one * two);
    printf("%d / %d = %d\n", one, two, one / two);
    printf("%d %% %d = %d\n", one, two, one % two);
}