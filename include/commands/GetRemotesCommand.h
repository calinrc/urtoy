/*
 * GetRemotes.h
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#ifndef GETREMOTES_H_
#define GETREMOTES_H_

#include "Command.h"

class GetRemotesCommand: public Command {
public:
	GetRemotesCommand();
	virtual ~GetRemotesCommand();
	virtual CommandsId getCommandId() {return GET_REMOTES;};

protected:
	virtual ErrorCode read(STREAM_HANDLER streamHandler);
	virtual ErrorCode write(STREAM_HANDLER streamHandler);
};

#endif /* GETREMOTES_H_ */
