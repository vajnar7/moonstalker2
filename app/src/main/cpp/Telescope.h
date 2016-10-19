/**
 * VajnarTech
 * Moonstalker
 * Telescope.h
 *
 * Purpose: Basic functionality for controlling the Telescope.
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#ifndef MOONSTALKER2_TELESCOPE_H
#define MOONSTALKER2_TELESCOPE_H

#include "Position.h"
#include "Track.h"

// Mechanical characteristics
#define MOTOR_STEPS_NUM      200.0
#define REDUCTOR_TRANSMITION 30.0
#define BELT_TRANSMITION     48.0 / 14.0
#define K  MOTOR_STEPS_NUM * REDUCTOR_TRANSMITION * BELT_TRANSMITION

#define TRSHLD_BTRY 11.0
#define PRECISION   2.0
#define APP_NAME "MoonStalker 2"

class Telescope {
protected:
    Position *position = NULL;
    Track    *tracker = NULL;
    bool     isReady;
    double   bateryVoltage;
    double   hSteps;
    double   vSteps;

public:
    Telescope();
    ~Telescope();

    /**
     * Calibrate the telescope.
     */
    void calibrate(double ra, double dec);

    /**
     * Set new telescope coordinates.
     */
    void newCoordinates(double ra, double dec);

    // Setters & getters
    void setIsReady(bool isReady) {
        Telescope::isReady = isReady;
    }
    void setBateryVoltage(double bateryVoltage) {
        Telescope::bateryVoltage = bateryVoltage;
    }
};

#endif //MOONSTALKER2_TELESCOPE_H
