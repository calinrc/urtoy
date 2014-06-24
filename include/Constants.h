/*
 * commandsid.h
 *
 *  Created on: Feb 17, 2014
 *      Author: abs
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

enum CommandsId {
	LOGIN,
	LOAD_REMOTE,
	SEND_COMMAND,
	GET_REMOTES,
	RECORD_SIGNAL,
	SAVE_REMOTE,
	CLOSE
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
	EC_NOT_IMPLEMENTED
};

typedef int STREAM_HANDLER;

#endif /* CONSTANTS_H_ */
