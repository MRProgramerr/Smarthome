#include "rawmeasurement.h"

template<>
std::string RawMeasurement<std::string>::deviceName(){
    return Name;
}

template<>
void RawMeasurement<std::string>::setDeviceName(std::string name){
    
    Name = name;
       
}
template <>
QDateTime RawMeasurement<QDateTime>::timestamp(){
    
    return QDateTime::currentDateTime();
}

template <>
void RawMeasurement<bool>::setfiltred(bool filter){
    
    Filter = filter;
            
}

template <>
bool RawMeasurement<bool>::isFiltered(){
    
    return Filter;
}

template <>
void RawMeasurement<std::string>::setunitofMeasure(std::string uom){
    
    UOM = uom;
}

template <>
std::string RawMeasurement<bool>::unitOfMeasure(){
    
    return UOM;
}

template <class t>
RawMeasurement<QObject> rawMeasurement();

