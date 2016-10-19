/**
 * VajnarTech
 * Moonstalker
 * MessageProcessor.cpp
 *
 * Purpose: Processing of messages received from BT
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#include "MessageProcessor.h"
#include "Telescope.h"
#include "Control.h"
#include <android/log.h>
#include <stdlib.h>

MessageProcessor::MessageProcessor(std::vector<std::string> &msg, void* ctrl) {
    this->ctrl = ctrl;
    std::vector<std::string>::iterator it;
    it = msg.begin();
    std::string opcode = *it;
    it++;

    if(opcode == BTRY_RESULT)       btry(it);
    else if (opcode == NOT_RDY)     notRdy(it);
    else if (opcode == RDY)         rdy(it);
    else if (opcode == FATAL_ERROR) fatal(it);
}

MessageProcessor::~MessageProcessor() {
}

// Function set for message processing.
void MessageProcessor::btry(std::vector<std::string>::iterator &it) {
    std::string p1 = *it;
    double num = atof(p1.c_str());
    if (num < TRSHLD_BTRY) {
        ((BlueTooth*)ctrl)->setIsReady(false);
        std::string alert = "Battery low. " + p1;
        __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, alert.c_str(), 1);
    }
    ((BlueTooth*)ctrl)->setBateryVoltage(num);
}

void MessageProcessor::notRdy(std::vector<std::string>::iterator &it) {
    ((BlueTooth*)ctrl)->setIsReady(false);
    std::string alert = "Telescope not ready.";
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, alert.c_str(), 1);
}

void MessageProcessor::rdy(std::vector<std::string>::iterator &it) {
    std::string alert = "Telescope ready.";
    ((BlueTooth*)ctrl)->setIsReady(true);
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, alert.c_str(), 1);
}

void MessageProcessor::fatal(std::vector<std::string>::iterator &it) {
    ((BlueTooth*)ctrl)->setIsReady(false);
    std::string p1 = *it;
    std::string alert = "Fatal error. " + p1;
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, alert.c_str(), 1);
}