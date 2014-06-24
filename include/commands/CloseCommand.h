/*
 * CloseCommand.h
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#ifndef CLOSECOMMAND_H_
#define CLOSECOMMAND_H_

#include "Command.h"

class CloseCommand: public Command {
public:
	CloseCommand();
	virtual ~CloseCommand();
	virtual CommandsId getCommandId() {return CLOSE;};

protected:
	virtual ErrorCode read(STREAM_HANDLER streamHandler);
	virtual ErrorCode write(STREAM_HANDLER streamHandler);
};

#endif /* CLOSECOMMAND_H_ */
