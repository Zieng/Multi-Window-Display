//
// Created by zieng on 11/6/15.
//

#include "MyWindow.h"

MyWindow::MyWindow(unsigned int w, unsigned int h, string t):width(w),height(h),title(t)
{
    pWindow = glfwCreateWindow(w,h,t.c_str(),NULL,NULL);
    if(pWindow==NULL)
    {
        cout<<"glfwCreateWindow failed!"<<endl;
    }
    projectionMatrix = glm::mat4(1);
    viewMatrix = glm::mat4(1);
}

MyWindow::~MyWindow()
{
    glfwDestroyWindow(pWindow);
}

unsigned int MyWindow::get_height()
{
    return height;
}

glm::mat4 MyWindow::get_projection_matrix()
{
    return projectionMatrix;
}

string MyWindow::get_title()
{
    return title;
}

glm::mat4 MyWindow::get_view_matrix()
{
    return viewMatrix;
}

unsigned int MyWindow::get_width()
{
    return width;
}

void MyWindow::set_projection_matrix(glm::mat4 p)
{
    projectionMatrix = p;
}

void MyWindow::set_view_matrix(glm::mat4 v)
{
    viewMatrix = v;
}

void MyWindow::set_window_size(unsigned int w, unsigned int h)
{
    width = w;
    height = h;
}

void MyWindow::set_window_title(string s)
{
    title = s;
}