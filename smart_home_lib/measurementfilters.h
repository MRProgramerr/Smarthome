#ifndef MEASUREMENTFILTERS_H
#define MEASUREMENTFILTERS_H
#include "measurementtemplate.h"
#include <QVariant>

template <class T>
class MeasurementFilters : public MeasurementTemplate<T>
{
public:
    MeasurementFilters(std::string DeviceName, MeasurementTemplate<T>* MeasurementType,std::string FilterType) : MeasurementTemplate<T>(DeviceName,MeasurementType, FilterType){
            devicename = DeviceName;
            Mtype = MeasurementType;
            filtertype = FilterType;
    }
    void setConfiguration(T conifguration){
        configuireval = conifguration;
    }
    T getConfiguration(){
        return configuireval;
    }
    void setFilterType(std::string type){

    }
    ~MeasurementFilters(){};

    void run(){
        if(filtertype == "1"){
            TempConversion();
        }
        if(filtertype == "2"){
            MinConversion();
        }
        if(filtertype =="3"){
            MaxConversion();
        }
        if(filtertype == "4"){
            ExactConversion();
        }
    }

    T MinConversion(){
        if(!isvalid(configuireval)){
                return "*invalid*";
    }
        else if(getinclusive()){

            if(Mtype->value() >= configuireval)
                return configuireval;
            else
                return Mtype->value();
        }

        else if(!getinclusive()){

            if(Mtype->value().value() > configuireval)
                return configuireval;
            else
                return Mtype->value();
        }
    }

    T MaxConversion(){
        if(!isvalid(configuireval)){
                return "*invalid*";
    }
        else if(getinclusive()){

            if(Mtype->value().value() <= configuireval)
                return configuireval;
            else
                return Mtype->value().value();
        }

        else if(!getinclusive()){

            if(Mtype->value().value() < configuireval)
                return configuireval;
            else
                return Mtype->value().value();
        }
    }

    T ExactConversion(){
        if(!isvalid(configuireval)){
                return "*invalid*";
         }

        if(Mtype->value().value() == configuireval)
            return configuireval;
        else if(Mtype->value().value() == configuireval+(rand()%10+1))
            return configuireval;
        else if(Mtype->value().value() == configuireval-(rand()%10+1))
            return configuireval;
        else
            return Mtype->value().value();

    }

    T TempConversion(){
        if(Mtype->unitofMeasure() == "C" || Mtype->value()->unitOfMeasure() == "C")
          return  (Mtype->value() * (9.0/5.0f))+32;
        else{
            return (Mtype->value()- 32) *(5.0/9.0);
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
    std::string filtertype;
    std::string devicename;
    MeasurementTemplate<T>* Mtype;
};


#endif // MEASUREMENTFILTERS_H
