/*
 * LoginCommand.h
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#ifndef LOGINCOMMAND_H_
#define LOGINCOMMAND_H_

#include "Command.h"

class LoginCommand : public Command{
public:
	LoginCommand();
	virtual ~LoginCommand();

	virtual CommandsId getCommandId() {return LOGIN;};

protected:
	virtual ErrorCode read(STREAM_HANDLER streamHandler);
	virtual ErrorCode write(STREAM_HANDLER streamHandler);
};

#endif /* LOGINCOMMAND_H_ */
