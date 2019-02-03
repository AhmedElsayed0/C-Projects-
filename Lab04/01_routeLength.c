/*
 Write a function to determine the distance of a route in km.
 
 Re-use the function distanceKm() from lab 3. Do not modify that function.
 
 Use two arrays, one to hold the latitudes and one to hold the longitudes of the waypoints.
 
 File IE-B1-SOL1_04_GeoRoute.txt contains the geographic coordinates.
 */

#include <stdio.h>
#include <math.h> // needs DEGREES  converted into RADIANS !!! Google says: 1° × π/180 = 0,01745rad (just google it)
// on Linux you need to COMPILE IN TERMINAL: gcc foo.c -lm -o foo

// PROTOTYPES & CONSTANTS
double distanceCalc(double originLat, double destinationLat, double originLon, double destinationLon);
double deeTOree(double a);

const double pi = 3.141592653589793; // because the Math.h library is weird on Linux :P

int main(void)
{
    // ARRAYS & DATA
    float coordinates[9][2] =
        {{53.557029, 10.022918}, 
        {53.557166, 10.021343},
        {53.557274, 10.020297}, 
        {53.560288, 10.014906}, 
        {53.561306, 10.015426}, 
        {53.562015, 10.016568}, 
        {53.558241, 10.023244}, 
        {53.557900, 10.022142}, 
        {53.557203, 10.022632}};

    double tempDistance, totDistance;

    for (int i = 0; i < 8; i++)
    {

        tempDistance = distanceCalc(coordinates[i][0], coordinates[i + 1][0], coordinates[i][1], coordinates[i + 1][1]);

        // TEST CODE
        printf("\nThe distance between point %d and %d is %f km.\n", i, b, tempDistance);

        totDistance = totDistance + tempDistance;
    }

    printf("\n\nThe total walk distance is... you know... %.2f km.\n", totDistance);

    return 0;
}

// DISTANCE CALCULATIONS
double distanceCalc(double originLat, double destinationLat, double originLon, double destinationLon)
{
    return 6378.388 * (acos((sin(deeTOree(originLat)) * sin(deeTOree(destinationLat))) + (cos(deeTOree(originLat)) * cos(deeTOree(destinationLat)) * cos(deeTOree(destinationLon) - deeTOree(originLon)))));
}

double deeTOree(double a)
{
    return a * (pi / 180);
}

/*
Write a function to determine the distance of a route in km.

Re-use the function distanceKm() from lab 3. Do not modify that function.

Use two arrays, one to hold the latitudes and one to hold the longitudes of the waypoints.

File IE-B1-SOL1_04_GeoRoute.txt contains the geographic coordinates.
*/

/*
TWO ARRAY VERSION
    double latitude[8] = {53.557078, 48.858363, 39.562553, 36.156214, -22.971177, 21.281004, -28.002695, 0};
    double longitude[8] = {10.023109, 2.294481, 2.661947, -115.148736, -43.182543, -157.837456, 153.431781, 0};

    double originLat = latitude[pickOne];
    double destinationLat = latitude[pickTwo];
    double originLon = longitude[pickOne];
    double destinationLon = longitude[pickTwo];
*/
