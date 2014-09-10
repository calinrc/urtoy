/*
 *    PathResolver.h file written and maintained by Calin Cocan
 *    Created on: Sep 11, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef PATHRESOLVER_H_
#define PATHRESOLVER_H_

#include <string>

using namespace std;

class PathResolver
{
public:
    PathResolver(string startPath);
    virtual ~PathResolver();
    string resolve(string name);

private:
    string m_rootPath;
};

#endif /* PATHRESOLVER_H_ */
