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

#include "commands/NewRemote.h"
#include <string>
#include "Helpers.h"
#include "remotes/RemotesManipulator.h"

NewRemote::NewRemote()
{

}

NewRemote::~NewRemote()
{
}

ErrorCode NewRemote::execute(TRANSPORTER_HANDLER streamHandler)
{
    byte buff[4]; // first byte identifies the remote id and second remote command id

    ErrorCode eCode = streamHandler->read(buff, sizeof(buff));
    if (eCode == EC_OK)
    {
        int stringLenght = Helpers::bigEndienBytesToInt(buff);

        byte* strBuff = new byte[stringLenght + 1];
        strBuff[stringLenght] = '\0';
        eCode = streamHandler->read(strBuff, stringLenght);
        std::string strName(strBuff);
        delete[] strBuff;
        if (eCode == EC_OK)
        {
            byte remoteId = RemotesManipulator::getInstance()->addRemote(strName);
            if (remoteId < 0)
            {
                eCode = EC_DEVICE_COMMAND_FAIL;
                streamHandler->write(eCode);
            } else
            {
                streamHandler->write(eCode);
                streamHandler->write(remoteId);
            }
        }

    }
    return eCode;
}

