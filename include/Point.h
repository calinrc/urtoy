/*
 * point.h
 *
 *  Created on: Feb 15, 2014
 *      Author: abs
 */

#ifndef POINT_H_
#define POINT_H_


class Point{

private:
	int x, y;

public:
	Point(int x, int y){
		this->x = x;
		this->y=y;
	}

	int getX(){
		return x;
	}

	int getY(){
		return y;
	}



};



#endif /* POINT_H_ */
