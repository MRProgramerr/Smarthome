#include "thermostat.h"


Thermostat::Thermostat(QString name): Device(name)
{
    this->Name = name;

}

int Thermostat::getUpdateFrequency()
{
    return Value;
}

void Thermostat::setUpdateFrequency(int value)
{
    Value = value;
}

std::string Thermostat::unitofMeasure()
{
    return UoM;
}

void Thermostat::setUnitofMeasure(std::string unitofMeasure)
{
    UoM = unitofMeasure;
}

double Thermostat::getStartingTemperature()
{
    return StartTemperature;
}

void Thermostat::setStartingTemperature(double starttemp){
    StartTemperature = starttemp;
}
void Thermostat::setlastMeasurement(double value){
    this->lastvalue = value;
}
void Thermostat::storelastMeasurements(double addvalue){
    if(last5values.size()>5){
        last5values.erase(last5values.begin()+0);
    }
    last5values.push_back(addvalue);

}
void Thermostat::setthesetpoint(double currentval){
    thesetpoint = currentval;
}
MeasurementTemplate<double> *Thermostat::lastMeasurement(){
    mt = new MeasurementTemplate<double>(Name.toStdString(),"last Measurement",UoM);
    mt->setValue(lastvalue);
    return mt;
}
MeasurementTemplate<std::vector<double>> *Thermostat::last5Measurement(){

    mt1 = new MeasurementTemplate<std::vector<double>>(Name.toStdString(),"last 5 Measurements ",UoM);
    mt1->setValue(last5values);
    return mt1;
}
MeasurementTemplate<double> *Thermostat::setpoint(){

    mt = new MeasurementTemplate<double>(Name.toStdString(),"temperature setpoint",UoM);
    mt->setValue(thesetpoint);
    return mt;
}

void Thermostat::setcurrentstate(std::string state)
{
   cstate = state;
}
MeasurementTemplate<double> *Thermostat::currentState(){

     mt = new MeasurementTemplate<double>(Name.toStdString(),"Current State",cstate);
     mt->setValue(currentvalue);
     return mt;

}
void Thermostat::warmer(double amount){
    if(amount>0)
    setthesetpoint(currentvalue+amount);
}
void Thermostat::cooler(double amount){
    if(amount>0)
        setthesetpoint(currentvalue-amount);
}

void Thermostat::update()
{

    if(lastvalue >= thesetpoint - 0.5 && lastvalue <= thesetpoint + 0.5){

        plusminus = randomDouble();
        lastvalue = currentvalue;

        storelastMeasurements(lastvalue);

        if(plusminus > 0.0 && plusminus<2.5)
            currentvalue = currentvalue + randomDouble();

        else
            currentvalue = currentvalue - randomDouble();
         setcurrentstate("STABLE");
    }

    else if(lastvalue < thesetpoint + 0.5){

        lastvalue = currentvalue;
        storelastMeasurements(lastvalue);
        if(0.5>((thesetpoint - lastvalue)/10))
            currentvalue = lastvalue + 0.5;
        else
           currentvalue = lastvalue + ((thesetpoint - lastvalue)/10);
        setcurrentstate("HEATING");

     }

    else if(lastvalue > thesetpoint + 0.5){

        lastvalue = currentvalue;
        storelastMeasurements(lastvalue);

        if(0.5>((lastvalue - thesetpoint)/10))
            currentvalue = lastvalue - 0.5;
        else
           currentvalue =  lastvalue - ((lastvalue - thesetpoint)/10);
        setcurrentstate("COOLING");

    }

}

double Thermostat::randomDouble()
{
        return _realDistribution(_randomGenerator);

}


Device *Thermostat::realDevice()
{
    return this;
}


std::string Thermostat::deviceType()
{
    return "Thermostat";
}
