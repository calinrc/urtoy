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

#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "remotes/RemotesManipulator.h"
#include "remotes/RemoteHandler.h"

using namespace std;

RemotesManipulator* RemotesManipulator::sInstance = new RemotesManipulator();

RemotesManipulator* RemotesManipulator::getInstance()
{
    return sInstance;
}

std::map<byte, std::string>& RemotesManipulator::getRemotesIdNameMap()
{
    return m_remotesIdNameMap;
}

void RemotesManipulator::loadRemotes(string fileName)
{
    ifstream read(fileName.c_str());
    if (!read.fail()) //no remote.txt file available so no remotes exists
    {
        string line;
        while (getline(read, line))
        {
            istringstream iss(line);
            byte remoteId;
            string remoteName;
            if (!(iss >> remoteId >> remoteName))
            {
                break;
            }
            m_remotesIdNameMap[remoteId] = remoteName;
            m_remotesIdRemoteHandlerMap[remoteId] = new RemoteHandler();
            m_remotesNameIdMap[remoteName] = remoteId;
        }
    }
    read.close();
}

void RemotesManipulator::saveRemotes(string fileName)
{
    ofstream write(fileName.c_str());
    if (!write.fail()) //no remote.txt file available so no remotes exists
    {
        for (map<byte, std::string>::iterator it = m_remotesIdNameMap.begin(); it != m_remotesIdNameMap.end(); it++)
        {
            write << (int) it->first << it->second << "\n";
        }
    }
    write.close();
}

byte RemotesManipulator::addRemote(string remoteName)
{
    if (!this->containsRemote(remoteName))
    {
        return getRemoteId(remoteName);
    } else
    {
        int nextId = 256;
        for (int i = 0; i < 256; i++)
        {
            if (m_remotesIdNameMap[(byte)i].empty())
            {
                nextId = i;
                break; //newId found
            }
        }
        if (nextId == 256)
        {
            return -1; // next new remote ID was not found
        } else
        {
            m_remotesIdRemoteHandlerMap[nextId] = new RemoteHandler();
            m_remotesNameIdMap[remoteName] = nextId;
            m_remotesIdNameMap[nextId] = remoteName;
            return nextId;
        }

    }
}

bool RemotesManipulator::containsRemote(string remoteName)
{
    return m_remotesNameIdMap.find(remoteName) != m_remotesNameIdMap.end();
}

byte RemotesManipulator::getRemoteId(string remoteName)
{
    byte retVal = -1;
    map<string, byte>::iterator it = m_remotesNameIdMap.find(remoteName);
    if (it != m_remotesNameIdMap.end())
    {
        retVal = it->second;
    }
    return retVal;
}

bool RemotesManipulator::deleteRemote(string remoteName)
{
    map<string, byte>::iterator it = m_remotesNameIdMap.find(remoteName);
    if (it != m_remotesNameIdMap.end())
    {
        byte foundId = it->second;
        m_remotesNameIdMap.erase(it);
        m_remotesIdNameMap.erase(foundId);
        return true;
    }
    return false;
}

RemoteHandler* RemotesManipulator::getRemoteHandler(byte remoteId)
{
    RemoteHandler* result = m_remotesIdRemoteHandlerMap[remoteId];
    if (result != NULL)
    {
        if (!result->isInit())
        {
            ErrorCode code = result->init();
            if (code != EC_OK)
            {
                result = NULL;
            }
        }
    }
    return result;
}
