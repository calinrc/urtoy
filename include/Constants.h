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

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

enum CommandsId {
	LOGIN,
	LOGOUT,
	GET_REMOTES,
	SEND_REOTE_COMMAND,
	NEW_REMOTE,
	RECORD_SIGNAL,
	LOAD_REMOTE_METAINF,
	SAVE_REMOTE_METAINF,
	UNKNOWN_COMMAND
};

enum ErrorCode {
	EC_OK,
	EC_SOCKET_FAIL,
	EC_BIND_FAIL,
	EC_LISTEN_FAIL,
	EC_ACCEPT_FAIL,
	EC_READ_FAIL,
	EC_WRITE_FAIL,
	EC_CLOSED,
	EC_IGNORED,
	EC_NOT_IMPLEMENTED
};

class Transporter;
typedef Transporter* TRANSPORTER_HANDLER;

#endif /* CONSTANTS_H_ */
