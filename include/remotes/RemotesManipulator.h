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

using namespace std;

class RemotesManipulator
{
public:
    void load(string fileName);
    void save(string fileName);
    long addRemote(string remoteName);
    bool containsRemote(string remoteName);
    long getRemoteId(string remoteName);
    bool deleteRemote(string remoteName);
    std::map<long, std::string>& getRemotesIdNameMap();
    static RemotesManipulator* getInstance();

private:
    RemotesManipulator()
    {
    }
    ~RemotesManipulator()
    {
    }

    std::map<long, std::string> m_remotesIdNameMap;
    std::map<std::string, long> m_remotesNameIdMap;

    static RemotesManipulator* sInstance;

};

#endif /* REMOTESLOADER_H_ */
