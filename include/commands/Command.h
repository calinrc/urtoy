/*
 * command.h
 *
 *  Created on: Feb 18, 2014
 *      Author: abs
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "Constants.h"
#include "ExecutorCallback.h"

class CommandsFactory;

class Command{

public:
	virtual ~Command(){}

	virtual ErrorCode execute(STREAM_HANDLER streamHandler, ExecutorCallback* callback);
	virtual void reg(CommandsFactory* factory);

	virtual CommandsId getCommandId() = 0;

protected:
	virtual ErrorCode read(STREAM_HANDLER streamHandler) = 0;
	virtual ErrorCode write(STREAM_HANDLER streamHandler) = 0;
};


#endif /* COMMAND_H_ */
