/*
 *    RemotesManipulator.cpp file written and maintained by Calin Cocan
 *    Created on: Jul 28, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#include "remotes/RemotesManipulator.h"
#include <sstream>
#include <fstream>
#include <sstream>

using namespace std;

RemotesManipulator* RemotesManipulator::sInstance = new RemotesManipulator ();

void RemotesManipulator::init (const char* szFileNamee)
{
    ifstream read (szFileNamee);
    if (!read.fail ()) //no remote.txt file available so no remotes exists
    {
        string line;
        while (getline (read, line))
        {
            istringstream iss (line);
            long remoteId;
            string remoteName;
            if (!(iss >> remoteId >> remoteName))
            {
                break;
            }
            m_remotesMap[remoteId] = remoteName;
        }
    }
    read.close();
}

void RemotesManipulator::release(){
    delete this;
    sInstance = NULL;
}
