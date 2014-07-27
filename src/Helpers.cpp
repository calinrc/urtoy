/*
 *    Helpers.cpp file written and maintained by Calin Cocan
 *    Created on: Jul 7, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#include <Helpers.h>
#include <stddef.h>

Helpers::Helpers ()
{
}

Helpers::~Helpers ()
{
}

long
Helpers::bigEndienBytesToInt (char bytes[4])
{
    long retVal = 0;
    for (size_t i = 0; i < sizeof(bytes); i++)
        {
            if (bytes[i] < 0)
                {
                    return -1;
                }
        }
    retVal = (bytes[0] << 24) + (bytes[1] << 16) + (bytes[2] << 8) + (bytes[3] << 0);
    return retVal;
}

void
Helpers::intToBigEndienBytes (long val, char* bytes)
{
    bytes[0] = ((unsigned int) val >> 24) & 0xFF;
    bytes[1] = ((unsigned int) val >> 16) & 0xFF;
    bytes[2] = ((unsigned int) val >> 8) & 0xFF;
    bytes[3] = ((unsigned int) val >> 0) & 0xFF;
}

