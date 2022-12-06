/**************************************************
Scene.cpp contains the implementation of the draw command
*****************************************************/
#include "RTScene.h"
#include "RTCube.h"
#include "RTObj.h"
#include "RTScene.inl"
// The scene init definition
//#include "Scene.inl"

using namespace glm;
using namespace std;

// void RTScene::init(void)
// {
//     // Create a geometry palette
//     geometry["cube"] = new RTCube;
//     geometry["teapot"] = new RTObj;
//     // geometry["bunny"] = new RTObj;
//     // geometry["sphere"] = new RTObj;
//     geometry["cube"]->init();
//     geometry["teapot"]->init("models/teapot.obj");
//     // geometry["bunny"]->init("models/bunny.obj");
//     // geometry["sphere"]->init("models/sphere.obj");

//     // Create a material palette
//     material["wood"] = new Material;
//     material["wood"]->ambient = vec4(0.1f, 0.1f, 0.1f, 1.0f);
//     material["wood"]->diffuse = vec4(0.3f, 0.15f, 0.1f, 1.0f);
//     material["wood"]->specular = vec4(0.3f, 0.15f, 0.1f, 1.0f);
//     material["wood"]->shininess = 100.0f;

//     material["ceramic"] = new Material;
//     material["ceramic"]->ambient = vec4(0.02f, 0.07f, 0.2f, 1.0f);
//     material["ceramic"]->diffuse = vec4(0.1f, 0.25f, 0.7f, 1.0f);
//     material["ceramic"]->specular = vec4(0.9f, 0.9f, 0.9f, 1.0f);
//     material["ceramic"]->shininess = 150.0f;

//     material["silver"] = new Material;
//     material["silver"]->ambient = vec4(0.1f, 0.1f, 0.1f, 1.0f);
//     material["silver"]->diffuse = vec4(0.2f, 0.2f, 0.2f, 1.0f);
//     material["silver"]->specular = vec4(0.9f, 0.9f, 0.9f, 1.0f);
//     material["silver"]->shininess = 50.0f;

//     material["turquoise"] = new Material;
//     material["turquoise"]->ambient = vec4(0.1f, 0.2f, 0.17f, 1.0f);
//     material["turquoise"]->diffuse = vec4(0.2f, 0.375f, 0.35f, 1.0f);
//     material["turquoise"]->specular = vec4(0.3f, 0.3f, 0.3f, 1.0f);
//     material["turquoise"]->shininess = 100.0f;

//     material["bulb"] = new Material;
//     material["bulb"]->ambient = vec4(1.0f, 0.5f, 0.5f, 1.0f);
//     material["bulb"]->diffuse = vec4(1.0f, 0.5f, 0.31f, 1.0f);
//     material["bulb"]->specular = vec4(0.5f, 0.5f, 0.5f, 1.0f);
//     material["bulb"]->emision = vec4(1.0f, 0.2f, 0.1f, 1.0f);
//     material["bulb"]->shininess = 32.0f;

//     material["floor"] = new Material;
//     material["floor"]->ambient = vec4(0.0f, 0.0f, 0.0f, 1.0f);
//     material["floor"]->diffuse = vec4(0.01f, 0.01f, 0.01f, 1.0f);
//     material["floor"]->specular = vec4(0.5f, 0.5f, 0.5f, 1.0f);
//     material["floor"]->shininess = 32.0f;

//     material["white"] = new Material;
//     material["white"]->ambient = vec4(0.0f, 0.0f, 0.0f, 0.0f);
//     material["white"]->diffuse = vec4(0.55f, 0.55f, 0.55f, 0.0f);
//     material["white"]->specular = vec4(0.7f, 0.37f, 0.7f, 0.0f);
//     material["white"]->shininess = 25.0f;
//     // Create a model palette
//     model["teapot1"] = new RTModel;
//     model["teapot1"]->geometry = geometry["teapot"];
//     model["teapot1"]->material = material["silver"];
//     model["teapot2"] = new RTModel;
//     model["teapot2"]->geometry = geometry["teapot"];
//     model["teapot2"]->material = material["ceramic"];
//     model["table piece"] = new RTModel;
//     model["table piece"]->geometry = geometry["cube"];
//     model["table piece"]->material = material["wood"];
//     // model["bunny"] = new RTModel;
//     // model["bunny"]->geometry = geometry["bunny"];
//     // model["bunny"]->material = material["turquoise"];
//     model["bulb"] = new RTModel;
//     model["bulb"]->geometry = geometry["sphere"];
//     model["bulb"]->material = material["bulb"];
//     // create a new model palette
//     // model["bunny1"] = new RTModel;
//     // model["bunny1"]->geometry = geometry["bunny"];
//     // model["bunny1"]->material = material["white"];
//     model["floor"] = new RTModel;
//     model["floor"]->geometry = geometry["cube"];
//     model["floor"]->material = material["floor"];
//     // Create a light palette
//     light["sun"] = new Light;
//     light["sun"]->position = vec4(3.0f, 2.0f, 4.0f, 0.0f);
//     light["sun"]->color = 1.0f * vec4(1.0f, 1.0f, 1.0f, 1.0f);

