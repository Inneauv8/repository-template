#ifndef WHISTLE_TRIGGER_H
#define WHISTLE_TRIGGER_H

/**
 * @brief Namespace for the WhistleTrigger library.
 */
namespace WhistleTrigger {

    /**
     * @brief Namespace containing internal variables.
     */
    namespace {

        /**
         * @brief Variable for the trigger threshold.
         */
        extern float threshold;

        /**
         * @brief Variables for tripped states.
         */
        extern bool previousTrippedState;
        extern bool trippedState;

        /**
         * @brief Variable for the trigger state.
         */
        extern bool triggered;
    }

    /**
     * @brief Initializes the WhistleTrigger library.
     *
     * @param _threshold The threshold for triggering.
     * @param _mode The trigger mode (CHANGE, RISING, FALLING).
     */
    void init(bool _threshold, int _mode);

    /**
     * @brief Updates the WhistleTrigger library.
     */
    void update();

    /**
     * @brief Gets the trigger threshold.
     *
     * @return The trigger threshold.
     */
    float getThreshold();

    /**
     * @brief Sets the trigger threshold.
     *
     * @param _threshold The new trigger threshold.
     */
    void setThreshold(int _threshold);

    /**
     * @brief Gets the trigger mode.
     *
     * @return The trigger mode (CHANGE, RISING, FALLING).
     */
    int getMode();

    /**
     * @brief Sets the trigger mode.
     *
     * @param _mode The new trigger mode (CHANGE, RISING, FALLING).
     */
    void setMode(int _mode);

    /**
     * @brief Checks if the trigger is currently active.
     *
     * @return True if the trigger is active, false otherwise.
     */
    bool isTriggered();

    /**
     * @brief Checks if the trigger is in a rising state.
     *
     * @return True if the trigger is rising, false otherwise.
     */
    bool isRising();

    /**
     * @brief Checks if the trigger is in a falling state.
     *
     * @return True if the trigger is falling, false otherwise.
     */
    bool isFalling();

    /**
     * @brief Checks if the trigger state is changing.
     *
     * @return True if the trigger state is changing, false otherwise.
     */
    bool isChanging();

    /**
     * @brief Prints information from the WhistleTrigger library.
     */
    void print();
}

#endif // WHISTLE_TRIGGER_H
