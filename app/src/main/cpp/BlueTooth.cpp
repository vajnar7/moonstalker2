/**
 * VajnarTech
 * Moonstalker
 * BlueTooth.cpp
 *
 * Purpose: Establish BT (BlueTooth) connection with Arduino module on Telescope.
 *          Sending and processing of BT messages.
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#include <thread>
#include "BlueTooth.h"
#include "MessageProcessor.h"
#include <sstream>

BlueTooth::BlueTooth(){
    // Connect to telescope and listen for messages
    std::thread t1(&BlueTooth::listener, this);
    t1.join();
}

BlueTooth::~BlueTooth() {
}

// Writes message to BT connection.
void BlueTooth::write(std::string) {
    //TODO
}

// Listening for the messages from Telescope.
void BlueTooth::listener() {
    //TODO
    while (1) {
        // Get message from BT
        std::string msg = "BTRY 12.9";
        std::vector<std::string> v;
        v = parse(msg, ' ');
        auto a = new MessageProcessor(v);
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

// Parse received message.
std::vector<std::string> BlueTooth::parse(const std::string &msg, char delim) {
    std::stringstream ss(msg);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim))
        elems.push_back(std::move(item));
    return elems;
}