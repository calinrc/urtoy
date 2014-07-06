/*
*    file written and maintained by Calin Cocan
*    Created on: Feb 17, 2014
*
* This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
*
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the License for more details.
* You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/ >.
*
********************************************************************************************************************* */

#ifndef LOGINCOMMAND_H_
#define LOGINCOMMAND_H_

#include "Command.h"

class Login : public Command{
public:
	Login();
	virtual ~Login();

	virtual CommandsId getCommandId() {return LOGIN;};

protected:
	virtual ErrorCode execute(TRANSPORTER_HANDLER streamHandler);
};

#endif /* LOGINCOMMAND_H_ */
