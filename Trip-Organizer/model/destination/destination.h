#ifndef TRIPORGANIZER_TRIP_H
#define TRIPORGANIZER_TRIP_H

#include <stdio.h>

#define BCN_LAT 41.3818
#define BCN_LON 2.1685

#define EARTH_RADIUS 6371000.0

typedef struct {
	double lat;
	double lon;
} Coordinates;

typedef struct {
	char * name;
	char * country;

	int area;
	int n;
	double ** travelAltitude;

	int nHotels;
	double * hotelPrices;

	Coordinates location;
} Destination;

double haversine(double ang);
void advanceInDirection(int *i, int *j, int direction);
double checkAltitudeInDirection(double ** travelAltitude, int i, int j, int direction, int n);
double travelThroughAltitude(double ** travelAltitude, int i, int j, int n);
void mapAltitude(double ** travelAltitude, char ** map, int i, int j, int n);
char * readString(FILE * file);
Destination readFromFile(FILE * file);
double getDistanceFromBcn(Destination dest);
double getDistanceBetween(Destination this, Destination that);
double getAverageHotelPrice(Destination dest);
double getTimeFromBcn(Destination dest);
void freeAll(Destination dest);
char ** mapAltitudeTravel(Destination dest);

#endif
