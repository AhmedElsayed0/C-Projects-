#include <stdio.h> // boilrtplate code

int main(void)
{
    char *location[8] = {"HAW Hamburg", "Eiffel Tower", "Palma de Mallorca", "Las Vegas", "Copacabana", "Waikiki Beach", "Surfer's Paradise", "MbutoLandia"}; //by declaring the array as a pointer I can use full strings as the content of the array value

    int longitude[8] = {53, 48, 39, 36, -22, 21, -28, 0};

    printf("Did you know?\n");

    for (int i = 0; i < 8; i++)
    {
        if (longitude[i] >= 1)
            printf("%s is in the Northern hemisphere.\n", location[i]);
        else if (longitude[i] <= -1)
            printf("%s is in the Southern hemisphere.\n", location[i]);
        else
            printf("%s is in the Equatorial belt.\n", location[i]);
    }

    return 0;
}

// each location is defined by one variable: name = Location, type = float (longitude)

// print - Did you know?\n
// print - LOCATION is in the +
// LOCATION is an array of names [0=HAW, 1=Eiffel, etc]
// LON is an array of longitudes [0=53] ...just Ints, as I don't need the exact value

// for loop to cycle through it all
// if LON >= 1 then +"is North\n"
// else if LON <= -1 then +"is South\n"
// else +"is Equator\n"
// print - this is correct because the isNorthernHemisphere() function says so
// print
// print - and the isSouthernHemisphere() agrees that
// print

/*
HAW Hamburg 53.557078 10.023109
Eiffel Tower 48.858363 2.294481
Palma de Mallorca 39.562553 2.661947
Las Vegas 36.156214 -115.148736
Copacabana -22.971177 -43.182543
Waikiki Beach 21.281004 -157.837456
Surfer’s Paradise -28.002695 153.431781
MbutoLandia 0 0
*/