/*
 *    Config.h file written and maintained by Calin Cocan
 *    Created on: Sep 9, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <map>

using namespace std;

class DeviceInitInfo;
class TransportInitInfo;

class Config
{
public:

    static Config* getInstance();

    void load(string filePath);
    DeviceInitInfo* getDeviceInitInfo();
    TransportInitInfo* getTransportInitInfo();
    map<string, string>& getAllProps();

private:
    Config();
    virtual ~Config();

    DeviceInitInfo* m_devInitInfo;
    TransportInitInfo* m_transportInitInfo;
    map<string, string> m_props;

    static Config* s_instance;

};

#endif /* CONFIG_H_ */
