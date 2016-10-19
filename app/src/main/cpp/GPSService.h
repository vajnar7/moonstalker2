/**
 * VajnarTech
 * Moonstalker
 * GPSService.h
 *
 * Purpose: Calculation and transformation of telescope and astronomical coordinates.
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#ifndef MOONSTALKER2_GPSSERVICE_H
#define MOONSTALKER2_GPSSERVICE_H

#define LONGITUDE 13.82
#define LATITUDE  46.45

class GPSService {

private:
    double longitude;
    double latitude;

public:
    GPSService(double lon, double lat);
    ~GPSService(){}

    /**
     * Retrives Latitude.
     *
     * @return Latitude.
     */
    double getLatitude();

    /**
    * Retrives Longitude.
    *
    * @return Longitude.
    */
    double getLongitude();
};


#endif //MOONSTALKER2_GPSSERVICE_H
