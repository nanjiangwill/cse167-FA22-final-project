/**************************************************
Cube is subclass class of Geometry
that represents a 3D cube.
*****************************************************/
#include "RTGeometry.h"
#ifndef __RTCUBE_H__
#define __RTCUBE_H__

class RTCube : public RTGeometry
{
public:
    void init(void)
    {
        // vertex positions
        const GLfloat positions[24][3] = {
            // Front face
            {-0.5f, -0.5f, 0.5f},
            {-0.5f, 0.5f, 0.5f},
            {0.5f, 0.5f, 0.5f},
            {0.5f, -0.5f, 0.5f},
            // Back face
            {-0.5f, -0.5f, -0.5f},
            {-0.5f, 0.5f, -0.5f},
            {0.5f, 0.5f, -0.5f},
            {0.5f, -0.5f, -0.5f},
            // Left face
            {-0.5f, -0.5f, 0.5f},
            {-0.5f, 0.5f, 0.5f},
            {-0.5f, 0.5f, -0.5f},
            {-0.5f, -0.5f, -0.5f},
            // Right face
            {0.5f, -0.5f, 0.5f},
            {0.5f, 0.5f, 0.5f},
            {0.5f, 0.5f, -0.5f},
            {0.5f, -0.5f, -0.5f},
            // Top face
            {0.5f, 0.5f, 0.5f},
            {-0.5f, 0.5f, 0.5f},
            {-0.5f, 0.5f, -0.5f},
            {0.5f, 0.5f, -0.5f},
            // Bottom face
            {0.5f, -0.5f, 0.5f},
            {-0.5f, -0.5f, 0.5f},
            {-0.5f, -0.5f, -0.5f},
            {0.5f, -0.5f, -0.5f}};
        // vertex normals
        const GLfloat normals[24][3] = {
            // Front face
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            {0.0f, 0.0f, 1.0f},
            // Back face
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},
            {0.0f, 0.0f, -1.0f},
            // Left face
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            {-1.0f, 0.0f, 0.0f},
            // Right face
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            // Top face
            {0.0f, 1.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            // Bottom face
            {0.0f, -1.0f, 0.0f},
            {0.0f, -1.0f, 0.0f},
            {0.0f, -1.0f, 0.0f},
            {0.0f, -1.0f, 0.0f}};
        // Cube indices
        const GLuint indices[36] = {
            0, 1, 2, 0, 2, 3,       // Front face
            4, 5, 6, 4, 6, 7,       // Back face
            8, 9, 10, 8, 10, 11,    // Left face
            12, 13, 14, 12, 14, 15, // Right face
            16, 17, 18, 16, 18, 19, // Top face
            20, 21, 22, 20, 22, 23  // Bottom face
        };
        // glGenVertexArrays(1, &vao);
        // buffers.resize(3); // recall that buffers is std::vector<GLuint>
        // glGenBuffers(3, buffers.data());
        // glBindVertexArray(vao);

        // // 0th attribute: position
        // glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
        // glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
        // glEnableVertexAttribArray(0);
        // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

        // // 1st attribute: normal
        // glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
        // glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);
        // glEnableVertexAttribArray(1);
        // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

        // // indices
        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[2]);
        // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // count = sizeof(indices) / sizeof(indices[0]);
        // glBindVertexArray(0);

        // implement the RT cube positon for P and N;
        size_t indeicesSize = sizeof(indices) / sizeof(indices[0]);
        for (size_t i = 0; i < indeicesSize; i += 3)
        {
            Triangle triangle;
            triangle.P.push_back(glm::vec3(positions[indices[i]][0], positions[indices[i]][1], positions[indices[i]][2]));
            triangle.P.push_back(glm::vec3(positions[indices[i + 1]][0], positions[indices[i + 1]][1], positions[indices[i + 1]][2]));
            triangle.P.push_back(glm::vec3(positions[indices[i + 2]][0], positions[indices[i + 2]][1], positions[indices[i + 2]][2]));
            triangle.N.push_back(glm::vec3(normals[indices[i]][0], normals[indices[i]][1], normals[indices[i]][2]));
            triangle.N.push_back(glm::vec3(normals[indices[i + 1]][0], normals[indices[i + 1]][1], normals[indices[i + 1]][2]));
            triangle.N.push_back(glm::vec3(normals[indices[i + 2]][0], normals[indices[i + 2]][1], normals[indices[i + 2]][2]));
            elements.push_back(triangle);
        }
         count = sizeof(indices) / sizeof(indices[0]);
    }
    void init(const char *s){};
};

#endif