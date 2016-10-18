/**
 * VajnarTech
 * Moonstalker
 * Telescope.cpp
 *
 * Purpose: Basic functionality for controlling the Telescope.
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#include "Telescope.h"
#include <assert.h>

#include <math.h>

Telescope::Telescope(){
    control = new Control();
    assert(control && "Controll is NULL.");
    hSteps = 0;
    vSteps = 0;

    isCalibrated =  false;
    isReady =       false;
    bateryVoltage = 0;
}

Telescope::~Telescope() {
    delete(control);
    delete(position);
}

// Telescope tracking action.
void Telescope::onTrack(bool status) {
    if(status) {
        tracker = new Track(2, this);
    }
    else {
        delete (tracker);
    }
}

// Update telescope position.
void Telescope::move() {
    int cur_h_steps = 0;
    int cur_v_steps = 0;
    Coordinates diff;

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
                //h.obtainMessage(ALT_POSITIVE_MESSAGE).sendToTarget();
                control->move(cur_h_steps, cur_v_steps);
            } else {
                //h.obtainMessage(BUSY_MESSAGE).sendToTarget()
            }
        }
    }
}

// Calibrate the telescope.
void Telescope::calibrate(double ra, double dec) {
    position = new Position(ra, dec);
    assert(position && "Position is NULL.");
    isCalibrated = true;
    isReady = true;
}

// Set new telescope coordinates.
void Telescope::newCoordinates(double ra, double dec) {
    assert(position && "Position is NULL");
    Coordinates c = position->getC();
    c.ra = ra;
    c.dec = dec;
    position->setC(c);
}