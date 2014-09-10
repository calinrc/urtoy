/*
 *    Config.cpp file written and maintained by Calin Cocan
 *    Created on: Sep 9, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#include <fstream>
#include <stdlib.h>
#include "Config.h"
#include "TransportInitInfo.h"
#include "devices/DeviceInitInfo.h"
#include "PathResolver.h"
#include "Constants.h"

Config* Config::s_instance = new Config();

Config::Config() :
        m_devInitInfo(NULL), m_transportInitInfo(NULL), m_pathResolver(NULL)
{
}

Config::~Config()
{
    if (m_devInitInfo != NULL)
    {
        delete m_devInitInfo;
    }
    if (m_transportInitInfo != NULL)
    {
        delete m_transportInitInfo;
    }
    if (m_pathResolver != NULL)
    {
        delete m_pathResolver;
    }

}

Config* Config::getInstance()
{
    return s_instance;
}

void Config::load(string path)
{
    if (m_devInitInfo != NULL)
    {
        delete m_devInitInfo;
        m_devInitInfo = NULL;
    }
    if (m_transportInitInfo != NULL)
    {
        delete m_transportInitInfo;
        m_transportInitInfo = NULL;
    }
    if (m_pathResolver != NULL)
    {
        delete m_pathResolver;
        m_pathResolver = NULL;
    }

    ifstream read(path.c_str());
    if (!read.fail()) //no config.properties file available
    {
        string line;
        while (getline(read, line))
        {
            if (!line.empty() && line[0] != '#')
            {
                size_t eqlPos = line.find('=');
                if (eqlPos != string::npos)
                {
                    m_props[line.substr(0, eqlPos)] = line.substr(eqlPos + 1);
                }
            }
        }
    }
    read.close();

    string deviceuri = m_props[DEVICEURI];
    m_devInitInfo = deviceuri.empty() ? new DeviceInitInfo() : new DeviceInitInfo(deviceuri);

    string portstr = m_props[PORT];
    string username = m_props[USERNAME];
    string password = m_props[PASSWORD];

    m_transportInitInfo =
            (portstr.empty() || username.empty() || password.empty()) ?
                    new TransportInitInfo() : new TransportInitInfo(atoi(portstr.c_str()), username, password);
    m_pathResolver = new PathResolver(getProp(ROOTPATH, "."));

}

map<string, string> &Config::getAllProps()
{
    return m_props;
}

string Config::getProp(string key)
{
    return m_props[key];
}

string Config::getProp(string key, string defaultValue)
{
    string val = m_props[key];
    return !val.empty() ? val : defaultValue;
}

int Config::getPropAsInt(string key)
{
    string val = m_props[key];
    if (!val.empty())
    {
        return atoi(val.c_str());
    } else
    {
        return -1;
    }
}

DeviceInitInfo * Config::getDeviceInitInfo()
{
    return m_devInitInfo;
}

TransportInitInfo * Config::getTransportInitInfo()
{
    return m_transportInitInfo;
}

PathResolver* Config::getPathResolver()
{
    return m_pathResolver;
}

