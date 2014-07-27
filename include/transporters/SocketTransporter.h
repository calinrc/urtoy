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

#ifndef SOCKETEXECUTOR_H_
#define SOCKETEXECUTOR_H_

#include "InitInfo.h"
#include <netinet/in.h>
#include "Constants.h"
#include "Transporter.h"

class SocketTransporter: public Transporter
{

public:
    SocketTransporter ();
    ~SocketTransporter ();

    virtual ErrorCode init (InitInfo* initInfo);

    virtual ErrorCode read (char* buff, int buffSize);

    virtual ErrorCode write (const char* buff, int buffSize);

    virtual ErrorCode write (char code);

    virtual ErrorCode close ();

private:
    ErrorCode launch (InitInfo* initInfo);
    InitInfo* m_initInfo;
    int m_socketHandler;
    int m_sockfd;
    struct sockaddr_in m_cli_addr;
    socklen_t m_clilen;

};

#endif /* SOCKETEXECUTOR_H_ */
