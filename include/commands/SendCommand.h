/*
 * SendCommand.h
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#ifndef SENDCOMMAND_H_
#define SENDCOMMAND_H_

#include "Command.h"

class SendCommand: public Command {
public:
	SendCommand();
	virtual ~SendCommand();
	virtual CommandsId getCommandId(){return SEND_COMMAND;};

protected:
	virtual ErrorCode read(STREAM_HANDLER streamHandler);
	virtual ErrorCode write(STREAM_HANDLER streamHandler);
};

#endif /* SENDCOMMAND_H_ */
