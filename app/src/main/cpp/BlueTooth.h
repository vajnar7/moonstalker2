/**
 * VajnarTech
 * Moonstalker
 * BlueTooth.h
 *
 * Purpose: Establish BT (BlueTooth) connection with Arduino module on Telescope.
 *          Sending and processing of BT messages.
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#ifndef MOONSTALKER3_BLUETOOTH_H
#define MOONSTALKER3_BLUETOOTH_H


#include <string>
#include <vector>
#include "Telescope.h"

#define TIMEOUT 10

class BlueTooth: public Telescope {
public:
    BlueTooth();
    ~BlueTooth();

protected:
    /**
     * Writes message to opened BT connection.
     */
    void write(std::string msg);

    /**
     * Read message to opened BT connection.
     */
    std::string read();

private:
    /**
     * Listening for the messages from Telescope.
     */
    void listener();

    /**
     * Parse received message.
     *
     * @param msg Received ASCII message from the Telescope.
     * @param delim Delimiter.
     *
     * @return Splitted message. Begins with OP code following by parameters
     */
     std::vector<std::string> parse(const std::string &msg, char delim);
};


#endif //MOONSTALKER3_BLUETOOTH_H
