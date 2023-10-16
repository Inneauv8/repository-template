#include "Arduino.h"
#include "whistle.h"

namespace Whistle {

    namespace {
        int ambiantPin;
        int signalPin;

        float ambiantTension;
        float signalTension;
        float ambientAdjustedSignalTension;
        
        float filteredAdjustedSignalTension = 0;

        float filterStrength = 0;

        float analogTo5V(int analogValue) { return (float) analogValue * 5.0 / 1023.0; }

        void readAmbiantTension() { ambiantTension = analogTo5V(analogRead(ambiantPin)); }
        void readSignalTension() { signalTension = analogTo5V(analogRead(signalPin)); }

        float applyLowPassFilter(float oldValue, float newValue, float filterStrength) {
            return (1 - filterStrength) * newValue + filterStrength * oldValue;
        }
    }

    void init(int _signalPin, int _ambiantPin, int _filterStrength) {
        filterStrength = _filterStrength;
        
        signalPin = _signalPin;
        ambiantPin = _ambiantPin;

        pinMode(signalPin, INPUT);
        pinMode(ambiantPin, INPUT);
    }

    void update() {
        readAmbiantTension();
        readSignalTension();

        ambientAdjustedSignalTension = signalTension - ambiantTension;
        
        filteredAdjustedSignalTension = applyLowPassFilter(filteredAdjustedSignalTension, ambientAdjustedSignalTension, filterStrength);
    }

    float getAmbiantTension() { return ambiantTension; }
    float getSignalTension() { return signalTension; }
    float getAmbientAdjustedSignalTension() { return ambientAdjustedSignalTension; }
    
    float getFilteredAdjustedSignalTension() { return filteredAdjustedSignalTension; }

    float getFilterStrength() { return filterStrength; }
    void setFilterStrength(float strength) { filterStrength = constrain(strength, 0, 1); }

    void print() {
        if (Serial) {
            Serial.print("Ambient tension: ");
            Serial.print(getAmbiantTension());
            Serial.print("V\t");

            Serial.print("Signal tension: ");
            Serial.print(getSignalTension());
            Serial.print("V\t");

            Serial.print("Adjusted tension: ");
            Serial.print(getAmbientAdjustedSignalTension());
            Serial.print("V\t");

            Serial.print("Filtered adjusted tension: ");
            Serial.print(getFilteredAdjustedSignalTension());
            Serial.print("V\t");

            Serial.print("Filter strength: ");
            Serial.println(getFilterStrength());
        }
    }
}