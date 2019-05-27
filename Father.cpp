// ClassOfFather(abstract class)
// Created by 卢延昌 on 2019-04-27.
//

#include "Father.h"
#include <iostream>
Father::Father() = default;
Father::Father(float p1, float p2) {
    x0=p1;
    y0=p2;
    numOfFather++;
}
Father::~Father() = default;
void Father::SetUpColor(const std::string &s) {  //设置颜色
        if(s=="white")
            glColor3f(1.0f,1.0f,1.0f);
        else if(s=="red")
            glColor3f(1.0f,0.0f,0.0f);
        else if(s=="green")
            glColor3f(0.0f,1.0f,0.0f);
        else if(s=="blue")
            glColor3f(0.0f,0.0f,1.0f);
        else if(s=="yellow")
            glColor3f(1.0f,1.0f,0.0f);
        else if(s=="pink")
            glColor3f(1.0f,0.0f,1.0f);
        else if(s=="black")
            glColor3f(0.0f,0.0f,0.0f);
    }
