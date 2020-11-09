#include "measurementtemplate.h"


template<>
QVariant MeasurementTemplate<double>::value()
{
    return 0;
}

template<class T>
QVariant MeasurementTemplate<T>::value()
{
    return this->_value;
}
