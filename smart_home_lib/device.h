#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QString>

class Device : public QObject
{
    Q_OBJECT
public:

    explicit Device(QObject *parent = nullptr);

    /**
     * @brief getDeviceName : The getter function for the deviceName
     * @return the name of the device
     */
    QString getDeviceName();


    /**
     * @brief setDeviceName : The setter function for the device name
     * @param deviceName  : The name of the device to be set
     */
    void setDeviceName(QString deviceName);

signals:



private:
    QString _deviceName;

};

#endif // DEVICE_H
