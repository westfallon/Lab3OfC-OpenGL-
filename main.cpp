//  Lab3OfC++
//  Created by 卢延昌 on 2019/4/27.
//  Copyright © 2019 卢延昌. All rights reserved.

#include <iostream>
#include <cstring>
#include <glew.h>
#include <glfw3.h>
#include <cmath>
#include <fstream>
#include <map>
#include "Father.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#define pi 3.1415f
using namespace std;
int Father::numOfFather{0};  //类中static数据用于计数
int Circle::numOfCircle{0};
int Rectangle::numOfRectangle{0};
int Triangle::numOfTriangle{0};

Circle* cir[10]{nullptr};  //指针数组用于储存类的指针
Rectangle* rec[10]{nullptr};
Triangle* tri[10]{nullptr};
float x[3];
float y[3];

void PutIn(){    //输入函数
    bool flag;
    cout<<"enter 1 to read by file"<<endl;
    cout<<"enter 0 to read by keyboard(end by 0)"<<endl;
    cout<<"数据应满足 -1<<x,y<<1"<<endl;
    cin>>flag;
    if(flag){
        ifstream fin("in.txt",ios::in);  //读文件
        int kinds;
        while(!fin.eof()){
            fin>>kinds;
            if(kinds==1){
                float p1,p2,p3;
                string p4;
                bool p5;
                fin>>p1>>p2>>p3>>p4>>p5;
                auto* p=new Circle(p3,p1,p2,p5,p4);  //新建类并将指针存入数组中
                cir[Circle::numOfCircle]=p;
            }
            else if(kinds==2){
                for(int i=0;i<3;i++)
                    fin>>x[i]>>y[i];
                string p1;
                bool p2;
                fin>>p1>>p2;
                auto* p=new Triangle(x,y,p1,p2);
                tri[Triangle::numOfTriangle]=p;
            }
            else if(kinds==3){
                float x1,x2,y1,y2;
                string p1;
                bool p2;
                fin>>x1>>y1>>x2>>y2;
                fin>>p1>>p2;
                auto* p=new Rectangle(x1,y1,x2,y2,p2,p1);
                rec[Rectangle::numOfRectangle]=p;
            }
            else{
                cout<<"sorry,wo dont have this graph"<<endl;
                continue;
            }
        }
        fin.close();  //文件读取结束
    }
    else{
        ofstream fout("out.txt",ios::out);
        int kinds;
        while(cin>>kinds){
            if(kinds==0)
                break;    //表明输入结束
            if(kinds==1){
                float p1,p2,p3;
                string p4;
                bool p5;
                cin>>p1>>p2>>p3>>p4>>p5;
                auto* p=new Circle(p3,p1,p2,p5,p4);
                cir[Circle::numOfCircle]=p;
                fout<<*p;
            }
            else if(kinds==2){
                for(int i=0;i<3;i++)
                    cin>>x[i]>>y[i];
                string p1;
                bool p2;
                cin>>p1>>p2;
                auto* p=new Triangle(x,y,p1,p2);
                tri[Triangle::numOfTriangle]=p;
                fout<<*p;
            }
            else{
                float x1,x2,y1,y2;
                string p1;
                bool p2;
                cin>>x1>>y1>>x2>>y2;
                cin>>p1>>p2;
                auto* p=new Rectangle(x1,y1,x2,y2,p2,p1);
                rec[Rectangle::numOfRectangle]=p;
                fout<<*p;
            }
        }
        fout.close();
    }
}

int main() {
    PutIn();
    GLFWwindow *window;
    if(!glfwInit())
        return -1;
    window=glfwCreateWindow(820,820,"LabOfC++", nullptr, nullptr);  //新建窗口
    if(!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    while(!glfwWindowShouldClose(window)){   //不断刷新窗口
        for(int i=1;i<=Circle::numOfCircle;i++)    //将储存的图形输出
            cir[i]->DrawCircle();
        for(int i=1;i<=Triangle::numOfTriangle;i++)
            tri[1]->DrawTriangle();
        for(int i=1;i<=Rectangle::numOfRectangle;i++)
            rec[i]->DrawRectangle();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    for(int i=1;i<=Circle::numOfCircle;i++)  //删除指针
        delete(cir[i]);
    for(int i=1;i<=Triangle::numOfTriangle;i++)
        delete(tri[i]);
    for(int i=1;i<=Rectangle::numOfRectangle;i++)
        delete(rec[i]);
    return 0;
}
