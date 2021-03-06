/*
 *    file written and maintained by Calin Cocan
 *    Created on: Feb 17, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/ >.
 *
 ********************************************************************************************************************* */

#ifndef INITINFO_H_
#define INITINFO_H_

#include <string>
#include "Config.h"

using namespace std;

class TransportInitInfo
{
public:

    friend class Config;

    int getPort()
    {
        return m_port;
    }
    string& getUserName()
    {
        return m_userName;
    }
    string& getPassword()
    {
        return m_password;
    }

private:
    TransportInitInfo() :
            m_port(1414), m_userName("test"), m_password("test")
    {
    }

    TransportInitInfo(int port, string username, string password) :
            m_port(port), m_userName(username), m_password(password)
    {
    }

private:
    int m_port;
    string m_userName;
    string m_password;
};

#endif /* INITINFO_H_ */
