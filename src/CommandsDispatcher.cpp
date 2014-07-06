/*
 *    Dispatcher.cpp written and maintained by Calin Cocan
 *    Created on: Feb 17, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/ >.
 *
 ********************************************************************************************************************* */

#include "CommandsDispatcher.h"
#include "commands/Login.h"
#include "commands/LoadRemoteMetaInf.h"
#include "commands/SendRemoteCommand.h"
#include "commands/GetRemotes.h"
#include "commands/NewRemote.h"
#include "commands/RecordSignal.h"
#include "commands/SaveRemoteMetaInf.h"
#include "commands/Logout.h"
#include "Constants.h"
#include "Transporter.h"

CommandsDispatcher* CommandsDispatcher::s_instance =
		CommandsDispatcher::initialize();

CommandsDispatcher* CommandsDispatcher::initialize() {
	CommandsDispatcher* factory = new CommandsDispatcher();
	(new Login())->reg(factory);
	(new Logout())->reg(factory);
	(new SendRemoteCommand())->reg(factory);
	(new GetRemotes())->reg(factory);
	(new NewRemote())->reg(factory);
	(new RecordSignal())->reg(factory);
	(new LoadRemoteMetaInf())->reg(factory);
	(new SaveRemoteMetaInf())->reg(factory);
	return factory;
}

CommandsDispatcher::~CommandsDispatcher() {
	for (std::map<CommandsId, Command*>::iterator iter = m_commands.begin();
			iter != m_commands.end(); ++iter) {
		delete iter->second;
	}
	m_commands.clear();
}

ErrorCode CommandsDispatcher::execute(TRANSPORTER_HANDLER streamHandler) {
	char buff[1];
	ErrorCode eCode = streamHandler->read(buff, sizeof(buff));
	if (eCode != EC_OK && eCode != EC_CLOSED) {
		streamHandler->close();
	} else if (eCode == EC_OK) {
		if (buff[0] >= 0 && buff[0] < UNKNOWN_COMMAND) {
			Command* command = this->m_commands[buff[0]];
			eCode = command->execute(streamHandler);
		}
	}
	return eCode;
}

void CommandsDispatcher::reg(Command* command) {
	this->m_commands.insert(std::make_pair(command->getCommandId(), command));
}

void CommandsDispatcher::release() {
	delete s_instance;
	s_instance = 0;
}
