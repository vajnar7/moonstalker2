/**
 * VajnarTech
 * Moonstalker
 * Telescope.h
 *
 * Purpose: Basic functionality for controlling the Telescope.
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#ifndef MOONSTALKER2_TELESCOPE_H
#define MOONSTALKER2_TELESCOPE_H

#include "Position.h"
#include "Control.h"
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
private:
    Position *position = NULL;
    Control  *control = NULL;
    Track    *tracker = NULL;
    bool isReady =      false;
    bool batteryOk =    false;
    bool isCalibrated = false;
    double hSteps;
    double vSteps;
    double btryVoltage;
public:
    Telescope();
    ~Telescope();

    /**
     * Telescope move action.
     */
    void move();
    /**
     * Telescope tracking action.
     *
     * @status Start or stop tracking.
     *
     */
    void onTrack(bool status);
    /**
     * Calibrate the telescope.
     *
     */
    void Calibrate(double ra, double dec);

    void setIsReady(bool isReady) {
        Telescope::isReady = isReady;
    }
    bool isIsReady() const {
        return isReady;
    }

    bool isBatteryOk() const {
        return batteryOk;
    }

};

#endif //MOONSTALKER2_TELESCOPE_H
