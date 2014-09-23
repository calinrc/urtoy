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

bool RemoteHandler::isInit()
{
    return m_wasInitialized;
}

ErrorCode RemoteHandler::init()
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode RemoteHandler::getRemoteCommanBytes(int commandId, char** bytesBuff, size_t* bytes_Size)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode RemoteHandler::storeRemoteCommandBytes(int commandId, byte* bytesBuff, size_t bytes_Size)
{

    return EC_NOT_IMPLEMENTED;
}

ErrorCode RemoteHandler::storeRemoteMetaBytes(byte* bytesBuff, size_t bytes_Size)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode RemoteHandler::storeRemoteImageBytes(byte* bytesBuff, size_t bytes_Size)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode RemoteHandler::getRemoteMetaBytes(byte** bytesBuff, size_t* bytes_Size)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode RemoteHandler::getRemoteImageBytes(byte** bytesBuff, size_t* bytes_Size)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode RemoteHandler::releaseMeta()
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode RemoteHandler::releaseImage()
{
    return EC_NOT_IMPLEMENTED;
}

void RemoteHandler::release()
{
    if (m_lastCommandBytes != NULL)
    {
        delete[] m_lastCommandBytes;
        m_lastCommandBytes = NULL;
    }
}
