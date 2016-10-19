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
#include <thread>

class MessageProcessor {
private:

    std::thread t;
public:
    MessageProcessor(std::vector <std::string> &msg);
    ~MessageProcessor();

private:
    void btry  (std::vector<std::string>::iterator &it);
    void notRdy(std::vector<std::string>::iterator &it);
    void rdy   (std::vector<std::string>::iterator &it);
    void fatal (std::vector<std::string>::iterator &it);

};


#endif //MOONSTALKER2_MESSAGEPROCESSOR_H
