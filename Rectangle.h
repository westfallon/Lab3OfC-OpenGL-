// Rectangle类的声明
// Created by 卢延昌 on 2019-04-27.
//

#ifndef OPENGL_RECTANGLE_H
#define OPENGL_RECTANGLE_H

#include <glew.h>
#include "Father.h"
#include <iostream>
#include <cstring>
class Rectangle :Father{
private:
    GLfloat xOfl,yOfl,xOfr,yOfr;
    bool IfFill;
    std::string Color;
public:
    static int numOfRectangle;
    Rectangle(const Rectangle& r);
    Rectangle(float p1,float p2,float p3,float p4,bool p5,std::string s);
    ~Rectangle()= default;
    void DrawRectangle();
    friend std::ostream &operator << (std::ostream &os,const Rectangle &r);
};


#endif //OPENGL_RECTANGLE_H
