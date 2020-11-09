#ifndef ABSTRACTMEASUREMENT_H
#define ABSTRACTMEASUREMENT_H
#include <iostream>
#include <QVariant>
#include <QDateTime>


class AbstractMeasurement
{
public:
    AbstractMeasurement(std::string deviceName, std::string measurementType);

    std::string deviceName();

    std::string unitofMeasure() ;

    void setUnitofMeasure(std::string unitofMeasure);

    std::string measurementType() ;

    QDateTime timeStamp();

    AbstractMeasurement* rawMeasurement();

    virtual ~AbstractMeasurement(){};

    bool isFiltered() ;
    void setIsFiltered(bool isFiltered);






private:

    std::string _deviceName;
    std::string _measurementType;

    std::string _unitofMeasure;
    bool _isFiltered;



};

#endif // ABSTRACTMEASUREMENT_H
