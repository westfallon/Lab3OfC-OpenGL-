// Triangle类的声明
// Created by 卢延昌 on 2019-04-27.
//

#ifndef OPENGL_TRIANGLE_H
#define OPENGL_TRIANGLE_H

#include <iostream>
#include <cstring>
#include <glew.h>
#include "Father.h"
class Triangle :Father{
private:
    bool IfFill{false};
    std::string Color;
    float* x;
    float* y;
public:
    static int numOfTriangle;
    Triangle()=default;
    Triangle(float* xx,float* yy,std::string p,bool flag);
    ~Triangle()=default;
    void DrawTriangle();
    friend std::ostream &operator <<(std::ostream &os,const Triangle &t);
};


#endif //OPENGL_TRIANGLE_H
