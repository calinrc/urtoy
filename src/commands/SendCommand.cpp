/*
 * SendCommand.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#include "commands/SendCommand.h"

SendCommand::SendCommand() {

}

SendCommand::~SendCommand() {
}

ErrorCode SendCommand::read(STREAM_HANDLER streamHandler){
	return EC_NOT_IMPLEMENTED;
}
ErrorCode SendCommand::write(STREAM_HANDLER streamHandler){
	return EC_NOT_IMPLEMENTED;
}


