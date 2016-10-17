/**
 * VajnarTech
 * Moonstalker
 * Position.h
 *
 * Purpose: Calculation and transformation of telescope and astronomical coordinates.
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#ifndef MS_CPOSITION_H
#define MS_CPOSITION_H

#include <cwchar>
#include "GPSService.h"

#define ALT_NEGATIVE  0

class Coordinates {
public:
    double ra =  0.0; //right accesion
    double dec = 0.0; //declination
    double az =  0.0; //azimuth
    double alt = 0.0; //altitude

    void print();
};

class Position {
public:
    const double PI = 3.14159;
private:
    Coordinates c;
    GPSService *gps = NULL;
    bool hNegative =  false;

public:
    Position (double ra, double dec);
    ~Position();

    const Coordinates &getC() const {
        return c;
    }
    void setC(const Coordinates &c) {
        Position::c = c;
    }

    bool isHNegative() const {
        return hNegative;
    }

    /**
     * Update the current position of telescope.
     *
     * @return The difference of az and alt between 2 calls of update.
     */
    Coordinates &update();

private:
    /**
     * Transform the astronomical coordinates to telescope one
     *
     * @param c The coordinates to transform.
     */
    void RaDec2AltAz(Coordinates &c);
    /**
    * Transform the radians to degress
    *
    * @param rad Radian value.
    * @return Degrees value.
    */
    double toDeg(double rad);
    /**
    * Transform the degrees to radians
    *
    * @param deg Degrees value.
    * @return Radians value.
    */
    double toRad(double deg);
    /**
    * Returns local siderium time.
    *
    * @return Local siderium time.
    */
    double getLst();
};


#endif //MS_CPOSITION_H
