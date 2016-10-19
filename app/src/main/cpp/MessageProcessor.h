/**
 * VajnarTech
 * Moonstalker
 * MessageProcessor.h
 *
 * Purpose: Processing of messages received from BT
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */


#ifndef MOONSTALKER2_MESSAGEPROCESSOR_H
#define MOONSTALKER2_MESSAGEPROCESSOR_H


#include <string>
#include <vector>
#include <thread>

// IN Messages
#define RDY            "RDY"
#define NOT_RDY        "NOT_RDY"
#define FATAL_ERROR    "FATAL_ERROR"
#define BTRY_RESULT    "BTRY"

class MessageProcessor {
private:
    void* ctrl;
    std::thread t;

public:
    MessageProcessor(std::vector <std::string> &msg, void* ctrl);
    ~MessageProcessor();

    /**
     * Function set for message processing.
     *
     * @param it message parameter list
     */
private:
    void btry  (std::vector<std::string>::iterator &it);
    void notRdy(std::vector<std::string>::iterator &it);
    void rdy   (std::vector<std::string>::iterator &it);
    void fatal (std::vector<std::string>::iterator &it);
};


#endif //MOONSTALKER2_MESSAGEPROCESSOR_H
