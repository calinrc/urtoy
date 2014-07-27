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
class InitInfo;

class Transporter
{

public:
    Transporter ()
    {
    }
    virtual ~Transporter ()
    {
    }

    virtual ErrorCode
    init (InitInfo* initInfo) = 0;

    virtual ErrorCode
    read (char* buff, int buffSize) = 0;

    virtual ErrorCode
    write (const char* buff, int buffSize) = 0;

    virtual ErrorCode
    write (char code) = 0;

    virtual ErrorCode
    close () = 0;

};

#endif /* TRANSPORTER_H_ */
