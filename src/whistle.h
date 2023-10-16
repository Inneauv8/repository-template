#ifndef WHISTLE_H
#define WHISTLE_H

/**
 * @brief Namespace for the Whistle library.
 */
namespace Whistle {

    /**
     * @brief Namespace containing internal variables.
     */
    namespace {

        /**
         * @brief Variable for ambient pin.
         */
        extern int ambiantPin;

        /**
         * @brief Variable for signal pin.
         */
        extern int signalPin;

        /**
         * @brief Variable for ambient tension.
         */
        extern float ambiantTension;

        /**
         * @brief Variable for signal tension.
         */
        extern float signalTension;

        /**
         * @brief Variable for ambient-adjusted signal tension.
         */
        extern float ambientAdjustedSignalTension;

        /**
         * @brief Variable for filtered adjusted signal tension.
         */
        extern float filteredAdjustedSignalTension;

        /**
         * @brief Variable for filter strength.
         */
        extern float filterStrength;

        /**
         * @brief Converts an analog value to 5V scale.
         *
         * @param analogValue The input analog value (0 - 1023)
         * @return The analog value scaled to 5V.
         */
        float analogTo5V(int analogValue);

        /**
         * @brief Reads the ambient tension and updates it.
         */
        void readAmbiantTension();

        /**
         * @brief Reads the signal tension and updates it.
         */
        void readSignalTension();

        /**
         * @brief Applies a low-pass filter to the input values.
         *
         * @param oldValue The previous value.
         * @param newValue The new value to filter.
         * @param filterStrength The strength of the filter.
         * @return The filtered value.
         */
        float applyLowPassFilter(float oldValue, float newValue, float filterStrength);
    }

    /**
     * @brief Initializes the Whistle library.
     *
     * @param _signalPin The signal pin to be used.
     * @param _ambiantPin The ambient pin to be used.
     * @param _filterStrength The strength of the filter to apply.
     */
    void init(int _signalPin, int _ambiantPin, int _filterStrength);

    /**
     * @brief Updates the Whistle library.
     */
    void update();

    /**
     * @brief Gets the ambient tension.
     *
     * @return The ambient tension.
     */
    float getAmbiantTension();

    /**
     * @brief Gets the signal tension.
     *
     * @return The signal tension.
     */
    float getSignalTension();

    /**
     * @brief Gets the ambient-adjusted signal tension.
     *
     * @return The ambient-adjusted signal tension.
     */
    float getAmbientAdjustedSignalTension();

    /**
     * @brief Gets the filtered adjusted signal tension.
     *
     * @return The filtered adjusted signal tension.
     */
    float getFilteredAdjustedSignalTension();

    /**
     * @brief Gets the filter strength.
     *
     * @return The filter strength.
     */
    float getFilterStrength();

    /**
     * @brief Sets the filter strength.
     *
     * @param strength The new filter strength.
     */
    void setFilterStrength(float strength);

    /**
     * @brief Prints information from the Whistle library.
     */
    void print();
}

#endif // WHISTLE_H
