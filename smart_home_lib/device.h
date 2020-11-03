#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QString>

class Device : public QObject
{
    Q_OBJECT
public:

    explicit Device(QObject *parent = nullptr);

    Device(QString deviceName);

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


    /**
     * @brief getIPAddressController  : The getter function for the controller's ip address
     * @return Ip Address of the controller
     */
    QString getIPAddressController();

    /**
     * @brief setIPAddressController : The setter function for the controller's ip address
     * @param IPAddress
     */
    void setIPAddressController(QString IPAddress);

    /**
     * @brief getPortNumberController  : The getter function for the controller's port no
     * @return Port Number
     */
    QString getPortNumberController();


    /**
     * @brief setPortNumberController : The setter function for the controller's port number
     * @param portNumber
     */
    void setPortNumberController(QString portNumber);


signals:



private:
    QString _deviceName ;
    QString _IPAddressController;
    QString _PortNumberController;


};

#endif // DEVICE_H
