/*
 * SaveRemote.h
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#ifndef SAVEREMOTE_H_
#define SAVEREMOTE_H_

#include "Command.h"

class SaveRemoteCommand: public Command {
public:
	SaveRemoteCommand();
	virtual ~SaveRemoteCommand();
	virtual CommandsId getCommandId(){return SAVE_REMOTE;};

protected:
	virtual ErrorCode read(STREAM_HANDLER streamHandler);
	virtual ErrorCode write(STREAM_HANDLER streamHandler);
};

#endif /* SAVEREMOTE_H_ */
