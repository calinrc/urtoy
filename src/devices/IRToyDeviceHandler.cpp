/*
 *    IRToyDeviceHandler.cpp file written and maintained by Calin Cocan
 *    Created on: Aug 12, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#include "devices/IRToyDeviceHandler.h"

IRToyDeviceHandler::IRToyDeviceHandler()
{
}

IRToyDeviceHandler::~IRToyDeviceHandler()
{
    this->release();
}

DeviceErrorCode IRToyDeviceHandler::init(DeviceInitInfo*)
{
    return DEC_NOT_IMPLEMENTED;
}
DeviceErrorCode IRToyDeviceHandler::read(char** bytesBuff, size_t* length)
{
    return DEC_NOT_IMPLEMENTED;
}
DeviceErrorCode IRToyDeviceHandler::release()
{
    return DEC_NOT_IMPLEMENTED;
}
DeviceErrorCode IRToyDeviceHandler::write(const char* bytes, const size_t lenght)
{
    return DEC_NOT_IMPLEMENTED;
}
