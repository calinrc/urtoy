/*
 * CloseCommand.cpp
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#include "commands/CloseCommand.h"

CloseCommand::CloseCommand() {

}

CloseCommand::~CloseCommand() {
}


ErrorCode CloseCommand::read(STREAM_HANDLER streamHandler){
 return EC_NOT_IMPLEMENTED;
}

ErrorCode CloseCommand::write(STREAM_HANDLER streamHandler){
	return EC_NOT_IMPLEMENTED;
}
