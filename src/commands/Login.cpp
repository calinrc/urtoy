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

#include "commands/Login.h"
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "Transporter.h"
#include "Helpers.h"
#include "InitInfo.h"
#include <sstream>

using namespace std;

Login::Login ()
{

}

Login::~Login ()
{
}

static const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char get_rand_char ()
{
    return charset[rand () % sizeof(charset)];
}

string generate_random_string (size_t n)
{
    char rbuf[n];
    std::generate (rbuf, rbuf + n, &get_rand_char);
    return std::string (rbuf, n);
}

static string getResultString (InitInfo* initInfo, string nonce)
{
    stringstream ss;
    ss << initInfo->getUserName ();
    ss << ":";
    string part = initInfo->getPassword () + nonce;
    long l = 0;
    const char* szPart = part.c_str ();
    for (size_t i = 0; i < part.size (); i++)
    {
        l += szPart[i];
    }
    ss << l;
    return ss.str ();

}

ErrorCode Login::execute (TRANSPORTER_HANDLER streamHandler)
{
    ErrorCode eCode = EC_OK;
    string nonce = generate_random_string (rand () % 20);
    eCode = streamHandler->write (nonce.c_str (), nonce.size ());
    if (eCode == EC_OK)
    {
        char intBytes[4];
        streamHandler->read (intBytes, sizeof(intBytes));
        int size = Helpers::bigEndienBytesToInt (intBytes);
        if (size < 0 || size > Helpers::MAX_MEM_ALLOC_SIZE)
        {
            return EC_INVALID_LENGTH;
        } else
        {
            char* buff = new char[size];
            eCode = streamHandler->read (buff, size);
            if (eCode == EC_OK)
            {
                string credentials (buff, size);
                delete[] buff;
                if (credentials == getResultString (InitInfo::getInstangetce (), nonce))
                {
                    streamHandler->write (EC_OK);
                    return EC_OK;
                } else
                {
                    streamHandler->write (EC_LOGIN_FAIL);
                    return EC_LOGIN_FAIL;
                }
            }

        }
    }
    return EC_NOT_IMPLEMENTED;
}

