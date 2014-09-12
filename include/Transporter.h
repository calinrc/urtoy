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

#ifndef TRANSPORTER_H_
#define TRANSPORTER_H_

#include "Constants.h"
class TransportInitInfo;

class Transporter
{

public:
    Transporter()
    {
    }
    virtual ~Transporter()
    {
    }

    virtual ErrorCode init(TransportInitInfo* initInfo) = 0;

    /* The read convention is that callers reads exactly the number of bytes specific in buffSize.
     * If the stream has lower number of bytes than the caller will wait untill the expected number of bytes is received*/
    virtual ErrorCode read(char* buff, int buffSize) = 0;

    /*The write convention is that the transporter writes all the bytes specified in buffSize value*/
    virtual ErrorCode write(const char* buff, int buffSize) = 0;

    /* Write a single byte */
    virtual ErrorCode write(char code) = 0;

    /*Close transporter stream*/
    virtual ErrorCode close() = 0;

};

#endif /* TRANSPORTER_H_ */
