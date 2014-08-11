/*
 *    DummyTransporter.cpp file written and maintained by Calin Cocan
 *    Created on: Jul 27, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#include "transporters/DummyTransporter.h"

DummyTransporter::DummyTransporter()
{
}

DummyTransporter::~DummyTransporter()
{
}

ErrorCode DummyTransporter::init(InitInfo* initInfo)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode DummyTransporter::read(char* buff, int buffSize)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode DummyTransporter::write(const char* buff, int buffSize)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode DummyTransporter::write(char code)
{
    return EC_NOT_IMPLEMENTED;
}

ErrorCode DummyTransporter::close()
{
    return EC_NOT_IMPLEMENTED;
}

