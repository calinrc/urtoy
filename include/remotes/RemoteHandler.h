/*
 *    RemoteHandler.h file written and maintained by Calin Cocan
 *    Created on: Sep 7, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef REMOTEHANDLER_H_
#define REMOTEHANDLER_H_
#include <string>

using namespace std;

class RemoteHandler
{
public:
    RemoteHandler();
    virtual ~RemoteHandler();

    virtual void getRemoteCommanBytes(int commandId, char** bytesBuff, size_t* bytes_Size);

    virtual void release();

private:

    char m_remoteId;
    string m_name;
    char* lastCommandBytes;

};

#endif /* REMOTEHANDLER_H_ */
