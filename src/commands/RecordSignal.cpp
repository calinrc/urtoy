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

#include "commands/RecordSignal.h"
#include "remotes/RemotesManipulator.h"
#include "remotes/RemoteHandler.h"
#include "devices/DeviceHandlerFactory.h"
#include "devices/DeviceHandler.h"
#include "devices/DeviceInitInfo.h"

RecordSignal::RecordSignal()
{

}

RecordSignal::~RecordSignal()
{
}

ErrorCode RecordSignal::execute(TRANSPORTER_HANDLER streamHandler)
{
    byte buff[2]; // first byte identifies the remote id and second remote command id
    ErrorCode eCode = streamHandler->read(buff, sizeof(buff));
    if (eCode == EC_OK)
    {

        DeviceHandler* dh = DeviceHandlerFactory::getInstance()->getHandler(Config::getInstance()->getDeviceInitInfo());
        byte* buffLocation = NULL;
        size_t buffSize = 0;
        DeviceErrorCode readECode = dh->read(&buffLocation, &buffSize);
        if (readECode == DEC_OK)
        {
            RemoteHandler* remoteHandler = RemotesManipulator::getInstance()->getRemoteHandler(buff[0]);
            if (remoteHandler != NULL)
            {
                eCode = remoteHandler->storeRemoteCommandBytes(buff[1],buffLocation, buffSize);
            } else
            {
                eCode = EC_REMOTE_NOT_FOUND;
            }
        }else{
            eCode = EC_DEVICE_COMMAND_FAIL;
        }
    }
    streamHandler->write(eCode);
    return eCode;
}

