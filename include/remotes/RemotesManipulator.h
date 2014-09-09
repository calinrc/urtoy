/*
 *    RemotesLoader.h file written and maintained by Calin Cocan
 *    Created on: Jul 28, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef REMOTESLOADER_H_
#define REMOTESLOADER_H_

#include <map>
#include <string>
#include "Constants.h"

using namespace std;

class RemoteHandler;

class RemotesManipulator
{
public:
    void load(string fileName);
    void save(string fileName);
    byte addRemote(string remoteName);
    bool containsRemote(string remoteName);
    byte getRemoteId(string remoteName);
    bool deleteRemote(string remoteName);
    std::map<byte, std::string>& getRemotesIdNameMap();
    RemoteHandler* getRemoteHandler(byte remoteId);


    static RemotesManipulator* getInstance();

private:
    RemotesManipulator()
    {
    }
    ~RemotesManipulator()
    {
    }

    std::map<byte, std::string> m_remotesIdNameMap;
    std::map<std::string, byte> m_remotesNameIdMap;
    std::map<byte, RemoteHandler*> m_remotesIdRemoteHandlerMap;

    static RemotesManipulator* sInstance;

};

#endif /* REMOTESLOADER_H_ */
