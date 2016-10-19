/**
 * VajnarTech
 * Moonstalker
 * Track.cpp
 *
 * Purpose: Tracking the Telescope.
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#include "thread"
#include "Track.h"
#include "Telescope.h"
#include "Control.h"
#include <android/log.h>

Track::Track(int timeout, void *ctrl) {
    this->timeout = timeout;
    this->ctrl = ctrl;

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
        ((Control*)ctrl)->move();
        std::this_thread::sleep_for(std::chrono::seconds(timeout));
    }
}
