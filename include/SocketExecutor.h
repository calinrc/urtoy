/*
 * socketexecutor.h
 *
 *  Created on: Feb 17, 2014
 *      Author: abs
 */

#ifndef SOCKETEXECUTOR_H_
#define SOCKETEXECUTOR_H_

#include "InitInfo.h"
#include <netinet/in.h>
#include "Constants.h"


class SocketExecutor{

public:
	SocketExecutor(InitInfo& initInfo, LoginInfo& loginInfo);
	~SocketExecutor();

	ErrorCode init();
	ErrorCode launch();



private:
	InitInfo& m_initInfo;
	LoginInfo m_loginInfo;
	STREAM_HANDLER m_socketHandler;
	int m_sockfd;
	struct sockaddr_in m_cli_addr;
	socklen_t m_clilen;


};


#endif /* SOCKETEXECUTOR_H_ */
