#include <jni.h>
#include <string>
#include <android/log.h>
#include "Telescope.h"

extern "C"
jstring
Java_si_vajnar_1tech_moonstalker2_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "MoonStalker 2";

    // Create the Telescope
    Telescope *telescope = new Telescope();
    telescope->Calibrate(0, 0);
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, "Telescope created.", 1);

    hello += "\nTelescope ready";

    return env->NewStringUTF(hello.c_str());
}
