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

#include "transporters/SocketTransporter.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>

SocketTransporter::SocketTransporter() :
        m_initInfo(NULL), m_socketHandler(0), m_sockfd(0), m_clilen(0)
{
}

SocketTransporter::~SocketTransporter()
{
    if (m_socketHandler != 0)
    {
        ::close(m_socketHandler);
        m_socketHandler = 0;
    }
}

ErrorCode SocketTransporter::init(InitInfo* initInfo)
{
    this->m_initInfo = initInfo;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_sockfd < 0)
    {
        perror("ERROR opening socket");
        return EC_SOCKET_FAIL;
    }
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(m_initInfo->getPort());

    /* Now bind the host address using bind() call.*/
    if (bind(m_sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        return EC_BIND_FAIL;
    }

    /* Now start listening for the clients, here process will
     * go in sleep mode and will wait for the incoming connection
     */
    listen(m_sockfd, 5);
    m_clilen = sizeof(m_cli_addr);
    return this->launch(initInfo);
}

ErrorCode SocketTransporter::launch(InitInfo* initInfo)
{
    //char buffer[256];
    //int n = 0;

    /* Accept actual connection from the client */
    m_socketHandler = accept(m_sockfd, (struct sockaddr *) &m_cli_addr, &m_clilen);
    if (m_socketHandler < 0)
    {
        perror("ERROR on accept");
        return EC_ACCEPT_FAIL;
    }
    bool end = false;
    int commandId = 0;
    while (!end)
    {
        if (::read(m_socketHandler, &commandId, 1) < 0)
        {

        }
    }
    if (m_socketHandler != 0)
    {
        ::close(m_socketHandler);
        m_socketHandler = 0;
    }

    return EC_OK;

}

ErrorCode SocketTransporter::read(char* buff, int buffSize)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode SocketTransporter::write(const char* buff, int buffSize)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode SocketTransporter::write(char code)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode SocketTransporter::close()
{
    return EC_NOT_IMPLEMENTED;
}

