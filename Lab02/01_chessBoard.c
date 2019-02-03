// this app creates a chessboard

#include <stdio.h>

int main(void)
{

    for (int i = 0; i <= 7; i++) //draw 8 lines
    {
        printf("+----+----+----+----+----+----+----+----+\n"); //draw the roof
        int x = 8 - i;
        printf("| a%d | b%d | c%d | d%d | e%d | f%d | f%d | h%d |\n", x, x, x, x, x, x, x, x); //draw the row content
        if (i == 7)
            printf("+----+----+----+----+----+----+----+----+\n"); //after the 8th row, draw a floor
    }

    // extra stuff for windowed IDE
    // getchar()

    return 0;
}
