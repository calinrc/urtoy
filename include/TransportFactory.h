/*
 *    TransportFactory.h file written and maintained by Calin Cocan
 *    Created on: Jul 27, 2014
 *
 * This work is free: you can redistribute it and/or modify it under the terms of Apache License Version 2.0
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the License for more details.
 * You should have received a copy of the License along with this program. If not, see <http://choosealicense.com/licenses/apache-2.0/>.

 ********************************************************************************************************************* */

#ifndef TRANSPORTFACTORY_H_
#define TRANSPORTFACTORY_H_

#include "Transporter.h"

class TransportFactory
{

public:
    void release();

    Transporter* getTransporter(InitInfo* initInfo);

private:
    TransportFactory();
    virtual ~TransportFactory();

    static TransportFactory* getInstance()
    {
        return s_instance;
    }
    static TransportFactory* s_instance;

};

#endif /* TRANSPORTFACTORY_H_ */
