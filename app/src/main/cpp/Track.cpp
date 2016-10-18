/**
 * VajnarTech
 * Moonstalker
 * Track.cpp
 *
 * Purpose: Tracing the Telescope.
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#include "thread"
#include "Track.h"
#include "Telescope.h"
#include <android/log.h>

Track::Track(int timeout, void *telescope) {
    this->timeout = timeout;
    this->telescope = telescope;

    // start thread
    isTracking = true;
    std::thread t1(&Track::f, this);
    t1.join();
}

Track::~Track() {
    isTracking = false;
}

// Tracking function
void Track::f() {
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, "Tracking", 1);
    while(isTracking) {
        ((Telescope*)telescope)->move();
        std::this_thread::sleep_for(std::chrono::seconds(timeout));
    }
}
