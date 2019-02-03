/*
 Write a function to determine the distance of a route in km.
 
 Re-use the function distanceKm() from lab 3. Do not modify that function.
 
 Use two arrays, one to hold the latitudes and one to hold the longitudes of the waypoints.
 
 File IE-B1-SOL1_04_GeoRoute.txt contains the geographic coordinates.
 */


#include <stdio.h>
#include <math.h> // trigonometric() need DEGREES converted to RADIANS !!! Google says: 1° × π/180 = 0,01745rad (just google it)
// on Linux you need to COMPILE IN TERMINAL: gcc foo.c -lm -o foo

int main(void);
double distanceCalc(double originLat, double destinationLat, double originLon, double destinationLon);
double deeTOree(double a);

const double pi = 3.141592653589793; // because the Math.h library is weird on Linux :P

char *location[8] = {"HAW Hamburg", "Eiffel Tower", "Palma de Mallorca", "Las Vegas", "Copacabana", "Waikiki Beach", "Surfer's Paradise", "MbutoLandia"};

float coordinates[8][2] =
    {{53.557078, 10.023109}, {48.858363, 2.294481}, {39.562553, 2.661947}, {36.156214, -115.148736}, {-22.971177, -43.182543}, {21.281004, -157.837456}, {-28.002695, 153.431781}, {0, 0}};

int main(void)
{
    int origin, destination, nameOrigin, nameDestination;
    double tempDistance, maxDistance;
    nameOrigin = 0;
    nameDestination = 0;

    for (int ia = 0; ia < 8; ia++)
    {
        // take Origin[i_1]
        double originLat = coordinates[ia][0];
        double originLon = coordinates[ia][1];

        for (int ib = 0; ib < 8; ib++)
        {
            double destinationLat = coordinates[ib][0];
            double destinationLon = coordinates[ib][1];

            // calc Distance to Destination[i_2]
            tempDistance = distanceCalc(originLat, destinationLat, originLon, destinationLon);
            // if Distance is > maxDistance then update

            if (tempDistance > maxDistance)
            {
                maxDistance = tempDistance;
                nameOrigin = ia;
                nameDestination = ib;
            }
            //  printf("[%d] %s to [%d] %s is %f\n", nameOrigin, location[*&nameOrigin], nameDestination, location[*&nameDestination], tempDistance);
        }
    }

    printf("\n%s and %s have the largest distance (%f km).\nYou'd better not walk.\nTake a flight, instead.\n", location[*&nameOrigin], location[*&nameDestination], maxDistance);

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
