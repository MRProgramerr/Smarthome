#ifndef RAWMEASUREMENT_H
#define RAWMEASUREMENT_H
#include "device.h"
#include <QDateTime>
#include <QVariant>


template <class T>
class RawMeasurement
{
public:
    RawMeasurement();
    RawMeasurement(T type);
    std::string deviceName();
    void setDeviceName(std::string name);
    T measurementType();
    QDateTime timestamp();
    void setfiltred(bool filter);
    bool isFiltered();
    void setunitofMeasure(std::string uom);
    std::string unitOfMeasure();
    RawMeasurement rawMeasurement();


private:
    T type;
    std::string Name;
    QString IP_Address;
    QString Port;
    bool ison;
    int brightnesslevel;
    bool Filter;
    std::string UOM;

};

#endif // RAWMEASUREMENT_H
