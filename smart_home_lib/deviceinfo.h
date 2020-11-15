#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QMetaType>

/**
 * @brief The DeviceInfo class/struct
 *
 *
 */
class DeviceInfo
{
public:
  DeviceInfo();
};

// You may need this to make it compatiable with QVariant
Q_DECLARE_METATYPE(DeviceInfo)

#endif // DEVICEINFO_H
