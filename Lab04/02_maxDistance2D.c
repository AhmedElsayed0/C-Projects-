/*
 Write a function to determine the distance of a route in km.
 
 Re-use the function distanceKm() from lab 3. Do not modify that function.
 
 Use two arrays, one to hold the latitudes and one to hold the longitudes of the waypoints.
 
 File IE-B1-SOL1_04_GeoRoute.txt contains the geographic coordinates.
 */

#include <stdio.h>
#include <math.h> // trigonometric() need DEGREES converted to RADIANS !!! Google says: 1° × π/180 = 0,01745rad (just google it)
// on Linux you need to COMPILE IN TERMINAL: gcc foo.c -lm -o foo

// PROTOTYPES
double max(double coordinates[][2], int *origin, int *destination);

double distanceCalc(double originLat, double destinationLat, double originLon, double destinationLon);
double deeTOree(double a);

const double pi = 3.141592653589793; // because the Math.h library is weird on Linux :P

// MAIN --> print the stuff
int main(void)
{
    // ARRAYS & DATA
    const char *location[8] = {"HAW Hamburg", "Eiffel Tower", "Palma de Mallorca", "Las Vegas", "Copacabana", "Waikiki Beach", "Surfer's Paradise", "MbutoLandia"};

    double coordinates[8][2] =
        {{53.557078, 10.023109}, {48.858363, 2.294481}, {39.562553, 2.661947}, {36.156214, -115.148736}, {-22.971177, -43.182543}, {21.281004, -157.837456}, {-28.002695, 153.431781}, {0, 0}};

    int origin, destination;
    double maxDistance = max(coordinates, &origin, &destination);

    // THA PRINTING
    printf("\n%s and %s have the largest distance (%.2f km).\nYou'd better not walk.\nTake a flight, instead.\n", location[origin], location[destination], maxDistance);

    printf("----------------------------------------------------\n");
    printf("\tLocation\tLatitude\tLongitude\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%17s\t%f\t%f\n", location[i], coordinates[i][0], coordinates[i][1]);
    }
    printf("----------------------------------------------------\n\n");
    return 0;
}

// COMPARE DISTANCES
double max(double coordinates[][2], int *origin, int *destination)
{
    double maxDistance;

    // ORIGIN POINT
    for (int ia = 0; ia < 7; ia++)
    {
        // DESTINATION POINT
        for (int ib = ia + 1; ib < 8; ib++)
        {
            // CALCULATION
            double tempDistance = distanceCalc(coordinates[ia][0], coordinates[ib][0], coordinates[ia][1], coordinates[ib][1]);

            // COMPARISON
            if (tempDistance > maxDistance)
            {
                maxDistance = tempDistance;
                *origin = ia;
                *destination = ib;
            }
            // TEST CODE
            printf("[%d] to [%d] = %.0f\n", ia, ib, tempDistance);
        }
    }
    return maxDistance;
}

// DISTANCE CALCULATION
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
