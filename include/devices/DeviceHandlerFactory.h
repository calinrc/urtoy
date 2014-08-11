/*
 *    DeviceHandlerFactory.h file written and maintained by Calin Cocan
 *    Created on: Aug 12, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef DEVICEHANDLERFACTORY_H_
#define DEVICEHANDLERFACTORY_H_

class DeviceHandler;
class DeviceInitInfo;

class DeviceHandlerFactory
{
public:

    static DeviceHandlerFactory* getInstance();
    DeviceHandler* getHandler(DeviceInitInfo* initInfo);

private:
    DeviceHandlerFactory();
    virtual ~DeviceHandlerFactory();

    static DeviceHandlerFactory* s_instance;
};

#endif /* DEVICEHANDLERFACTORY_H_ */
