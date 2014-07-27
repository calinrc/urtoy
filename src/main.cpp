/*
 *    main.cpp written and maintained by Calin Cocan
 *    Created on: Feb 17, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/ >.
 *
 ********************************************************************************************************************* */

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

int
main ()
{

    std::string str ("calin:");
    long l = 1234;
    int a = 10;
    stringstream ss;
    ss << a;
    str += ss.str ();

    printf (str.c_str ());
    srand (time (NULL));
    return 0;
}

