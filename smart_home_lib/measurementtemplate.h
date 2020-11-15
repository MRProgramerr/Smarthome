#ifndef MEASUREMENTTEMPLATE_H
#define MEASUREMENTTEMPLATE_H

#include "abstractmeasurement.h"
#include <QVariant>
#include <iostream>
#include <math.h>

/**
 * The template class for measurementsd
 */

template <class T>
class MeasurementTemplate : public AbstractMeasurement
{
public:
    MeasurementTemplate(std::string deviceName, std::string measurementType, std::string UoM)
        : AbstractMeasurement(deviceName,measurementType,UoM ){
    }

    void setValue(T value){
        _value = value;
    }

    QVariant value(){
        return _value;
    }

    ~MeasurementTemplate(){};

private:
    T _value;
};


template <>
class MeasurementTemplate<double> : public AbstractMeasurement
{
public:
    MeasurementTemplate(std::string deviceName, std::string measurementType, std::string UoM )
        : AbstractMeasurement(deviceName,measurementType, UoM){}

    void setValue(double value){
        _value = value;
    }

    QVariant value(){
        return std::round(_value*_precission*10)/(_precission*10);
    }

    void setPrecision(int precission)
    {
        _precission = precission;

    }
     int getPrecision()
    {
        return _precission;
    }



private:
    double _value = 0.00;
    int _precission=1;

};


#endif // MEASUREMENTTEMPLATE_H
