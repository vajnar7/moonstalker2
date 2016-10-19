/**
 * VajnarTech
 * Moonstalker
 * Track.h
 *
 * Purpose: Tracking the Telescope.
 *
 * @author Zoran Robic
 * @version 2.1 10/4/16
 */

#ifndef MOONSTALKER2_TRACK_H
#define MOONSTALKER2_TRACK_H

class Track {
private:
    bool isTracking = false;
    int  timeout; // Tracking precision
    void *ctrl;
public:
    Track(int timeout, void *ctrl);
    ~Track();

private:
    /**
     * Tracking function.
     */
    void f();
};


#endif //MOONSTALKER2_TRACK_H
