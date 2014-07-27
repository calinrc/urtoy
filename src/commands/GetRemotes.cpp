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
#include <sstream>
#include <string>
#include <fstream>
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

    ifstream read (REMOTES_FILE);
    if (read.fail ())
    {
        streamHandler->write (EC_OK);
    }
    char number[4];
    long length = 0;
    Helpers::intToBigEndienBytes (length, number);
    streamHandler->write (number, sizeof(number));

    return EC_OK;
}

