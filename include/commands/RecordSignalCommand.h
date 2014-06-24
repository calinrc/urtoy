/*
 * RecordSignalCommand.h
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#ifndef RECORDSIGNALCOMMAND_H_
#define RECORDSIGNALCOMMAND_H_

#include "Command.h"

class RecordSignalCommand: public Command {
public:
	RecordSignalCommand();
	virtual ~RecordSignalCommand();
	virtual CommandsId getCommandId() {return RECORD_SIGNAL;};

protected:
	virtual ErrorCode read(STREAM_HANDLER streamHandler);
	virtual ErrorCode write(STREAM_HANDLER streamHandler);
};

#endif /* RECORDSIGNALCOMMAND_H_ */
