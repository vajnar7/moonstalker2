/**
 * VajnarTech
 * Moonstalker
 * BlueTooth.h
 *
 * Purpose: Establish BT (BlueTooth) connection with Arduino module on Telescope.
 *          Sending and processing of BT messages.
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#ifndef MOONSTALKER3_BLUETOOTH_H
#define MOONSTALKER3_BLUETOOTH_H


#include <string>

class BlueTooth {

public:
    BlueTooth();
    ~BlueTooth();

    /**
     * Writes message to open BT connection.
     */
    void write(std::string);

};


#endif //MOONSTALKER3_BLUETOOTH_H
