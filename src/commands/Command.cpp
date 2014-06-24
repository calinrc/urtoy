/*
 * command.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#include "commands/Command.h"
#include "CommandsFactory.h"


ErrorCode Command::execute(STREAM_HANDLER streamHandler, ExecutorCallback* callback){
	ErrorCode errCode  = this->read(streamHandler);
	if (errCode != EC_OK){
		callback->close();
		return errCode;
	}else{
		errCode = this->write(streamHandler);
		if (errCode != EC_OK){
			callback->close();
		};
		return errCode;
	}
}

void Command::reg(CommandsFactory* factory){
	factory->reg(this);
}
