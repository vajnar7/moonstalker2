/**
 * VajnarTech
 * Moonstalker
 * Telescope.cpp
 *
 * Purpose: Basic functionality for controlling the Telescope.
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#include "Telescope.h"
#include <assert.h>
#include <android/log.h>

Telescope::Telescope(){
    hSteps =        0;
    vSteps =        0;
    isReady =       false;
    bateryVoltage = 0.0;
}

Telescope::~Telescope() {
    delete(position);
}

// Calibrate the telescope.
void Telescope::calibrate(double ra, double dec) {
    position = new Position(ra, dec);
    assert(position && "Position is NULL.");
    isReady = true;
}

// Set new telescope coordinates.
void Telescope::newCoordinates(double ra, double dec) {
    if(!position) {
        __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, "Telescope not calibrated", 1);
        return;
    }
    Coordinates c = position->getC();
    c.ra = ra;
    c.dec = dec;
    position->setC(c);
}