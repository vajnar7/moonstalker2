/**
 * VajnarTech
 * Moonstalker
 * Track.h
 *
 * Purpose: Tracing the Telescope.
 *
 * @author Zoran Robic
 * @version 1.1 10/4/16
 */

#ifndef MOONSTALKER2_TRACK_H
#define MOONSTALKER2_TRACK_H

class Track {
private:
    bool isTracking = false;
    int  timeout; // Tracking precision
    void *telescope;
public:
    Track(int timeout, void *telescope);
    ~Track();

private:
    /**
     * Tracking function.
     */
    void f();
};


#endif //MOONSTALKER2_TRACK_H