//     light["bulb"] = new Light;
//     light["bulb"]->position = vec4(0.0f, 2.0f, 0.0f, 0.0f);
//     light["bulb"]->color = 1.5f * vec4(1.0f, 0.2f, 0.1f, 1.0f);

//     // Build the scene graph
//     node["table"] = new RTNode;
//     node["table top"] = new RTNode;
//     node["table leg"] = new RTNode;
//     // node["teapot1"] = new RTNode;
//     // node["teapot2"] = new RTNode;
//     // node["bunny"] = new RTNode;
    
//     // new scene graph
//     // node["bunny1"] = new RTNode;
//     node["floor"] = new RTNode;
//     // node["table"]->childnodes.push_back(node["table top"]);
//     // node["table"]->childtransforms.push_back(translate(vec3(0.0f, 1.2f, 0.0f)));
//     // node["table"]->childnodes.push_back(node["table leg"]);
//     // node["table"]->childtransforms.push_back(translate(vec3(-0.9f, 0.0f, -0.4f)));
//     // node["table"]->childnodes.push_back(node["table leg"]);
//     // node["table"]->childtransforms.push_back(translate(vec3(-0.9f, 0.0f, 0.4f)));
//     // node["table"]->childnodes.push_back(node["table leg"]);
//     // node["table"]->childtransforms.push_back(translate(vec3(0.9f, 0.0f, 0.4f)));
//     // node["table"]->childnodes.push_back(node["table leg"]);
//     // node["table"]->childtransforms.push_back(translate(vec3(0.9f, 0.0f, -0.4f)));

//     // node["table leg"]->models.push_back(model["table piece"]);
//     // node["table leg"]->modeltransforms.push_back(translate(vec3(0.0f, 0.5f, 0.0f)) * scale(vec3(0.2f, 1.0f, 0.2f)));

//     // node["table top"]->models.push_back(model["table piece"]);
//     // node["table top"]->modeltransforms.push_back(translate(vec3(0.0f, -0.1f, 0.0f)) * scale(vec3(2.0f, 0.2f, 1.0f)));
//     // node["table top"]->childnodes.push_back(node["teapot1"]);
//     // node["table top"]->childtransforms.push_back(translate(vec3(-0.5f, 0.0f, 0.0f)));
//     // node["table top"]->childnodes.push_back(node["teapot2"]);
//     // node["table top"]->childtransforms.push_back(translate(vec3(0.5f, 0.0f, 0.0f)) * rotate(-120.0f * float(M_PI) / 180.0f, vec3(0.0f, 1.0f, 0.0f)));

//     // node["teapot1"]->models.push_back(model["teapot1"]);
//     // node["teapot1"]->modeltransforms.push_back(scale(vec3(0.5f)));
//     // node["teapot2"]->models.push_back(model["teapot2"]);
//     // node["teapot2"]->modeltransforms.push_back(scale(vec3(1.0f, 1.5f, 1.0f)) * scale(vec3(0.5f)));

//     // node["bunny"]->models.push_back(model["bunny"]);
//     // node["bunny"]->modeltransforms.push_back(scale(vec3(0.8f)) * translate(vec3(0.0f, 1.0f, 2.2f)));

//     // node["bunny1"]->models.push_back(model["bunny1"]);
//     // node["bunny1"]->modeltransforms.push_back(scale(vec3(0.8f)) * translate(vec3(0.0f, 1.0f, 0.0f)));
//     node["floor"]->models.push_back(model["floor"]);
//     node["floor"]->modeltransforms.push_back(scale(vec3(5.0f, 0.05f, 5.0f)));

