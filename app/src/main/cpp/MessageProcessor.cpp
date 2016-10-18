/**
 * VajnarTech
 * Moonstalker
 * MessageProcessor.cpp
 *
 * Purpose: Processing of messages received from BT
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#include "MessageProcessor.h"
#include "Telescope.h"
#include <android/log.h>
#include <thread>

MessageProcessor::MessageProcessor(std::vector<std::string> &msg) {
    std::vector<std::string>::iterator it = msg.begin();
    std::string opcode = *it;
    it++;

    if (opcode == BTRY_RESULT) btry(it);
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, opcode.c_str(), 1);
}

MessageProcessor::~MessageProcessor() {

}

void MessageProcessor::btry(std::vector<std::string>::iterator &params) {
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, "Bebc", 1);
}

void MessageProcessor::notRdy(std::vector<std::string>::iterator &params) {

}