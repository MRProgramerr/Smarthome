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
        configuireval = conifguration;
    }
    T getConfiguration(){
        return configuireval;
    }
    ~MeasurementFilters(){};

    T MinConversion(){
        if(!isvalid(configuireval)){
                return "*invalid*";
    }
        else if(getinclusive()){

            if(MeasurementTemplate<T>().value() >= configuireval)
                return configuireval;
            else
                return MeasurementTemplate<T>().value();
        }

        else if(!getinclusive()){

            if(MeasurementTemplate<T>().value() > configuireval)
                return configuireval;
            else
                return MeasurementTemplate<T>().value();
        }
    }

    T MaxConversion(){
        if(!isvalid(configuireval)){
                return "*invalid*";
    }
        else if(getinclusive()){

            if(MeasurementTemplate<T>().value() <= configuireval)
                return configuireval;
            else
                return MeasurementTemplate<T>().value();
        }

        else if(!getinclusive()){

            if(MeasurementTemplate<T>().value() < configuireval)
                return configuireval;
            else
                return MeasurementTemplate<T>().value();
        }
    }

    T TempConversion(){
        if(MeasurementTemplate<T>::unitOfMeasure() == "C" || MeasurementTemplate<T>::unitOfMeasure() == "C")
          return  (MeasurementTemplate<T>::value() * (9.0/5.0f))+32;
        else{
            return (MeasurementTemplate<T>::value()- 32) *(5.0/9.0);
        }

}
    bool isvalid(QVariant value){

        if(value.type() == QVariant::Double || value.type() == QVariant::Time || value.type() == QVariant::Int){
            return true;
        }
        else
            return false;
    }

    void setinclusive(bool inc){
        Inc = inc;
    }
    bool getinclusive(){
        return Inc;
    }

private:
    T configuireval ;
    bool Inc = true;
};


#endif // MEASUREMENTFILTERS_H
