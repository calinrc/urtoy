/*
 *    RemoteInitInfo.h file written and maintained by Calin Cocan
 *    Created on: Aug 11, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef DEVICEINITINFO_H_
#define DEVICEINITINFO_H_

#include <string>
#include "Config.h"

using namespace std;
class DeviceInitInfo
{
    friend class Config;
public:

    string getConnectionURI()
    {
        return m_uri;
    }

private:

    DeviceInitInfo() :
            m_uri("/dev/com123")
    {
    }

    DeviceInitInfo(string uri) :
            m_uri(uri)
    {
    }
    virtual ~DeviceInitInfo()
    {
    }

    string m_uri;

};

#endif /* DEVICEINITINFO_H_ */
