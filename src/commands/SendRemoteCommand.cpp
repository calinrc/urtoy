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

#include "commands/SendRemoteCommand.h"

SendRemoteCommand::SendRemoteCommand()
{

}

SendRemoteCommand::~SendRemoteCommand()
{
}

ErrorCode SendRemoteCommand::execute(TRANSPORTER_HANDLER streamHandler)
{
    char buff[2]; // first byte identifies the remote if and second remote command id

    ErrorCode eCode = streamHandler->read(buff, sizeof(buff));
    if (eCode == EC_OK)
    {

    }
    return eCode;
}

