/*
 *    GetRemotes.cpp file written and maintained by Calin Cocan
 *    Created on: Feb 17, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/ >.
 *
 ********************************************************************************************************************* */

#include "commands/GetRemotes.h"
#include "remotes/RemotesManipulator.h"
#include <sstream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

#include "Helpers.h"

using namespace std;

GetRemotes::GetRemotes ()
{

}

GetRemotes::~GetRemotes ()
{
}

ErrorCode GetRemotes::execute (TRANSPORTER_HANDLER streamHandler)
{

    long length = 0;
    map<long, std::string> remotesMap;
    RemotesManipulator* rm = RemotesManipulator::getInstance ();
    rm->init (REMOTES_FILE);
    remotesMap = rm->getRemotesMap ();
    length = remotesMap.size ();
    streamHandler->write (EC_OK);
    char number[4];
    Helpers::intToBigEndienBytes (length, number);
    streamHandler->write (number, sizeof(number));
    for (map<long, string>::iterator mapIt = remotesMap.begin (); mapIt != remotesMap.end (); mapIt++)
    {
        long remoteId = mapIt->first;
        string remoteName = mapIt->second;
        Helpers::intToBigEndienBytes (remoteId, number);
        streamHandler->write (number, sizeof(number));
        long remoteSizeName = remoteName.size ();
        Helpers::intToBigEndienBytes (remoteSizeName, number);
        streamHandler->write (number, sizeof(number));
        streamHandler->write (remoteName.c_str (), remoteSizeName);
    }
    return EC_OK;
}

