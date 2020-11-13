#include "sprinklersystem.h"

SprinklerSystem::SprinklerSystem(QString name) : Device(name)
{
    Name = name;

}

int SprinklerSystem::getUpdateFrequency()
{
    return _updateFrequency;
}

void SprinklerSystem::setUpdateFrequency(int value)
{
    _updateFrequency = value;
}

double SprinklerSystem::getWaterConsumptionPerInterval()
{
    return _waterConsumptionPerInterval;
}

void SprinklerSystem::setWaterConsumptionPerInterval(double value)
{
    _waterConsumptionPerInterval = value;
}

double SprinklerSystem::getlifetimeConsumption()
{
   return totalConsumption;
}
void SprinklerSystem::setlifetimeConsumption(double value){

    totalConsumption = value;
}

bool SprinklerSystem::getIsOn()
{
    return _isOn;
}

double SprinklerSystem::waterConsumptionPerCycle(QDateTime on, QDateTime off)
{


    qint64 diff = on.msecsTo(off);

    return diff;


}


void SprinklerSystem::turnOn()
{
    _isOn = true;
    setcurrrentState("ON");

}


void SprinklerSystem::turnOff( )
{
    _isOn = false;
    setcurrrentState("OFF");
}

void SprinklerSystem::schedule(QTime delay, QTime duration)
{

    setcurrrentState("SCHEDULED");

        std::async(std::launch::async, [=] () {

            std::this_thread::sleep_for(std::chrono::seconds{delay.second()});

            this->turnOn();
            std::cout << "Sprinkler System turned on"<< std::endl;
        } );

        std::this_thread::sleep_for( std::chrono::seconds{duration.second()});
            this->turnOff();
            std::cout << "Sprinkler System turned off"<< std::endl;

            // Some arbitary rate of water usage
            std::cout << "Sprinkler System used" << (_waterConsumptionPerInterval*duration.second()/15) << " litre(s) of water " << std::endl;


}

void SprinklerSystem::setcurrrentState(std::string state)
{
    thestate = state;
}

std::vector<MeasurementTemplate<QTime>*> SprinklerSystem::currentState()
{
    if(thestate == "SCHEDULED"){
        mtstate = new MeasurementTemplate<QTime>(Name.toStdString(),"Current State","SCHEDULED");
        mtvectorstate.push_back(mtstate);

        mtstate2 = new MeasurementTemplate<QTime>(Name.toStdString(),"Delay","Seconds");
        mtstate->setValue(Delay);
        mtvectorstate.push_back(mtstate);

        mtstate3 = new MeasurementTemplate<QTime>(Name.toStdString(),"Duration","Seconds");
        mtstate->setValue(Duration);
        mtvectorstate.push_back(mtstate);

    }
    else{
        mtstate = new MeasurementTemplate<QTime>(Name.toStdString(),"Current State",thestate);
        mtstate->setValue(Duration);
        mtvectorstate.push_back(mtstate);
    }
    return mtvectorstate;
}

std::vector<MeasurementTemplate<double> *> SprinklerSystem::waterUsage()
{
       mtusage = new MeasurementTemplate<double>(Name.toStdString(),"Water Usage","L");
       mtusage->setValue(getWaterConsumptionPerInterval());
       mtvectorusage.push_back(mtusage);

       mtusage2 = new MeasurementTemplate<double>(Name.toStdString(),"Lifetime Water Consumption","L");
       mtusage->setValue(getlifetimeConsumption());
       mtvectorusage.push_back(mtusage);

       return mtvectorusage;
}


Device *SprinklerSystem::realDevice()
{
 return this;
}


std::string SprinklerSystem::deviceType()
{
    return "Sprinkler System";
}



