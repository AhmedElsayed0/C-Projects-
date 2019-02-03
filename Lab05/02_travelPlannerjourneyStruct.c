#include <stdio.h>
#include <stdlib.h>
#include <math.h> // needs DEGREES  converted into RADIANS !!! Google says: 1° × π/180 = 0,01745rad (just google it)
// on Linux you need to COMPILE IN TERMINAL: gcc foo.c -lm -o foo

typedef struct
{
    float lat;
    float lon;
} geoCoord;

const double pi = 3.141592653589793; // because the Math.h library is weird on Linux :P

// PROTOTYPES
void coordinates(int);
void finalTrip(geoCoord coords[], int wayPnum);
int wayPcheck(void);
float coorDcheck(void);
void clearBuff(void);

double distanceCalc(double originLat, double destinationLat, double originLon, double destinationLon);
double deeTOree(double a);

// print UI asking for waypoints
int main(void)
{
    // VIEW
    // enter NUMBER of waypoints (min 2)
    printf("So you want to travel? Cool!\nThen you will need a DEPARTURE location.\nAnd an ARRIVAL location.\nAnd manybe some more STAY locations in between?\n\nPlease input the TOTAL number of locations for your journey: ");

    wayPcheck();
    return 0;
}

int wayPcheck(void)
{
    int wPcheck;

    if (scanf("%d", &wPcheck) && wPcheck > 1) // validate input: isNumber, isEnough
    {
        clearBuff();
        //*TEST*/ printf("___%d___\n", check);
        coordinates(wPcheck);
    }
    else // display error + try again
    {
        printf("ERROR!\nPlease enter a number between 2 and whatever!\n");
        clearBuff();
        //*TEST*/ printf("___%d___\n", check);
        wayPcheck();
    }
}

void coordinates(int wayPnum)
{
    // ▪ Dynamically allocate 1-D arrays to hold the latitudes and the longitudes of the waypoints.

    geoCoord *coords = (geoCoord *)malloc(wayPnum * sizeof(geoCoord));

    if (coords == NULL)
        exit(EXIT_FAILURE);

    // print UI asking for coordinates
    printf("\nLife is pain.\n");
    for (int i = 0; i < wayPnum; i++)
    {
        if (i == 0)
        {
            printf("So please input EXACTLY the coordinates for your Departure location -->\n");
        }
        else if (i == wayPnum - 1)
        {
            printf("Finally, P-LEASE input EXACTLY the coordinates for your Arrival location -->\n");
        }
        else
        {
            printf("An then, please input EXACTLY the coordinates for your #%d Stay location -->\n", i);
        }
        printf("Latitude : ");
        coords[i].lat = coorDcheck();
        printf("Longitide : ");
        coords[i].lon = coorDcheck();
    }

    finalTrip(coords, wayPnum);
}

float coorDcheck(void)
{
    float check;

    if (scanf("%f", &check)) // validate input: isNumber
    {
        clearBuff();
        //*TEST*/ printf("___%f___\n", check);
        check;
    }
    else // display error + try again
    {
        printf("ERROR!\nPlease enter a proper set of coordinates!\n");
        clearBuff();
        //*TEST*/ printf("___%d___\n", check);
        coorDcheck();
    }
}

void finalTrip(geoCoord coords[], int wayPnum)
{
    double tempDistance, totDistance;
    /*TEST
    for (int i = 0; i < wayPnum; i++)
    {
        printf("%f - %f\n", coords[i].lat, coords[i].lon);
    }
*/
    for (int i = 0; i < wayPnum - 1; i++)
    {
        tempDistance = distanceCalc(coords[i].lat, coords[i + 1].lat, coords[i].lon, coords[i + 1].lon);

        //*TEST*/ printf("\nThe distance between point %d and %d is %f km.\n", i, i + 1, tempDistance);

        totDistance = totDistance + tempDistance;
    }

    printf("\n\nThe total walk distance is... you know... %.2f km.\n", totDistance);
}

// CLEAR BUFFER
void clearBuff(void)
{
    while (getchar() != '\n')
        continue;
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
print UI asking for waypoints
enter NUMBER of waypoints (min 2)
validate input: isNumber, isEnough
display error + try again
▪ Dynamically allocate 1-D arrays to hold the latitudes and the longitudes of the waypoints.
print UI asking for coordinates
enter COORDINATES for each waypoint
validate input: isNumber (isCorrect???)
display error + try again
print the TOT distance
▪ Make sure to free dynamically allocated memory before the application exits.
*/