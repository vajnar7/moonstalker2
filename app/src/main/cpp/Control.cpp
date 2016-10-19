/**
 * VajnarTech
 * Moonstalker
 * Control.cpp
 *
 * Purpose: Provides position control functionality.
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#include <string>
#include <math.h>
#include "Control.h"
#include <android/log.h>

Control::Control() {
}

Control::~Control() {
}

// Request message for battery voltage.
void Control::btry() {
    std::string msg = BTRY;
    write(msg);
}

// Request message for telescope status
void Control::st() {
    std::string msg = ST;
    write(msg);
}

// Request message for move the telescope.
void Control::mv(double h, double v) {
    char buf[256];
    sprintf(buf, "%s%s%d%s%d", MOVE, D, (int)h, D, (int)v);
    std::string msg = buf;
    write(msg);
}

// Update telescope position.
void Control::move() {
    int cur_h_steps = 0;
    int cur_v_steps = 0;
    Coordinates diff;

    if(!position) {
        __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, "Telescope not calibrated", 1);
        return;
    }
    diff = position->update();
    hSteps += (diff.az * K) / 360.0;
    vSteps += (diff.alt * K) / 360.0;

    if ((fabs(hSteps) >= PRECISION) ||
        (fabs(vSteps) >= PRECISION)) {
        if (isReady) {
            cur_h_steps = (int) hSteps;
            cur_v_steps = (int) vSteps;
            hSteps -= cur_h_steps;
            vSteps -= cur_v_steps;
            //Check for negative height
            if (!position->isHNegative()) {
                mv(cur_h_steps, cur_v_steps);
            } else {
            }
        }
    }
}

// Telescope tracking action.
void Control::track(bool status) {
    if(status) tracker = new Track(TRACKING_PERIOD, this);
    else if(tracker) delete (tracker);
}


