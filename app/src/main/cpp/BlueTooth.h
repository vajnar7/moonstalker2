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
#include <vector>

#define TIMEOUT 10

class BlueTooth {

public:
    BlueTooth();
    ~BlueTooth();

    /**
     * Writes message to open BT connection.
     */
    void write(std::string msg);

    /**
     * Read message to open BT connection.
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
