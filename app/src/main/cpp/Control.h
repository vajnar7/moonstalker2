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

// Delimiters
#define SM "<"
#define EM ">"

// IN Messages
#define RDY            "RDY"
#define NOT_RDY        "NOT_RDY"
#define BTRY_LOW       "BTRY_LOW"
#define FATAL_ERROR    "FATAL_ERROR"
#define BTRY_RESULT    "BTRY"

// OUT Messages
#define MOVE   "MV"
#define ST     "ST?"
#define BTRY   "BTRY?"

class Control {

private:
    BlueTooth *bt;
    std::string message;

public:
    Control();
    ~Control();

    /**
     * Request message for battery voltage.
     */
    void btry();
    /**
     * Request message for telescope status.
     */
    void st();
    /**
     * Request message for move the telescope.
     *
     * @param h The number of steps in horizontal direction (altitude).
     * @param v The number of steps in vertical direction (azimuth).
     */
    void move(double h, double v);

private:
    /**
     * Create message.
     *
     * @param p1 First parameter usualy message mnemonic
     * @param p2 Second parameter
     * @param p3 Third parameter
     *
     * @return Composed message.
     */
    template <typename T, typename U, typename V>
    std::string sendMessage(T p1, U p2, V p3);
};


#endif //MOONSTALKER2_CONTROL_H
