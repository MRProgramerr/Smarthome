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
    this->last5values.push_back(addvalue);

}
void Thermostat::setthesetpoint(double currentval){
    this->currentvalue = currentval;
}
AbstractMeasurement *Thermostat::lastMeasurement(){
    am = new AbstractMeasurement("Light Switch","last Measurement","C");
    mt->setValue(lastvalue);
    return am;
}
AbstractMeasurement *Thermostat::last5Measurement(){

    am = new AbstractMeasurement("Light Switch","last 5 Measurements ","C");
    mt1->setValue(last5values);
    return am;
}
AbstractMeasurement *Thermostat::setpoint(){

    am = new AbstractMeasurement("Light Switch","temperature setpoint","C");
    mt->setValue(currentvalue);
    return am;
}
std::string Thermostat::currentState(){

    if(lastvalue >= currentvalue - 0.5 && lastvalue <= currentvalue + 0.5){

        plusminus = randomDouble();
        lastvalue = currentvalue;
        storelastMeasurements(lastvalue);

        if(plusminus > 0.0 && plusminus<2.5)
            currentvalue = currentvalue + randomDouble();

        else
            currentvalue = currentvalue - randomDouble();
        return "STABLE";
    }

    else if(lastvalue < currentvalue + 0.5){
        lastvalue = currentvalue;
        storelastMeasurements(lastvalue);
        if(0.5>((currentvalue - lastvalue)/10))
            currentvalue = lastvalue + 0.5;
        else
           currentvalue = lastvalue + ((currentvalue - lastvalue)/10);
        return "HEATING";
    }
    else if(lastvalue > currentvalue + 0.5){

        lastvalue = currentvalue;
        storelastMeasurements(lastvalue);

        if(0.5>((currentvalue - lastvalue)/10))
            currentvalue = lastvalue - 0.5;
        else
           currentvalue =  lastvalue - ((currentvalue - lastvalue)/10);
        return "COOLING";
    }
    return "";
}
void Thermostat::warmer(double amount){
    if(amount>0)
    setthesetpoint(currentvalue+amount);
}
void Thermostat::cooler(double amount){
    if(amount>0)
    setthesetpoint(currentvalue-amount);
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
