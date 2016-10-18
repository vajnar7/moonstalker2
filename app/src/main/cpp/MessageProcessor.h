/**
 * VajnarTech
 * Moonstalker
 * MessageProcessor.h
 *
 * Purpose: Processing of messages received from BT
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */


#ifndef MOONSTALKER2_MESSAGEPROCESSOR_H
#define MOONSTALKER2_MESSAGEPROCESSOR_H


#include <string>
#include <vector>

class MessageProcessor {
public:
    MessageProcessor(std::vector <std::string> &msg);
    ~MessageProcessor();

private:
    void btry  (std::vector<std::string>::iterator &params);
    void notRdy(std::vector<std::string>::iterator &params);
};


#endif //MOONSTALKER2_MESSAGEPROCESSOR_H
