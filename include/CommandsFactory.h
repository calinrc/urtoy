/*
 * commandsfactory.h
 *
 *  Created on: Feb 18, 2014
 *      Author: abs
 */

#ifndef COMMANDSFACTORY_H_
#define COMMANDSFACTORY_H_

#include <map>
#include "commands/Command.h"

using namespace std;
class CommandsFactory{

public :
	static CommandsFactory* getInstance() {return s_instance;};
	Command* getCommand(CommandsId id){return m_commands[id];};

	void reg(Command* command);
	static void release();


private:
	CommandsFactory(){}
	~CommandsFactory();

	static CommandsFactory* initialize();

	static CommandsFactory* s_instance;

	map<CommandsId, Command*> m_commands;



};


#endif /* COMMANDSFACTORY_H_ */
