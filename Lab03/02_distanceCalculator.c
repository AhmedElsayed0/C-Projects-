#include <stdio.h>
#include <math.h> // needs DEGREES  converted into RADIANS !!! Google says: 1° × π/180 = 0,01745rad (just google it)
// on Linux you need to COMPILE IN TERMINAL: gcc foo.c -lm -o foo

int main(void);
double distanceOne(double yLat1, double yLat2, double xLon1, double xLon2);
double distanceTwo(double yLat1, double yLat2, double xLon1, double xLon2);
double deeTOree(double a);
//double reeTOdee(double a);

const double pi = 3.141592653589793; // because the Math.h library is weird on Linux :P

char *location[8] = {"HAW Hamburg", "Eiffel Tower", "Palma de Mallorca", "Las Vegas", "Copacabana", "Waikiki Beach", "Surfer's Paradise", "MbutoLandia"}; //by declaring the array as a pointer I can use full strings as the content of the array value

float coordinates[8][2] =
    {{53.557078, 10.023109}, {48.858363, 2.294481}, {39.562553, 2.661947}, {36.156214, -115.148736}, {-22.971177, -43.182543}, {21.281004, -157.837456}, {-28.002695, 153.431781}, {0, 0}};

int main(void)
{
    int pickOne, pickTwo;
    double yLat1, xLon1, yLat2, xLon2;

    printf("Would you like to know the distance between two cities? Sure you do!\nJust pick the first one...\n");

    for (int i = 0; i < 8; i++)
    {
        printf("[%d] %s \n", i, location[i]);
    }

    scanf("%d", &pickOne);
    getchar();

    printf("...and now pick a second city. Any city...\n");

    for (int i = 0; i < 8; i++)
    {
        printf("[%d] %s \n", i, location[i]);
    }
    scanf("%d", &pickTwo);
    getchar();

    yLat1 = coordinates[pickOne][0];
    yLat2 = coordinates[pickTwo][0];
    xLon1 = coordinates[pickOne][1];
    xLon2 = coordinates[pickTwo][1];

    printf("Well, the distance between %s and %s is %f km, although some would argue it is actually %f km.\n\n", location[*&pickOne], location[*&pickTwo], distanceOne(yLat1, yLat2, xLon1, xLon2), distanceTwo(yLat1, yLat2, xLon1, xLon2));

    return 0;
}

double distanceOne(double yLat1, double yLat2, double xLon1, double xLon2)
{
    double dY = 111.3 * fabs(yLat1 - yLat2);                                                // delta latitude
    double dX = 111.3 * cos((deeTOree(yLat1) + deeTOree(yLat2)) / 2) * fabs(xLon1 - xLon2); // delta longitude
    return sqrt(pow(dX, 2) + pow(dY, 2));
}

double distanceTwo(double yLat1, double yLat2, double xLon1, double xLon2)
{
    return 6378.388 * (acos((sin(deeTOree(yLat1)) * sin(deeTOree(yLat2))) + (cos(deeTOree(yLat1)) * cos(deeTOree(yLat2)) * cos(deeTOree(xLon2) - deeTOree(xLon1)))));
}

double deeTOree(double a)
{
    return a * (pi / 180);
}



/*
Implement a function localDistanceKm() that returns the distance in km between two geographic locations calculated according to Section 2.2.
// find distance between POINTS a and b
// a POINT is Lat/Lon
// both are Floats (which length?)
// calculate DX
// take lat1 and lat2
// calculate DY
// calculate DISTANCE using the DX DY formula

Implement a function distanceKm() that returns the distance in km between two geographic locations calculated according to Section 2.3.

Verify that the functions return the correct distances between the HAW Hamburg and the Eiffel Tower as given in the table below.
Determine the distances to the HAW Hamburg missing in the table below.
*/
