#ifndef MEASUREMENTTEMPLATE_H
#define MEASUREMENTTEMPLATE_H

#include "abstractmeasurement.h"
#include <QVariant>
#include <iostream>
#include <math.h>


template <class T>
class MeasurementTemplate : public AbstractMeasurement
{
public:
    MeasurementTemplate(std::string deviceName, std::string measurementType )
        : AbstractMeasurement(deviceName,measurementType){


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
    MeasurementTemplate(std::string deviceName, std::string measurementType )
        : AbstractMeasurement(deviceName,measurementType){}

    void setValue(double value){
        _value = value;
    }

    QVariant value(){
        return std::round(_value*100)/100;
    }


private:
    double _value;

};


#endif // MEASUREMENTTEMPLATE_H