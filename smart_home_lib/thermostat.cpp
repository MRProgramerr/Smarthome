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
MeasurementTemplate<double> *Thermostat::lastMeasurement(){
    mt = new MeasurementTemplate<double>("Light Switch","last Measurement","C");
    mt->setValue(lastvalue);
    return mt;
}
MeasurementTemplate<std::vector<double>> *Thermostat::last5Measurement(){

    mt1 = new MeasurementTemplate<std::vector<double>>("Light Switch","last 5 Measurements ","C");
    mt1->setValue(last5values);
    return mt1;
}
MeasurementTemplate<double> *Thermostat::setpoint(){

    mt = new MeasurementTemplate<double>("Light Switch","temperature setpoint","C");
    mt->setValue(currentvalue);
    return mt;
}
MeasurementTemplate<double> *Thermostat::currentState(){

    if(lastvalue >= currentvalue - 0.5 && lastvalue <= currentvalue + 0.5){

        plusminus = randomDouble();
        lastvalue = currentvalue;
        storelastMeasurements(lastvalue);

        if(plusminus > 0.0 && plusminus<2.5)
            currentvalue = currentvalue + randomDouble();

        else
            currentvalue = currentvalue - randomDouble();

        mt = new MeasurementTemplate<double>("Light Switch","Current State","STABLE");
        mt->setValue(0);
        return mt;
    }

    else if(lastvalue < currentvalue + 0.5){
        lastvalue = currentvalue;
        storelastMeasurements(lastvalue);
        if(0.5>((currentvalue - lastvalue)/10))
            currentvalue = lastvalue + 0.5;
        else
           currentvalue = lastvalue + ((currentvalue - lastvalue)/10);
        mt = new MeasurementTemplate<double>("Light Switch","Current State","HEATING");
        mt->setValue(1);
        return mt;
    }
    else if(lastvalue > currentvalue + 0.5){

        lastvalue = currentvalue;
        storelastMeasurements(lastvalue);

        if(0.5>((currentvalue - lastvalue)/10))
            currentvalue = lastvalue - 0.5;
        else
           currentvalue =  lastvalue - ((currentvalue - lastvalue)/10);

    }
    mt = new MeasurementTemplate<double>("Light Switch","Current State","COOLING");
    mt->setValue(-1);
    return mt ;
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
