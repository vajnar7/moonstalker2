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
    bool isReady;
    bool isCalibrated;
    double hSteps;
    double vSteps;
    double bateryVoltage;
public:
    Telescope();
    ~Telescope();

    /**
     * Update telescope position.
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
     */
    void calibrate(double ra, double dec);

    /**
     * Set new telescope coordinates.
     */
    void newCoordinates(double ra, double dec);

    // Getters and setters
    void setIsReady(bool isReady) {
        Telescope::isReady = isReady;
    }
    bool isIsReady() const {
        return isReady;
    }

    void setBateryVoltage(double bateryVoltage) {
        Telescope::bateryVoltage = bateryVoltage;
    }
};

#endif //MOONSTALKER2_TELESCOPE_H
