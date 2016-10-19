/**
 * VajnarTech
 * Moonstalker
 * Control.cpp
 *
 * Purpose: Provides functions for sending control and status messages to telescope.
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#include <string>
#include "Control.h"

Control::Control() {
    bt = new BlueTooth();
}

Control::~Control() {
    delete(bt);
}

// Request message for battery voltage.
void Control::btry() {
    std::string msg = BTRY;
    bt->write(msg);
}

// Request message for telescope status
void Control::st() {
    std::string msg = ST;
    bt->write(msg);
}

// Request message for move the telescope.
void Control::move(double h, double v) {
    char buf[256];
    sprintf(buf, "%s%s%d%s%d", MOVE, D, (int)h, D, (int)v);
    std::string msg = buf;
    bt->write(msg);
}


