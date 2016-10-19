/**
 * VajnarTech
 * Moonstalker
 * Position.cpp
 *
 * Purpose: Calculation and transformation of telescope and equatorial coordinates.
 *
 * @author Zoran Robic
 * @version 2.1 10/10/16
 */

#include <math.h>
#include <chrono>

#include "Position.h"
#include "Telescope.h"
#include <android/log.h>

void Coordinates::print() {
    char buf[256];
    sprintf(buf, "ra=%lf\ndec=%lf\naz=%lf\nalt=%lf",
            ra, dec, az, alt);
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, buf, 1);
}

Position::Position(double ra, double dec) {
    c.ra =  ra;
    c.dec = dec;
    c.az = 0.0;
    c.alt = 0.0;
    gps = new GPSService(LONGITUDE, LATITUDE);
    update();
}
Position::~Position() {
    delete (gps);
}

//Update the current position of telescope.
Coordinates &Position::update() {
    Coordinates tmp;

    tmp.az = c.az;
    tmp.alt = c.alt;
    RaDec2AltAz(c);
    c.print();
    tmp.az = c.az - tmp.az;
    tmp.alt = c.alt - tmp.alt;

    //Check for negative alt
    if (c.alt <= ALT_NEGATIVE) {
        hNegative = true;
    } else {
        hNegative = false;
    }

    return tmp;
}

// Transform the astronomical coordinates to telescope one.
void Position::RaDec2AltAz(Coordinates &c) {
    Coordinates tmp;
    long        tmp2;
    double      lat;
    double      lst;
    double      ha;

    tmp.ra =  c.ra * 15;
    tmp.dec = c.dec;
    lat = gps->getLatitude();
    // Siderium time
    lst = getLst();
    tmp2 = long(lst / 360.0);
    lst -= tmp2 * 360.0;
    if (lst < 0.0) lst += 360.0;
    // Hour angle
    ha = lst - tmp.ra;
    if (ha < 0.0) ha += 360.0;
    // Convert to radians
    ha =      toRad(ha);
    tmp.dec = toRad(tmp.dec);
    lat =     toRad(lat);
    // Altitude
    tmp.alt = sin(tmp.dec) * sin(lat) + cos(tmp.dec) * cos(lat) * cos(ha);
    tmp.alt = asin(tmp.alt);
    c.alt = toDeg(tmp.alt);
    // Azimuth
    double b1 = sin(tmp.dec) - sin(tmp.alt) * sin(lat);
    double b2 = cos(tmp.alt) * cos(lat);
    c.az = toDeg(acos(b1 / b2));
    // If sin(ha) is positive, the azimuth angle is 360 - azimuth
    if (sin(ha) > 0.0) c.az = 360.0 - c.az;
}

// Transform the radians to degress
double Position::toDeg(double rad) {
    return (rad*180/PI);
}

// Transform the degrees to radians
double Position::toRad(double deg) {
    return (deg*PI/180);
}

// Returns local siderium time.
double Position::getLst() {
    using namespace std::chrono;
    using namespace std;

    tm y2k = {100, 0, 1, 0, 0, 0, -1}; // 1.1.2000
    auto y2ktp = system_clock::from_time_t(mktime(&y2k));
    auto curTime = system_clock::now();
    auto sec = duration_cast<seconds>(curTime - y2ktp);
    sec /= 86400;
    auto dayTime = 0; //TODO

    double lst = 100.46 +
          0.985647 * sec.count() +
          gps->getLongitude() +
          15.0 * dayTime;

    return (lst);
}
