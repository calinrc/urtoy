/*
 *    IRToyDeviceHandler.h file written and maintained by Calin Cocan
 *    Created on: Aug 12, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef IRTOYDEVICEHANDLER_H_
#define IRTOYDEVICEHANDLER_H_

#include "DeviceHandler.h"

class IRToyDeviceHandler : public DeviceHandler
{
public:
    IRToyDeviceHandler();
    virtual ~IRToyDeviceHandler();

    virtual DeviceErrorCode init(DeviceInitInfo*);
    virtual DeviceErrorCode read(char** bytesBuff, size_t* length);
    virtual DeviceErrorCode release();
    virtual DeviceErrorCode write(const char* bytes, const size_t lenght);

};

#endif /* IRTOYDEVICEHANDLER_H_ */
