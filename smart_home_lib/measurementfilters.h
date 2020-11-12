#ifndef MEASUREMENTFILTERS_H
#define MEASUREMENTFILTERS_H
#include "measurementtemplate.h"
#include <QVariant>

template <class T>
class MeasurementFilters : public MeasurementTemplate<T>
{
public:
    MeasurementFilters(std::string DeviceName, std::string MeasurementType,std::string FilterType) : MeasurementTemplate<T>(DeviceName,MeasurementType, FilterType){}
    void setConfiguration(T conifguration){
        Configuration = conifguration;
    }
    T getConfiguration(){
        return Configuration;
    }
    ~MeasurementFilters(){};

    T MinConversion(){
        if(!isvalid(Configuration)){
                return "*invalid*";
    }
        T lastVal = MeasurementTemplate<T>().value();

    }

    bool isvalid(QVariant value){

        if(value.type() == QVariant::Double || value.type() == QVariant::Time || value.type() == QVariant::Int){
            return true;
        }
        else
            return false;
    }

private:
    T Configuration ;

};


#endif // MEASUREMENTFILTERS_H
