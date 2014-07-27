/*
 *    CommandsDispatcher.h file written and maintained by Calin Cocan
 *    Created on: Feb 17, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/ >.
 *
 ********************************************************************************************************************* */

#ifndef COMMANDSFACTORY_H_
#define COMMANDSFACTORY_H_

#include <map>
#include "commands/Command.h"

using namespace std;
class CommandsDispatcher : public Command
{

public:
    static CommandsDispatcher*
    getInstance ()
    {
        return s_instance;
    }
    ;
    Command*
    getCommand (CommandsId id)
    {
        return m_commands[id];
    }
    ;

    void
    reg (Command* command);
    virtual CommandsId
    getCommandId ()
    {
        return UNKNOWN_COMMAND;
    }
    ;
    virtual void
    reg (CommandsDispatcher* factory)
    {
    }
    ;

    virtual ErrorCode
    execute (TRANSPORTER_HANDLER streamHandler);

    static void
    release ();

private:
    CommandsDispatcher () :
            m_isloggon (false)
    {
    }
    ~CommandsDispatcher ();

    static CommandsDispatcher*
    initialize ();

    static CommandsDispatcher* s_instance;

    map<CommandsId, Command*> m_commands;
    bool m_isloggon;

};

#endif /* COMMANDSFACTORY_H_ */
