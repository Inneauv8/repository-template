#include "Arduino.h"
#include "whistleTrigger.h"
#include "whistle.h"

namespace WhistleTrigger {

    namespace {
        float threshold = 1;

        int mode;
        
        bool previousTrippedState = false;
        bool trippedState = false;

        bool triggered = false;
    }

    void init(bool _threshold, int _mode) {
        threshold = _threshold;
        mode = _mode;
    }

    void update() {
        previousTrippedState = trippedState;
        trippedState = Whistle::getFilteredAdjustedSignalTension() >= threshold;

        if ((mode == CHANGE && isChanging()) || (mode == RISING && isRising()) || (mode == FALLING && isFalling())) {
            triggered = !triggered;
        }
    }
    
    float getThreshold() { return threshold; }
    void setThreshold(int _threshold) { threshold = _threshold; }

    int getMode() { return mode; }
    void setMode(int _mode) { mode = _mode; }

    bool isTriggered() { return triggered; }
    bool isRising() { return !previousTrippedState && trippedState; }
    bool isFalling() { return previousTrippedState && !trippedState; }
    bool isChanging() { return isRising() || isFalling(); }

    void print() {
        Serial.print("Threshold: ");
        Serial.print(getThreshold());
        Serial.print("\t");

        Serial.print("Mode: ");
        Serial.print(getMode());
        Serial.print("\t");

        Serial.print("Triggered: ");
        Serial.println(isTriggered());
    }
}