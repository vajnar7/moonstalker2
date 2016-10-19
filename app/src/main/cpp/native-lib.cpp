#include <jni.h>
#include <string>
#include "Control.h"

extern "C"
jstring
Java_si_vajnar_1tech_moonstalker2_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    std::string hello = "MoonStalker 2";
    hello += "\nTelescope ready";

    Control *control = new Control();
    control->calibrate(0.0, 0.0);
    control->track(true);
    control->track(false);

    control->newCoordinates(18.45, 60.0);
    control->move();

    return env->NewStringUTF(hello.c_str());
}
