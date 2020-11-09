#include "abstractmeasurement.h"

AbstractMeasurement::AbstractMeasurement(std::string deviceName, std::string measurementType, QVariant value)
    : _deviceName(deviceName), _measurementType(measurementType), _value(value)
{

}

std::string AbstractMeasurement::deviceName()
{
    return _deviceName;
}

std::string AbstractMeasurement::unitofMeasure()
{
    return _unitofMeasure;
}

void AbstractMeasurement::setUnitofMeasure( std::string unitofMeasure)
{
    _unitofMeasure = unitofMeasure;
}

std::string AbstractMeasurement::measurementType()
{
    return _measurementType;
}

QDateTime AbstractMeasurement::timeStamp()
{
    return QDateTime::currentDateTime();
}

AbstractMeasurement *AbstractMeasurement::rawMeasurement()
{
    return this;
}

bool AbstractMeasurement::isFiltered()
{
    return _isFiltered;
}

void AbstractMeasurement::setIsFiltered(bool isFiltered)
{
    _isFiltered = isFiltered;
}

