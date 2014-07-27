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

#ifndef COMMAND_H_
#define COMMAND_H_

#include "Constants.h"
#include "ExecutorCallback.h"
#include "Transporter.h"

class CommandsDispatcher;

class Command
{

public:
    virtual
    ~Command ()
    {
    }

    virtual void
    reg (CommandsDispatcher* factory);

    virtual CommandsId
    getCommandId () = 0;

    virtual ErrorCode
    execute (TRANSPORTER_HANDLER streamHandler) = 0;
};

#endif /* COMMAND_H_ */
