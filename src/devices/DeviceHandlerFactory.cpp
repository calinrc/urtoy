/*
 *    DeviceHandlerFactory.cpp file written and maintained by Calin Cocan
 *    Created on: Aug 12, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#include "devices/DeviceHandlerFactory.h"
#include "devices/DeviceHandler.h"
#include "devices/DeviceInitInfo.h"
#include "devices/IRToyDeviceHandler.h"

DeviceHandlerFactory* DeviceHandlerFactory::s_instance = new DeviceHandlerFactory();

DeviceHandlerFactory::DeviceHandlerFactory()
{

}

DeviceHandlerFactory::~DeviceHandlerFactory()
{
}

DeviceHandler* getHandler(DeviceInitInfo* initInfo)
{
    DeviceHandler* retVal = new IRToyDeviceHandler();
    retVal->init(initInfo);
    return retVal;
}

