#ifndef MEASUREMENTTEMPLATE_H
#define MEASUREMENTTEMPLATE_H

#include "abstractmeasurement.h"
#include <QVariant>


template <class T>
class MeasurementTemplate : public AbstractMeasurement
{
public:
    MeasurementTemplate(std::string deviceName, std::string measurementType, QVariant value)
        : AbstractMeasurement(deviceName,measurementType,value){}


    QVariant value() override;

    ~MeasurementTemplate(){};
};

#endif // MEASUREMENTTEMPLATE_H