//     // node["world"]->childnodes.push_back(node["table"]);
//     // node["world"]->childtransforms.push_back(mat4(1.0f));
//     // node["world"]->childnodes.push_back(node["bunny"]);
//     // node["world"]->childtransforms.push_back(translate(vec3(-1.8f, 0.0f, 0.0f)) * rotate(90.0f * float(M_PI) / 180.0f, vec3(0.0f, 1.0f, 0.0f)));
//     node["world"]->models.push_back(model["bulb"]);
//     node["world"]->modeltransforms.push_back(translate(vec3(2.0f, 2.0f, 0.0f)) * scale(vec3(0.6f)));
//     // node["world"]->childnodes.push_back(node["bunny1"]);
//     // node["world"]->childtransforms.push_back(translate(vec3(-1.8f, 0.0f, 0.0f)) * rotate(90.0f * float(M_PI) / 180.0f, vec3(0.0f, 1.0f, 0.0f)));
//     node["world"]->childnodes.push_back(node["floor"]);
//     node["world"]->childtransforms.push_back(translate(vec3(0.0f, -0.02f, 0.0f)));

//     // Put a camera
//     camera = new Camera;
//     camera->target_default = vec3(0.0f, 1.0f, 0.0f);
//     camera->eye_default = vec3(0.0f, 1.0f, 5.0f);
//     camera->up_default = vec3(0.0f, 1.0f, 0.0f);
//     camera->reset();

//     // Initialize shader
//     shader = new SurfaceShader;
//     shader->read_source("shaders/projective.vert", "shaders/lighting.frag");
//     shader->compile();
//     glUseProgram(shader->program);
//     shader->initUniforms();
// }


