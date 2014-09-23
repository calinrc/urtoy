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
#include "Config.h"
#include "Helpers.h"
#include "PathResolver.h"

using namespace std;

GetRemotes::GetRemotes()
{

}

GetRemotes::~GetRemotes()
{
}

ErrorCode GetRemotes::execute(TRANSPORTER_HANDLER streamHandler)
{
    byte length = 0;
    map<byte, std::string> remotesMap;
    RemotesManipulator* rm = RemotesManipulator::getInstance();
    rm->loadRemotes(Config::getInstance()->getPathResolver()->resolve(REMOTES_FILE));
    remotesMap = rm->getRemotesIdNameMap();
    length = remotesMap.size();
    streamHandler->write(EC_OK);
    streamHandler->write(length);
    byte numberBytes[4];
    for (map<byte, string>::iterator mapIt = remotesMap.begin(); mapIt != remotesMap.end(); mapIt++)
    {
        char remoteId = mapIt->first;
        string remoteName = mapIt->second;
        streamHandler->write(remoteId);
        long remoteNameSize = remoteName.size();
        Helpers::intToBigEndienBytes(remoteNameSize, numberBytes);
        streamHandler->write(numberBytes, sizeof(numberBytes));
        streamHandler->write(remoteName.c_str(), remoteNameSize);
    }
    return EC_OK;
}

