/**
 * VajnarTech
 * Moonstalker
 * BlueTooth.cpp
 *
 * Purpose: Establish BT (BlueTooth) connection with Arduino module on Telescope.
 *          Sending and processing of BT messages.
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#include <thread>
#include "BlueTooth.h"
#include "MessageProcessor.h"
#include <sstream>
#include <android/log.h>

BlueTooth::BlueTooth(){
    // Connect to telescope and listen for messages
    std::thread t1(&BlueTooth::listener, this);
    t1.join();
}

BlueTooth::~BlueTooth() {
}

// Writes message to BT connection.
void BlueTooth::write(std::string msg) {
    //TODO: implement from HW LIB
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, msg.c_str(), 1);
}

// Read message from BT connection
std::string BlueTooth::read() {
    //TODO: implement from HW LIB
    std::this_thread::sleep_for(std::chrono::seconds(TIMEOUT));
    //return ("BTRY 5.9");
    return ("FATAL_ERROR belt_transmition_broken");
}

// Listening for the messages from Telescope.
void BlueTooth::listener() {
    bool running = true;
    while (running) {
        // Get message from BT
        std::vector<std::string> v;
        // TODO This will be thread blocking until message is received
        std::string msg = read();
        v = parse(msg, ' ');
        auto a = new MessageProcessor(v, this);
        std::this_thread::sleep_for(std::chrono::seconds(TIMEOUT));
        // Delete processor for current message
        // TODO: Message queue
        if(a) delete(a);
        running = false;
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