void RTScene::buildTriangleSoup(void){
    // Pre-draw sequence: assign uniforms that are the same for all Geometry::draw call.  These uniforms include the camera view, proj, and the lights.  These uniform do not include modelview and material parameters.
    camera->computeMatrices();
    // shader->view = camera->view;
    // shader->projection = camera->proj;
    // shader->nlights = light.size();
    // shader->lightpositions.resize(shader->nlights);
    // shader->lightcolors.resize(shader->nlights);
    // int count = 0;
    // for (std::pair<std::string, Light *> entry : light)
    // {
    //     shader->lightpositions[count] = (entry.second)->position;
    //     shader->lightcolors[count] = (entry.second)->color;
    //     count++;
    // }

    // Define stacks for depth-first search (DFS)
    std::stack<RTNode *> dfs_stack;
    std::stack<mat4> matrix_stack; // HW3: You will update this matrix_stack during the depth-first search while loop.

    // Initialize the current state variable for DFS
    RTNode *cur = node["world"];  // root of the tree
    mat4 cur_VM = camera->view; // HW3: You will update this current modelview during the depth first search.  Initially, we are at the "world" node, whose modelview matrix is just camera's view matrix.

    //  HW3: The following is the beginning of the depth-first search algorithm.
    //  HW3: The depth-first search for the node traversal has already been implemented (cur, dfs_stack).
    //  HW3: All you have to do is to also update the states of (cur_VM, matrix_stack) alongside the traversal.  You will only need to modify starting from this line.
    dfs_stack.push(cur);
    /**
     * TODO: (HW3 hint: you should do something here)
     */
    matrix_stack.push(cur_VM);
    // Compute total number of connectivities in the graph; this would be an upper bound for
    // the stack size in the depth first search over the directed acyclic graph
    int total_number_of_edges = 0;
    for (const auto &n : node) total_number_of_edges += n.second->childnodes.size();

    // If you want to print some statistics of your scene graph
    // std::cout << "total numb of nodes = " << node.size() << std::endl;
    // std::cout << "total number of edges = " << total_number_of_edges << std::endl;

    while (!dfs_stack.empty())
    {
        // Detect whether the search runs into infinite loop by checking whether the stack is longer than the number of edges in the graph.
        if (dfs_stack.size() > total_number_of_edges)
        {
            std::cerr << "Error: The scene graph has a closed loop." << std::endl;
            exit(-1);
        }

        // top-pop the stacks
        cur = dfs_stack.top();
        dfs_stack.pop();
        /**
         * TODO: (HW3 hint: you should do something here)
         */
        cur_VM = matrix_stack.top();
        matrix_stack.pop();
        // draw all the models at the current node
        for (size_t i = 0; i < cur->models.size(); i++)
        {
            // Prepare to draw the geometry. Assign the modelview and the material.

            /**
             * TODO: (HW3 hint: you should do something here)
             */

            // shader->modelview = cur_VM * cur->modeltransforms[i]; // TODO: HW3: Without updating cur_VM, modelview would just be camera's view matrix.
            // shader->material = (cur->models[i])->material;
            // glm::mat4 curRTModelView = cur_VM * cur->modeltransforms[i]; // TODO: HW3: Without updating cur_VM, modelview would just be camera's view matrix.
            // Material * cuRTMaterial= cur->models[i]->material;
            // glm::mat3 TransRTModelViewer = glm::inverse(glm::transpose(mat3(curRTModelView)));
            glm::mat4 curModelView = cur_VM * cur->modeltransforms[i];
            glm::mat3 invTransMV = glm::inverse(glm::transpose(mat3(curModelView)));
            Material *curMaterial = cur->models[i]->material;
            // The draw command
            // shader->setUniforms();
            // (cur->models[i])->geometry->draw();
        

            // for (Triangle Tri : cur->models[i]->geometry->elements)
            // {
            //     Triangle transformedTri;
                
            //     glm::vec4 currProd = curRTModelView * glm::vec4(Tri.P[0], 1);
            //     transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
            //     currProd = curRTModelView * glm::vec4(Tri.P[1], 1);
            //     transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
            //     currProd = curRTModelView * glm::vec4(Tri.P[2], 1);
            //     transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
            //     transformedTri.N.push_back(TransRTModelViewer * Tri.N[0]);
            //     transformedTri.N.push_back(TransRTModelViewer * Tri.N[1]);
            //     transformedTri.N.push_back(TransRTModelViewer * Tri.N[2]);

            //     transformedTri.material = cuRTMaterial;
            //     triangle_soup.push_back(transformedTri);
            // }
             std::vector<Triangle> triangleElement = cur->models[i]->geometry->elements;
            // cout << "triangleElement size is " << triangleElement.size() << endl;
            for (int i = 0; i < triangleElement.size(); i++)
            {
                //cout << "test triangle" << endl;
                Triangle transformedTri;

                glm::vec4 currProd = curModelView * glm::vec4(triangleElement[i].P[0], 1);
                transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
                currProd = curModelView * glm::vec4(triangleElement[i].P[1], 1);
                transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
                currProd = curModelView * glm::vec4(triangleElement[i].P[2], 1);
                transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
                transformedTri.N.push_back(invTransMV * triangleElement[i].N[0]);
                transformedTri.N.push_back(invTransMV * triangleElement[i].N[1]);
                transformedTri.N.push_back(invTransMV * triangleElement[i].N[2]);

                transformedTri.material = curMaterial;
                triangle_soup.push_back(transformedTri);
            }
            // int count = 0;
            // for (Triangle origTri : cur->models[i]->geometry->elements)
            // {
            //     Triangle transformedTri;
            //     std::cout << "triangle is " << count << std::endl;
            //     glm::vec4 currProd = curModelView * glm::vec4(origTri.P[0], 1);
            //     transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
            //     currProd = curModelView * glm::vec4(origTri.P[1], 1);
            //     transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
            //     currProd = curModelView * glm::vec4(origTri.P[2], 1);
            //     transformedTri.P.push_back(glm::vec3(currProd.x, currProd.y, currProd.z));
            //     transformedTri.N.push_back(invTransMV * origTri.N[0]);
            //     transformedTri.N.push_back(invTransMV * origTri.N[1]);
            //     transformedTri.N.push_back(invTransMV * origTri.N[2]);

            //     transformedTri.material = curMaterial;
            //     triangle_soup.push_back(transformedTri);
            //     count++;
            // }
        }

        // Continue the DFS: put all the child nodes of the current node in the stack
        for (size_t i = 0; i < cur->childnodes.size(); i++)
        {
            dfs_stack.push(cur->childnodes[i]);
            /**
             * TODO: (HW3 hint: you should do something here)
             */
            matrix_stack.push(cur_VM * cur->childtransforms[i]);
        }
    }
}
