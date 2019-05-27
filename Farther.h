// 父类的声明
// Created by 卢延昌 on 2019-04-27.
//

#ifndef OPENGL_FATHER_H
#define OPENGL_FATHER_H

#include <glew.h>
#include <iostream>
#include <cstring>

class Father{
public:
    float x0,y0;
    static int numOfFather;
    Father();
    Father(float p1,float p2);
    ~Father();
    void SetUpColor(const std::string& s);
};


#endif //OPENGL_FATHER_H
