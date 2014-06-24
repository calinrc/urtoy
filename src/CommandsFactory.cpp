/*
 * commandsfactory.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#include "CommandsFactory.h"
#include "commands/LoginCommand.h"
#include "commands/LoadRemoteCommand.h"
#include "commands/SendCommand.h"
#include "commands/GetRemotesCommand.h"
#include "commands/RecordSignalCommand.h"
#include "commands/SaveRemoteCommand.h"
#include "commands/CloseCommand.h"
#include "Constants.h"

CommandsFactory* CommandsFactory::s_instance = CommandsFactory::initialize();

CommandsFactory* CommandsFactory::initialize(){
	CommandsFactory* factory = new CommandsFactory();
	(new LoginCommand())->reg(factory);
	(new LoadRemoteCommand())->reg(factory);
	(new SendCommand())->reg(factory);
	(new GetRemotesCommand())->reg(factory);
	(new RecordSignalCommand())->reg(factory);
	(new SaveRemoteCommand())->reg(factory);
	(new CloseCommand())->reg(factory);
	return factory;
}

CommandsFactory::~CommandsFactory(){
	for(std::map<CommandsId, Command*>::iterator iter = m_commands.begin(); iter != m_commands.end(); ++iter)
	{
		delete iter->second;
	}
	m_commands.clear();

}

void CommandsFactory::reg(Command* command){
	this->m_commands.insert(std::make_pair(command->getCommandId(), command));
}

void CommandsFactory::release(){
	delete s_instance;
	s_instance = 0;
}


