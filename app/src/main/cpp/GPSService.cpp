/**
 * VajnarTech
 * Moonstalker
 * GPSService.cpp
 *
 * Purpose: Calculation and transformation of telescope and equatorial coordinates.
 *
 * @author Zoran Robic
 * @version 2.1 10/10/16
 */

#include "GPSService.h"

GPSService::GPSService(double lon, double lat) {
    longitude = lon;
    latitude = lat;
}

// Retrives Latitude.
double GPSService::getLatitude() {
    return latitude;
}

// Retrives Longitude
double GPSService::getLongitude() {
    return longitude;
}