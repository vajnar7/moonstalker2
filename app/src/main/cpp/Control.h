/**
 * VajnarTech
 * Moonstalker
 * Control.h
 *
 * Purpose: Provides functions for sending control and status messages to telescope.
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#ifndef MOONSTALKER2_CONTROL_H
#define MOONSTALKER2_CONTROL_H

#include "BlueTooth.h"

// Delimiter
#define D " "

// IN Messages
#define RDY            "RDY"
#define NOT_RDY        "NOT_RDY"
#define FATAL_ERROR    "FATAL_ERROR"
#define BTRY_RESULT    "BTRY"

// OUT Messages
#define MOVE   "MV"
#define ST     "ST?"
#define BTRY   "BTRY?"

class Control {

private:
    BlueTooth *bt;

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
    void move(double h, double v);
};


#endif //MOONSTALKER2_CONTROL_H
