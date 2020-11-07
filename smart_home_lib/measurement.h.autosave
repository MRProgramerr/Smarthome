#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <QMetaType>
#include "lightswitch.h"
#include "thermostat.h"
#include "iomanip"
#include "device.h"
/**
 * @brief The Measurement class
 *
 * TODO: This is just a placeholder so that the MessageFactory can
 * reference it. You need to implement it properly.
 */
template <class T>
class Measurement
{

public:
    Measurement(T type);
    std::string deviceName();
    void setDeviceName(std::string name);
    T measurementType();
    bool isFiltered();
    Measurement rawMeasurement();

};

// You may need this to make it compatiable with QVariant
// You may also need to use it on each instantiation of the
// template subclass.
Q_DECLARE_METATYPE(Measurement<int>)

#endif // MEASUREMENT_H
