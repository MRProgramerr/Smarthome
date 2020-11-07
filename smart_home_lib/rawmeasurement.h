#ifndef RAWMEASUREMENT_H
#define RAWMEASUREMENT_H
#include "device.h"

template <class T>
class RawMeasurement
{
public:
    RawMeasurement();
    RawMeasurement(T type);
    Device deviceName();
    void setDeviceName(std::string name);
    T measurementType();
    bool isFiltered();
    RawMeasurement rawMeasurement();

private:
    T type;
    QString Name;
    QString IP_Address;
    QString Port;
    bool ison;
    int brightnesslevel;

};

#endif // RAWMEASUREMENT_H
