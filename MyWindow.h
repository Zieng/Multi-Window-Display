//
// Created by zieng on 11/6/15.
//

#ifndef MULTI_SCREENDISPLAY_MYWINDOW_H
#define MULTI_SCREENDISPLAY_MYWINDOW_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string.h>  // for memcmp()
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class MyWindow
{
public:
    MyWindow(unsigned int w, unsigned int h,string t);
    ~MyWindow();
    
    // setter and getter
    void set_window_size(unsigned int w,unsigned int h);
    void set_window_title(string s);
    void set_projection_matrix(glm::mat4 p);
    void set_view_matrix(glm::mat4 v);

    unsigned int get_width();
    unsigned int get_height();
    string get_title();
    glm::mat4 get_projection_matrix();
    glm::mat4 get_view_matrix();

private:
    GLFWwindow * pWindow;
    unsigned int width,height;
    string title;
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
};


#endif //MULTI_SCREENDISPLAY_MYWINDOW_H
