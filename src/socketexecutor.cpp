/*
 * socketexecutor.cpp
 *
 *  Created on: Feb 17, 2014
 *      Author: abs
 */

#include "SocketExecutor.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>

SocketExecutor::SocketExecutor(InitInfo& initInfo, LoginInfo& loginInfo) :
		m_initInfo(initInfo), m_loginInfo(loginInfo), m_socketHandler(0), m_sockfd(
				0), m_clilen(0) {
}

SocketExecutor::~SocketExecutor() {
	if (m_socketHandler != 0) {
		close(m_socketHandler);
		m_socketHandler = 0;
	}
}

ErrorCode SocketExecutor::init() {
	struct sockaddr_in serv_addr;

	/* First call to socket() function */
	m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_sockfd < 0) {
		perror("ERROR opening socket");
		return EC_SOCKET_FAIL;
	}
	/* Initialize socket structure */
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(m_initInfo.getPort());

	/* Now bind the host address using bind() call.*/
	if (bind(m_sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR on binding");
		return EC_BIND_FAIL;
	}

	/* Now start listening for the clients, here process will
	 * go in sleep mode and will wait for the incoming connection
	 */
	listen(m_sockfd, 5);
	m_clilen = sizeof(m_cli_addr);

	return EC_OK;
}

ErrorCode SocketExecutor::launch() {
	//char buffer[256];
	//int n = 0;

	/* Accept actual connection from the client */
	m_socketHandler = accept(m_sockfd, (struct sockaddr *) &m_cli_addr,
			&m_clilen);
	if (m_socketHandler < 0) {
		perror("ERROR on accept");
		return EC_ACCEPT_FAIL;
	}
	bool end = false;
	int commandId = 0;
	while(!end){
		if (read(m_socketHandler, &commandId, 1)<0){

		}
	}
	if (m_socketHandler != 0) {
		close(m_socketHandler);
		m_socketHandler = 0;
	}

	return EC_OK;

}

