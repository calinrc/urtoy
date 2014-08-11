/*
 *    Remote.h file written and maintained by Calin Cocan
 *    Created on: Aug 11, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef DEVICE_HANDLER_H_
#define DEVICE_HANDLER_H_

#include "devices/DeviceInitInfo.h"
#include "Constants.h"

class DeviceHandler
{
public:
    DeviceHandler()
    {
    }

    virtual ~DeviceHandler()
    {

    }

    //init the device with the information from DeviceInitInfo
    virtual DeviceErrorCode init(DeviceInitInfo*) = 0;
    //init read from device the data bytes
    virtual DeviceErrorCode read(char** bytesBuff, size_t* length)=0;
    //release read data bytes
    virtual DeviceErrorCode release() = 0;
    //write into device some bytes
    virtual DeviceErrorCode write(const char* bytes, const size_t lenght)=0;
};

#endif /* DEVICE_HANDLER_H_ */
