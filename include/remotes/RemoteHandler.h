/*
 *    RemoteHandler.h file written and maintained by Calin Cocan
 *    Created on: Sep 7, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef REMOTEHANDLER_H_
#define REMOTEHANDLER_H_
#include <string>
#include "Constants.h"

using namespace std;

class RemoteHandler
{
public:
    RemoteHandler();
    virtual ~RemoteHandler();

    virtual bool isInit();

    virtual ErrorCode init();

    virtual ErrorCode getRemoteCommanBytes(int commandId, byte** bytesBuff, size_t* bytes_Size);

    virtual ErrorCode storeRemoteCommandBytes(int commandId, byte* bytesBuff, size_t bytes_Size);

    virtual ErrorCode storeRemoteMetaBytes(byte* bytesBuff, size_t bytes_Size);

    virtual ErrorCode storeRemoteImageBytes(byte* bytesBuff, size_t bytes_Size);

    virtual ErrorCode getRemoteMetaBytes(byte** bytesBuff, size_t* bytes_Size);

    virtual ErrorCode getRemoteImageBytes(byte** bytesBuff, size_t* bytes_Size);

    virtual ErrorCode releaseMeta();

    virtual ErrorCode releaseImage();

    virtual void release();

private:
    byte m_remoteId;
    string m_name;
    byte* m_lastCommandBytes;
    bool m_wasInitialized;

};

#endif /* REMOTEHANDLER_H_ */
