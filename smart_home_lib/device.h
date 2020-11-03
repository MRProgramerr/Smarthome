#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QString>

class Device : public QObject
{
    Q_OBJECT
public:
    explicit Device(QObject *parent = nullptr);

signals:


private:
    QString deviceName;



};

#endif // DEVICE_H
