/*
 * LoadRemoteCommand.h
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#ifndef LOADREMOTECOMMAND_H_
#define LOADREMOTECOMMAND_H_

#include "Command.h"

class LoadRemoteCommand: public Command {
public:
	LoadRemoteCommand();
	virtual ~LoadRemoteCommand();

	virtual CommandsId getCommandId() {return LOAD_REMOTE;};

protected:
	virtual ErrorCode read(STREAM_HANDLER streamHandler);
	virtual ErrorCode write(STREAM_HANDLER streamHandler);

};

#endif /* LOADREMOTECOMMAND_H_ */
