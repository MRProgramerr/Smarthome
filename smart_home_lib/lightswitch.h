#ifndef LIGHTSWITCH_H
#define LIGHTSWITCH_H

#include <QObject>
#include <QString>
#include "device.h"

class LightSwitch : public Device
{
    Q_OBJECT

public:

    /**
     * @brief LightSwitch : The default contructor for the lightSwitch class
     * @param name
     */
    LightSwitch(QString name);


    /**
     * @brief getIsOn
     * @return True if device is turned on, else false
     */
    bool getIsOn() const;

    /**
     * @brief setIsOn : Turns on the device
     * @param value
     */
    void turnOn(bool value);

    /**
     * @brief getIsOff
     * @return True if device is turned off, else false
     */
    bool getIsOff() const;

    /**
     * @brief setIsOff : Turns off the device
     * @param value
     */
    void turnOff(bool value);

    /**
     * @brief getBrightnessLevel
     * @return The brightness level of the lightSwitch(20-100)
     */
    int getBrightnessLevel() const;

    /**
     * @brief setBrightnessLevel : Sets the brightness level of the lightSwitch
     * @param value
     */
    void setBrightnessLevel(int value);


    /**
     * @brief dim : Reduce the 'brightness level' by 20 points
     * if currently greater than 20
     */
    void dim();

    /**
     * @brief brighten : Increases the brighness level by 20 points
     * if less than 100
     */
    void brighten();


    // Todo currentState();


    /**
     * @brief menuLightSwitch
     * @details This is the main menu for the lightSwitch device
     * it will allow the controller or even the local instance of the light
     * switch to change its paramters
     * A signal and slot mechanism will be used to report each state change to commandLine
     * and to the controller
     */
    void menuLightSwitch();


private:

    bool _isOn = false;
    bool _isOff = false;
    int _brightnessLevel = 0;

signals:


public slots:



};

#endif // LIGHTSWITCH_H
