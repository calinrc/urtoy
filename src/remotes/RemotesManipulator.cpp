/*
 *    RemotesManipulator.cpp file written and maintained by Calin Cocan
 *    Created on: Jul 28, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#include "remotes/RemotesManipulator.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

RemotesManipulator* RemotesManipulator::sInstance = new RemotesManipulator();

RemotesManipulator* RemotesManipulator::getInstance()
{
    return sInstance;
}

std::map<char, std::string>& RemotesManipulator::getRemotesIdNameMap()
{
    return m_remotesIdNameMap;
}

void RemotesManipulator::load(string fileName)
{
    ifstream read(fileName.c_str());
    if (!read.fail()) //no remote.txt file available so no remotes exists
    {
        string line;
        while (getline(read, line))
        {
            istringstream iss(line);
            char remoteId;
            string remoteName;
            if (!(iss >> remoteId >> remoteName))
            {
                break;
            }
            m_remotesIdNameMap[remoteId] = remoteName;
            m_remotesNameIdMap[remoteName] = remoteId;
        }
    }
    read.close();
}

void RemotesManipulator::save(string fileName)
{
    ofstream write(fileName.c_str());
    if (!write.fail()) //no remote.txt file available so no remotes exists
    {
        for (map<char, std::string>::iterator it = m_remotesIdNameMap.begin(); it != m_remotesIdNameMap.end(); it++)
        {
            write << (int) it->first << it->second << "\n";
        }
    }
    write.close();
}

char RemotesManipulator::addRemote(string remoteName)
{
    if (!this->containsRemote(remoteName))
    {
        return getRemoteId(remoteName);
    } else
    {
        int nextId = rand();
        m_remotesNameIdMap[remoteName] = nextId % 256;
        m_remotesIdNameMap[nextId] = remoteName;
    }
    return 0;
}

bool RemotesManipulator::containsRemote(string remoteName)
{
    return m_remotesNameIdMap.find(remoteName) != m_remotesNameIdMap.end();
}

char RemotesManipulator::getRemoteId(string remoteName)
{
    char retVal = -1;
    map<string, char>::iterator it = m_remotesNameIdMap.find(remoteName);
    if (it != m_remotesNameIdMap.end())
    {
        retVal = it->second;
    }
    return retVal;
}

bool RemotesManipulator::deleteRemote(string remoteName)
{
    map<string, char>::iterator it = m_remotesNameIdMap.find(remoteName);
    if (it != m_remotesNameIdMap.end())
    {
        char foundId = it->second;
        m_remotesNameIdMap.erase(it);
        m_remotesIdNameMap.erase(foundId);
        return true;
    }
    return false;
}
