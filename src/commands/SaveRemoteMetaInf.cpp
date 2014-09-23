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

#include "commands/SaveRemoteMetaInf.h"
#include "remotes/RemotesManipulator.h"
#include "remotes/RemoteHandler.h"
#include "devices/DeviceHandlerFactory.h"
#include "devices/DeviceHandler.h"
#include "devices/DeviceInitInfo.h"
#include "Helpers.h"

SaveRemoteMetaInf::SaveRemoteMetaInf()
{

}

SaveRemoteMetaInf::~SaveRemoteMetaInf()
{
}

ErrorCode SaveRemoteMetaInf::execute(TRANSPORTER_HANDLER streamHandler)
{
    byte buff[9]; // first byte identifies the remote id,  second 4 bytes the length of region files , third 4 bytes the length of image file
    ErrorCode eCode = streamHandler->read(buff, sizeof(buff));
    if (eCode == EC_OK)
    {
        long metaInfSize = Helpers::bigEndienBytesToInt(buff + 1);
        long imageSize = Helpers::bigEndienBytesToInt(buff + 5);
        if (metaInfSize <= 0 || metaInfSize > MAX_FILE_SIZE || imageSize <= 0 || imageSize > MAX_FILE_SIZE)
        {
            eCode = EC_INVALID_LENGTH;
        } else
        {
            byte* readBuff = new byte[max(metaInfSize, imageSize)];
            eCode = streamHandler->read(readBuff, metaInfSize);

            if (eCode == EC_OK)
            {
                RemoteHandler* remoteHandler = RemotesManipulator::getInstance()->getRemoteHandler(buff[0]);
                if (remoteHandler != NULL)
                {
                    eCode = remoteHandler->storeRemoteMetaBytes(readBuff, metaInfSize);
                } else
                {
                    eCode = EC_REMOTE_NOT_FOUND;
                }

                eCode = streamHandler->read(readBuff, imageSize);
                if (eCode == EC_OK)
                {
                    if (remoteHandler != NULL)
                    {
                        eCode = remoteHandler->storeRemoteImageBytes(readBuff, imageSize);
                    } else
                    {
                        eCode = EC_REMOTE_NOT_FOUND;
                    }
                }
            }
            delete[] readBuff;
        }
    }
    streamHandler->write(eCode);
    return eCode;
}
