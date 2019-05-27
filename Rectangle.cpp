//ClassOfRectangle
// Created by 卢延昌 on 2019-04-27.
//

#include "Rectangle.h"
#include "Father.h"
Rectangle::Rectangle(const Rectangle &r) {  //拷贝构造函数
    xOfl=r.xOfl;
    yOfl=r.yOfl;
    xOfr=r.xOfr;
    yOfr=r.yOfr;
    numOfRectangle++;
}
Rectangle::Rectangle(float p1, float p2, float p3, float p4, bool p5,std::string s) : Father(p1,p2){
    xOfl=p1;
    yOfl=p2;
    xOfr=p3;
    yOfr=p4;
    IfFill=p5;
    Color=s;
    numOfRectangle++;
}
void Rectangle::DrawRectangle(){
    if(IfFill)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  //填充
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  //描边
    SetUpColor(Color);
    glBegin(GL_POLYGON);  //开始画多边形（这里是矩形）
    glVertex2f(xOfl,yOfl);
    glVertex2f(xOfr,yOfl);
    glVertex2f(xOfr,yOfl);
    glVertex2f(xOfr,yOfr);
    glVertex2f(xOfr,yOfr);
    glVertex2f(xOfl,yOfr);
    glVertex2f(xOfl,yOfr);
    glVertex2f(xOfl,yOfl);
    glEnd();  //结束画图
}
std::ostream &operator << (std::ostream &os,const Rectangle &r){
    os<<3<<std::endl;
    os<<r.xOfl<<" "<<r.yOfl<<" "<<r.xOfr<<" "<<r.yOfr<<std::endl;
    os<<r.Color<<" "<<r.IfFill<<std::endl;
}
