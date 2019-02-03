// this app counts grains of rice on a chessboard

#include <stdio.h>

int main(void)
{
    printf("\nField | On field | Sum\n");
    printf("------+----------+---------------------\n"); //draw the separator row

    //unsigned short x = 1; 16 bit
    //unsigned x = 1;       32 bit
    unsigned long x = 1; //64 bit

    for (int i = 1; i < 65; i++) //draw 8 rows
    {
        printf("%5d | %8lu | %8lu (= %.1Le)\n", i, x, x * 2 - 1, (long double)x * 2 - 1); //number line
        x = x * 2;

        if (i % 8 == 0)
        {
            printf("------+----------+---------------------\n"); //draw the separator row
        }
        if (i == 64)
        {
            int weight = (x * 2 - 1) * 55 / 10e09;
            printf("\nThe total number of rice grains is %lu and their weight is %dt ... this is %d million tonnes!!! x_x\n", x * 2 - 1, weight, weight / 1000000);
            printf("It's kind of a bit more than the 2015 worldwide production of 735.8 million tonnes :P\n\n");
        }
    }

    // extra stuff for windowed IDE
    // getchar()

    return 0;
}
