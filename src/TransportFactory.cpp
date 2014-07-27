/*
 *    TransportFactory.cpp file written and maintained by Calin Cocan
 *    Created on: Jul 27, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#include <stddef.h>

#include "TransportFactory.h"
#ifdef DUMMY_DEBUG
#include "transporters/DummyTransporter.h"
#else
#include "transporters/SocketTransporter.h"
#endif

TransportFactory* TransportFactory::s_instance = new TransportFactory ();

TransportFactory::TransportFactory ()
{
}
TransportFactory::~TransportFactory ()
{
}

void TransportFactory::release ()
{
    delete this;
    s_instance = NULL;
}

Transporter* TransportFactory::getTransporter (InitInfo* initInfo)
{
    Transporter* transporter = NULL;
#ifdef DUMMY_DEBUG
    transporter = new DummyTransporter ();
#else
    transporter = new SocketTransporter ();
#endif
    transporter->init (initInfo);
    return transporter;
}

