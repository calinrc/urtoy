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

#include "commands/LoadRemoteMetaInf.h"
#include "remotes/RemotesManipulator.h"
#include "remotes/RemoteHandler.h"
#include "devices/DeviceHandlerFactory.h"
#include "devices/DeviceHandler.h"
#include "devices/DeviceInitInfo.h"
#include "Helpers.h"

LoadRemoteMetaInf::LoadRemoteMetaInf()
{

}

LoadRemoteMetaInf::~LoadRemoteMetaInf()
{
}

ErrorCode LoadRemoteMetaInf::execute(TRANSPORTER_HANDLER streamHandler)
{
    byte buff[1]; // first byte identifies the remote id
    byte numberBuff[8];
    ErrorCode eCode = streamHandler->read(buff, sizeof(buff));
    ErrorCode tempECode = EC_OK;
    if (eCode == EC_OK)
    {
        RemoteHandler* remoteHandler = RemotesManipulator::getInstance()->getRemoteHandler(buff[0]);
        if (remoteHandler != NULL)
        {
            size_t metaInfSize = 0;
            size_t imageSize = 0;
            byte* buffMetaInf = NULL;
            byte* buffImage = NULL;
            if (eCode == EC_OK)
            {

                eCode = ((tempECode = remoteHandler->getRemoteMetaBytes(&buffMetaInf, &metaInfSize)) == EC_OK) ? eCode : tempECode;
                eCode = ((tempECode = remoteHandler->getRemoteImageBytes(&buffImage, &imageSize)) == EC_OK) ? eCode : tempECode;
                if (eCode == EC_OK)
                {
                    Helpers::intToBigEndienBytes(metaInfSize, numberBuff);
                    Helpers::intToBigEndienBytes(imageSize, numberBuff + 4);

                    eCode = ((tempECode = streamHandler->write(eCode)) == EC_OK) ? eCode : tempECode;
                    eCode = ((tempECode = streamHandler->write(numberBuff, sizeof(numberBuff))) == EC_OK) ? eCode : tempECode;
                    eCode = ((tempECode = streamHandler->write(buffMetaInf, metaInfSize)) == EC_OK) ? eCode : tempECode;
                    eCode = ((tempECode = streamHandler->write(buffImage, imageSize)) == EC_OK) ? eCode : tempECode;

                    remoteHandler->releaseMeta();
                    remoteHandler->releaseImage();
                    return eCode;
                }
                remoteHandler->releaseMeta();
                remoteHandler->releaseImage();
            }
        } else
        {
            eCode = EC_REMOTE_NOT_FOUND;
        }
    }
    streamHandler->write(eCode);
    return eCode;
}
