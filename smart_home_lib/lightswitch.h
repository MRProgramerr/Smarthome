#ifndef LIGHTSWITCH_H
#define LIGHTSWITCH_H

#include <QObject>
#include <QString>
#include "device.h"
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "LightSwitchProxyInterface.h"

/**
 * @brief The LightSwitch class
 * Concrete implementation of the lightswitch
 * Inherits Abstract Device and the lightswitch proxy
 * interface using multiple inheritance.
 */

class LightSwitch : public Device, public LightSwitchProxyInterface
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
    bool getIsOn() ;

    /**
     * @brief setIsOn : Turns on the sdevice
     * @param value
     */
    void turnOn() ;

    /**
     * @brief setIsOff : Turns off the device
     * @param value
     */
    void turnOff() ;

    /**
     * @brief getBrightnessLevel
     * @return The brightness level of the lightSwitch(20-100)
     */
    int getBrightnessLevel() ;

    /**
     * @brief setBrightnessLevel : Sets the brightness level of the lightSwitch
     * @param value
     */
    void setBrightnessLevel(int value);


    /**
     * @brief dim : Reduce the 'brightness level' by 20 points
     * if currently greater than 20
     */
    void dim() ;

    /**
     * @brief brighten : Increases the brighness level by 20 points
     * if less than 100
     */
    void brighten() ;




private:

    bool _isOn = false;
    int _brightnessLevel = 0;
    int _userInput ;


signals:

    void reportChange(QString change);


public slots:

    void receiveChange(QString change);

};

#endif // LIGHTSWITCH_H
