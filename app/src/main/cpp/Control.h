/**
 * VajnarTech
 * Moonstalker
 * Control.h
 *
 * Purpose: Provides position control functionality.
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#ifndef MOONSTALKER2_CONTROL_H
#define MOONSTALKER2_CONTROL_H

#include "BlueTooth.h"

// Delimiter
#define D " "

// OUT Messages
#define MOVE   "MV"
#define ST     "ST?"
#define BTRY   "BTRY?"

#define TRACKING_PERIOD 2 //2s

class Control: public BlueTooth {
public:
    Control();
    ~Control();

    /**
     * Request for battery voltage.
     */
    void btry();

    /**
     * Request for telescope status.
     */
    void st();

    /**
     * Request for move telescope.
     *
     * @param h The number of steps in horizontal direction (altitude).
     * @param v The number of steps in vertical direction (azimuth).
     */
    void mv(double h, double v);

    /**
     * Internal function for move the telescope
     */
    void move();

    /**
     * Internal function for track the telescope.
     */
    void track(bool status);
};


#endif //MOONSTALKER2_CONTROL_H
