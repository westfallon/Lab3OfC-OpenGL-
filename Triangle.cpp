//ClassOfTriangle
// Created by 卢延昌 on 2019-04-27.
//

#include "Triangle.h"
Triangle::Triangle(float *xx, float *yy, std::string p, bool flag) {
    x=xx;
    y=yy;
    IfFill=flag;
    Color=p;
    numOfTriangle++;
}
void Triangle::DrawTriangle() {
    if(IfFill)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  //填充模式
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  //描边模式
    SetUpColor(Color);
    glBegin(GL_TRIANGLES);  //开始画三角形
    glVertex2f(*x,*y);
    glVertex2f(*(x+1),*(y+1));
    glVertex2f(*(x+2),*(y+2));
    glEnd();  //画图结束
}
std::ostream &operator <<(std::ostream &os,const Triangle &t){
    os<<2<<std::endl;
    for(int i=0;i<3;i++){
        os<<*(t.x+i)<<" "<<*(t.y+i)<<" ";
    }
    std::cout<<std::endl;
    os<<t.Color<<" ";
    os<<t.IfFill<<std::endl;
}
