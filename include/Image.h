/**************************************************
Image is a class for a image object.
*****************************************************/
#define GLM_FORCE_CTOR_INIT
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_normalized_axis.hpp>
#include <math.h>

#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <stack>

#include <glm/gtx/string_cast.hpp>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif
#ifndef __IMAGE_H__
#define __IMAGE_H__

class Image
{
public:
    int width;
    int height;
    std::vector<glm::vec3> pixels;
    unsigned int fbo; // framebuffer object
    unsigned int tbo; // texture buffer object
    
    // Image(){    //Constructor
    //     width = 0;
    //     height = 0;
    //     // pixels.resize(0, glm::vec3(0.0));
    // }
    Image(int wid, int heig){ //copy Constructor
        // cout << wid << " " << heig << endl;
        width = wid;
        height = heig;
        // cout << wid * heig << endl;
        // pixels = std::vector<glm::vec3>(wid * heig, glm::vec3(0.0));
        // cout << pixels.size() << endl;
        pixels.resize(wid * heig, glm::vec3(0.0));
    }

    void init(void){
        glGenFramebuffers(1, &fbo);
        glGenTextures(1, &tbo);
    }

    // inline void test() {
    //     pixels.clear();
    //     for (size_t i = 0; i < 480000; i++) {
    //         pixels.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    //     }
    // }

    void draw(void){
        // cout << pixels.size() << endl;
        // cout << glm::to_string(pixels[0]) << endl;
        // test();
        glBindTexture(GL_TEXTURE_2D, tbo);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, // load texture
                     0, GL_RGB, GL_FLOAT, &pixels[0][0]);
        glBindFramebuffer(GL_READ_FRAMEBUFFER, fbo);
        glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                               GL_TEXTURE_2D, tbo, 0); // attach texture and the read frame
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);    // if not already so
        glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT,
                          GL_NEAREST); // copy framebuffer from read to write
    }


};
#endif