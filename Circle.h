// Circle类的声明
// Created by 卢延昌 on 2019-04-27.
//

#ifndef OPENGL_CIRCLE_H
#define OPENGL_CIRCLE_H

#include "Father.h"
#include <iostream>
#include <cstring>

class Circle :Father{
private:
    GLfloat r,x,y;
    bool IfFill;
    std::string Color;
public:
    static int numOfCircle;
    Circle( const Circle &c);
    Circle(float p1,float p2,float p3,bool flag,std::string s);
    ~Circle()= default;
    void DrawCircle();
    friend std::ostream &operator << (std::ostream &os,const Circle &c);
};


#endif //OPENGL_CIRCLE_H
