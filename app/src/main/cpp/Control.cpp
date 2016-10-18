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
    bt->write(sendMessage(BTRY, "", ""));
}

// Request message for telescope status
void Control::st() {
    bt->write(sendMessage(ST, "", ""));
}

// Request message for move the telescope.
void Control::move(double h, double v) {
    bt->write(sendMessage(MOVE, (int)h, (int)v));
}
// Create message
template <typename T, typename U, typename  V>
std::string Control::sendMessage(T p1, U p2, V p3) {
    //return(SM + p1 + " " + p2 + "," + p3 + EM);
    return(SM);
}


