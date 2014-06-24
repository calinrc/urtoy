/*
 * executorcallback.h
 *
 *  Created on: Feb 21, 2014
 *      Author: abs
 */

#ifndef EXECUTORCALLBACK_H_
#define EXECUTORCALLBACK_H_

class ExecutorCallback{

public:
	virtual ~ExecutorCallback(){}

	virtual void close() = 0;

};


#endif /* EXECUTORCALLBACK_H_ */
