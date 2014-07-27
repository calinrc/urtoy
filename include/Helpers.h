/*
 *    Helpers.h file written and maintained by Calin Cocan
 *    Created on: Jul 7, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef HELPERS_H_
#define HELPERS_H_

class Helpers
{
private:
    Helpers ();
    virtual
    ~Helpers ();

public:
    static long
    bigEndienBytesToInt (char bytes[]);

    static void
    intToBigEndienBytes (long val, char* bytes);

    static const int MAX_MEM_ALLOC_SIZE = 5 * 1024 * 1024; // max 5MB allocation for this app
};

#endif /* HELPERS_H_ */
