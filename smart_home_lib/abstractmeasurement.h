#ifndef ABSTRACTMEASUREMENT_H
#define ABSTRACTMEASUREMENT_H
#include <iostream>
#include <QVariant>
#include <QDateTime>


/**
 * @brief The AbstractMeasurement class
 * This is the abstract measurement class used to
 * define the common behaviours of each
 * concrete measurement
 */

class AbstractMeasurement
{
public:

    /**
     * @brief AbstractMeasurement
     * The constructor for the abs measurement
     * class.
     * @param deviceName
     * @param measurementType
     * @param UoM
     */
    AbstractMeasurement(std::string deviceName, std::string measurementType, std::string UoM);

    /**
     * @brief deviceName
     * @return The name of the device
     */
    std::string deviceName();

    /**
     * @brief unitofMeasure
     * @return The unit of measure of the device
     */
    std::string unitofMeasure() ;

    /**
     * @brief setUnitofMeasure
     * Sets the unit of measure of the device
     * @param unitofMeasure
     */
    void setUnitofMeasure(std::string unitofMeasure);

    /**
     * @brief measurementType
     * @return The measurement type
     */
    std::string measurementType() ;

    /**
     * @brief timeStamp
     * @return The current date and time
     */
    QDateTime timeStamp();

    /**
     * @brief rawMeasurement
     * @return The bare measurement object
     */
    AbstractMeasurement* rawMeasurement();

    /**
     * @brief ~AbstractMeasurement
     * The virtual destructor for the abstract
     * measurement class
     */
    virtual ~AbstractMeasurement(){};

    /**
     * @brief isFiltered
     * @return True if filtered measurement else false
     */
    bool isFiltered() ;

    /**
     * @brief setIsFiltered
     * sets whether measurement filtered or not
     * @param isFiltered
     */
    void setIsFiltered(bool isFiltered);



private:

    std::string _deviceName = "";
    std::string _measurementType = "";

    std::string _unitofMeasure ="";
    bool _isFiltered = true;



};

#endif // ABSTRACTMEASUREMENT_H

