// ClassOfCircle
// Created by 卢延昌 on 2019-04-27.
//
#include <utility>
#include "Circle.h"
#include <cmath>
#include <iostream>
#define pi 3.1415
Circle::Circle(const Circle &c) {  //拷贝构造函数
    r=c.r;
    x=c.x;
    y=c.y;
    IfFill=c.IfFill;
    Color=c.Color;
    numOfCircle++;
}
Circle::Circle(float p1, float p2, float p3, bool flag,std::string s) {
    r=p1;
    x=p2;
    y=p3;
    IfFill=flag;
    Color=std::move(s);
    numOfCircle++;
}
void Circle::DrawCircle(){
    if(!IfFill)
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);  //描边
    else
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);  //填充
    glBegin(GL_POLYGON);  //开始画多边形（足够短的直线画圆）
    SetUpColor(Color);
    for(int i=0; i<100; ++i)
        glVertex2f(x+r*cos(2*pi/100*i), y+r*sin(2*pi/100*i));
    glEnd();
}
std::ostream &operator << (std::ostream &os,const Circle &c){
    os<<1<<std::endl;
    os<<c.x<<" "<<c.y<<" "<<c.r<<std::endl;
    os<<c.Color<<" "<<c.IfFill<<std::endl;
}
