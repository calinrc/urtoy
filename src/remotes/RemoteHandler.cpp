/*
 *    RemoteHandler.cpp file written and maintained by Calin Cocan
 *    Created on: Sep 7, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#include <remotes/RemoteHandler.h>

RemoteHandler::RemoteHandler() :
        m_remoteId(0), m_lastCommandBytes(NULL), m_wasInitialized(false)
{

}

RemoteHandler::~RemoteHandler()
{
}

ErrorCode RemoteHandler::getRemoteCommanBytes(int commandId, char** bytesBuff, size_t* bytes_Size)
{
    return EC_NOT_IMPLEMENTED;
}

bool RemoteHandler::isInit()
{
    return m_wasInitialized;
}

ErrorCode RemoteHandler::init()
{
    return EC_NOT_IMPLEMENTED;
//TODO implement this
}

void RemoteHandler::release()
{
    if (m_lastCommandBytes != NULL)
    {
        delete[] m_lastCommandBytes;
        m_lastCommandBytes = NULL;
    }
}
