#include "thermostat.h"

//Thermostat::Thermostat(QString name, QString port,QString IP_address, int updatefrequency, char UoM, double starttemperature): Device(name)
//{
//    this->Name = name;
//    this->IP_Address = IP_address;
//    this->Port = port;
//    this->UpdateFrequency = updatefrequency;
//    this->UoM = UoM;
//    this->StartTemperature = starttemperature;

//}

//void Thermostat::setlastMeasurement(double value){
//    this->lastvalue = value;
//}
//void Thermostat::storelastMeasurements(double addvalue){
//    if(last5values.size()>5){
//        last5values.erase(last5values.begin()+0);
//    }
//    this->last5values.push_back(addvalue);

//}
//void Thermostat::setcurrentdesiredtemperature(double temp){
//    this->Temp = temp;
//}
//Measurement<double> Thermostat::lastMeasurement(){
//    return this->lastvalue;
//}
//Measurement<std::vector<double>> Thermostat::last5Measurement(){

//    return this->last5values;
//}
//double Thermostat::setpoint(){

//    return this->Temp;
//}
//int Thermostat::currentState(){

//}
//void Thermostat::warmer(double amount){
//    if(amount>0)
//    setcurrentdesiredtemperature(setpoint()+amount);
//}
//void Thermostat::cooler(double amount){
//    if(amount>0)
//    setcurrentdesiredtemperature(setpoint()-amount);
//}
